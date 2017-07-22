// Shape_Detect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define WINPAUSE system("pause")

using namespace std;
using namespace cv;

pair<Point, double> town_center;
vector<pair<Point, double> > food, wood, water;
const int TMAX = 350;
Mat src2, imgHsv, resource, town, river;
//initialize value
int h11 = 0;
int s11 = 90;
int v11 = 125;
int h12 = 40;
int s12 = 160;
int v12 = 240;

int h21 = 0;
int s21 = 49;
int v21 = 125;
int h22 = 15;
int s22 = 110;
int v22 = 160;

int h31 = 90;
int s31 = 25;
int v31 = 122;
int h32 = 120;
int s32 = 50;
int v32 = 270;
//initialize trackbars
Point finalLoc(400, 200);
// Setting Label On the Contours
void setLabel(Mat& im, string label, vector<Point> contour_temp)
{
	int fontface = FONT_HERSHEY_SIMPLEX;
	double scale = 1.5;
	int thickness = 2;
	int baseline = 0;
	Size text = getTextSize(label, fontface, scale, thickness, &baseline);
	Rect r = boundingRect(contour_temp);
	Point pt(r.x + (r.width - text.width) / 2, r.y + (r.height + text.height) / 2);
	//rectangle(im, pt + Point(0, baseline), pt + Point(text.width - text.height), CV_RGB(255, 255, 255), CV_FILLED);
	putText(im, label, pt, fontface, scale, CV_RGB(255, 255, 255), thickness, 8);
}

void init_trackbars()
{
	createTrackbar("H1", "Resource", &h11, TMAX);
	createTrackbar("S1", "Resource", &s11, TMAX);
	createTrackbar("V1", "Resource", &v11, TMAX);
	createTrackbar("H2", "Resource", &h12, TMAX);
	createTrackbar("S2", "Resource", &s12, TMAX);
	createTrackbar("V2", "Resource", &v12, TMAX);

	createTrackbar("H1", "Town", &h21, TMAX);
	createTrackbar("S1", "Town", &s21, TMAX);
	createTrackbar("V1", "Town", &v21, TMAX);
	createTrackbar("H2", "Town", &h22, TMAX);
	createTrackbar("S2", "Town", &s22, TMAX);
	createTrackbar("V2", "Town", &v22, TMAX);

	createTrackbar("H1", "River", &h31, TMAX);
	createTrackbar("S1", "River", &s31, TMAX);
	createTrackbar("V1", "River", &v31, TMAX);
	createTrackbar("H2", "River", &h32, TMAX);
	createTrackbar("S2", "River", &s32, TMAX);
	createTrackbar("V2", "River", &v32, TMAX);
}
Mat noise_remove(Mat img)
{
	//dilate(img, img, Mat(),Point(-1,-1), 2);
	medianBlur(img, img, 5);
	morphologyEx(img, img, MORPH_OPEN, 1);
	dilate(img, img, 1);
	return img;
}
void find_townhall(Mat img, Mat& drawing)
{
	vector<vector<Point> > contours;
	vector<Vec4i> heirarchy;
	Rect bounding_rect;
	double largest_area = 200;
	findContours(img.clone(), contours, heirarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area>largest_area)
		{
			largest_area = area;
			bounding_rect = boundingRect(contours[i]);
		}
	}
	Point p1 = bounding_rect.tl();
	Point p2 = bounding_rect.br();
	Point p((p1.x + p2.x) >> 1, (p1.y + p2.y) >> 1);
	circle(drawing, p, 5, Scalar(0, 0, 0), CV_FILLED, 8, 0);
	town_center.first = p;
	town_center.second = sqrtf(powf(abs(p1.x - p.x), 2) + powf(abs(p1.y - p.y), 2));
}
void find_resources(Mat img, Mat& drawing)
{
	vector<vector<Point> > contours;
	vector<Vec4i> heirarchy;
	vector<Point> approx;// vector to store the result of approxPolyDp
	Rect bounding_rect;
	double largest_area = 200;
	findContours(img.clone(), contours, heirarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area<largest_area)
			continue;
		approxPolyDP(Mat(contours[i]), approx, (arcLength(contours[i], true))*0.05, true);
		if (!isContourConvex(approx))
			continue;
		int vtc = approx.size();
		cout << "Area " << area << " Vtc " << vtc << endl;
		bounding_rect = boundingRect(contours[i]);
		Point p1 = bounding_rect.tl();
		Point p2 = bounding_rect.br();
		Point p((p1.x + p2.x) >> 1, (p1.y + p2.y) >> 1);
		double radius = sqrtf(powf(abs(p1.x - p.x), 2) + powf(abs(p1.y - p.y), 2));
		if (vtc == 3 || area<350)
		{
			food.push_back(make_pair(p, radius));
			circle(drawing, p, 4, Scalar(0, 255, 0), CV_FILLED, 8, 0);
		}
		else
		{
			wood.push_back(make_pair(p, radius));
			circle(drawing, p, 4, Scalar(0, 0, 255), CV_FILLED, 8, 0);
		}
	}
}
void find_water(Mat img, Mat& drawing)
{
	vector<vector<Point> > contours;
	vector<Vec4i> heirarchy;
	vector<Point> approx;// vector to store the result of approxPolyDp
	Rect bounding_rect;
	double largest_area = 200;
	findContours(img.clone(), contours, heirarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		if (area < largest_area)
			continue;
		bounding_rect = boundingRect(contours[i]);
		Point p1 = bounding_rect.tl();
		Point p2 = bounding_rect.br();
		Point p((p1.x + p2.x) >> 1, (p1.y + p2.y) >> 1);
		double radius = sqrtf(powf(abs(p1.x - p.x), 2) + powf(abs(p1.y - p.y), 2));
		water.push_back(make_pair(p, radius));
		circle(drawing, p, 4, Scalar(255, 0, 0), CV_FILLED, 8, 0);
	}
}
void show_bot(Point p, Mat& drawing)
{
	circle(drawing, p, 4, Scalar(255,255,255), CV_FILLED, 8, 0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	//_sleep(250000);
	string filename = "E:\\computer vision\\data\\sample.webm";//wmv
	VideoCapture cap(filename);
	if (!cap.isOpened())
	{
		cout << "Error in reading Video Stream" << endl;;
		WINPAUSE;
		return -1;
	}
	namedWindow("Display", CV_WINDOW_NORMAL);
	namedWindow("Resource", CV_WINDOW_NORMAL);
	namedWindow("Town", CV_WINDOW_NORMAL);
	namedWindow("River", CV_WINDOW_NORMAL);
	Point start_point(5, 5);
	//init_trackbars();
	while (true)
	{
		cap >> src2;
		if (src2.empty())
			break;
		Mat drawing(src2.size(), CV_8UC3, Scalar(0, 0, 0));
		circle(drawing, finalLoc, 5, CV_RGB(255, 0, 0), CV_FILLED, 8, 0);
		cvtColor(src2, imgHsv, CV_BGR2HSV);
		inRange(imgHsv, Scalar(h11, s11, v11), Scalar(h12, s12, v12), resource);
		inRange(imgHsv, Scalar(h21, s21, v21), Scalar(h22, s22, v22), town);
		inRange(imgHsv, Scalar(h31, s31, v31), Scalar(h32, s32, v32), river);
		//removing noise
		resource = noise_remove(resource);
		town = noise_remove(town);
		river = noise_remove(river);
		// blobs obtained
		show_bot(start_point, src2);
		find_townhall(town, src2);
		find_resources(resource, src2);
		find_water(river, src2);
		cout << "Center " << town_center.first.x << " " << town_center.first.y << endl;
		imshow("Resource", resource);
		imshow("Town", town);
		imshow("River", river);
		imshow("Display", src2);
		if (waitKey(60) == 32)
			break;
	}
	destroyAllWindows();
	return 0;
}