
// plot.cpp : Defines the entry point for the console application.
//

#include <limits>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

struct Pnt
{
	int x;
	int y;
};

Mat computeFullEnergy(Mat img)
{
	Mat energy(img.rows, img.cols, CV_8UC1, Scalar(255));// declaring white image
	//implementing the sobel operator
	int i, j, gx, gy;
	for (i = 1; i < img.rows - 1; i++)
	{
		for (j = 1; j < img.cols - 1; j++)
		{
			gx = gy = 0;
			gx = abs((img.at<Vec3b>(i - 1, j + 1)[0] - img.at<Vec3b>(i - 1, j - 1)[0]) + 2 * (img.at<Vec3b>(i, j + 1)[0] - img.at<Vec3b>(i, j - 1)[0]) + (img.at<Vec3b>(i + 1, j + 1)[0] - img.at<Vec3b>(i + 1, j - 1)[0]));
			gy = abs((img.at<Vec3b>(i + 1, j - 1)[0] - img.at<Vec3b>(i - 1, j - 1)[0]) + 2 * (img.at<Vec3b>(i + 1, j)[0] - img.at<Vec3b>(i - 1, j)[0]) + (img.at<Vec3b>(i + 1, j + 1)[0] - img.at<Vec3b>(i - 1, j + 1)[0]));
			energy.at<uchar>(i, j) = abs(gx + gy);
		}
	}
	return energy;
}

int distTo[2000][2000];
int dist2To[2000][2000];
int edgeTo[2000][2000];
int edge2To[2000][2000];
int seam2d[2000][1000];

vector<uint> findVerticalSeam(Mat img, Mat energy, Pnt n)
{
	vector<uint> seam(img.rows);
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			distTo[i][j] = (i == 0) ? 0 : numeric_limits<int>::max();
			edgeTo[i][j] = 0;
			dist2To[i][j] = (i == (img.rows - 1)) ? 0 : numeric_limits<int>::max();
			edge2To[i][j] = 0;
		}
	}
	
	// rows
	for (int r = 0; r < img.rows; r++)
	{
		for (int c = 0; c < img.cols; c++)
		{
			if(r <= img.rows - 2)
			{
				//checking pixels in left
				if (c != 0)
				{
					if (distTo[r + 1][c - 1]>(distTo[r][c] + (int)energy.at<uchar>(r + 1, c - 1)))
					{
						distTo[r + 1][c - 1] = distTo[r][c] + (int)energy.at<uchar>(r + 1, c - 1);
						edgeTo[r + 1][c - 1] = 1;
					}
				}
				// change pixel right below
				if (distTo[r + 1][c] > (distTo[r][c] + (int)energy.at<uchar>(r + 1, c)))
				{
					distTo[r + 1][c] = distTo[r][c] + (int)energy.at<uchar>(r + 1, c);
					edgeTo[r + 1][c] = 0;
				}
				// check pixel in bottom right
				if (c != (img.cols - 1))
				{
					if (distTo[r + 1][c + 1] > (distTo[r][c] + energy.at<uchar>(r + 1, c + 1)))
					{
						distTo[r + 1][c + 1] = distTo[r][c] + (int)energy.at<uchar>(r + 1, c + 1);
						edgeTo[r + 1][c + 1] = -1;
					}
				}
			}
			/*********************************************************/
			if(r >= 1)
			{
				//checking pixels in left
				if (c != 0)
				{
					if (dist2To[r - 1][c - 1] > (int)energy.at<uchar>(r, c))
					{
						dist2To[r - 1][c - 1] = (int)energy.at<uchar>(r, c);
						edge2To[r - 1][c - 1] = 1;
					}
				}
				// change pixel right below
				if (dist2To[r - 1][c] > (int)energy.at<uchar>(r, c))
				{
					dist2To[r - 1][c] = (int)energy.at<uchar>(r, c);
					edge2To[r - 1][c] = 0;
				}
				// check pixel in bottom right
				if (c != (img.cols - 1))
				{
					if (dist2To[r - 1][c + 1] > (int)energy.at<uchar>(r, c))
					{
						dist2To[r - 1][c + 1] = (int)energy.at<uchar>(r + 1, c + 1);
						edge2To[r - 1][c + 1] = -1;
					}
				}
			}
		}
	}

	
	//retracing the path and updating the seam vector
	//Retrace the min-path and update the 'seam' vector
	seam[n.x] = n.y;
	for (int i = n.x; i > 0; --i)
		seam[i - 1] = seam[i] + edgeTo[i][seam[i]];
	for (int i = n.x; i < (img.rows - 1); ++i)
		seam[i + 1] = seam[i] + edge2To[i][seam[i]];

	return seam;
}

Mat removeVerticalSeam(Mat img, vector<uint> seam, Mat &mod)
{
	for (int r = 0; r < img.rows; r++)
	{
		for (int c = seam[r]; c < img.cols - 1; c++)
		{
			img.at<Vec3b>(r, c) = img.at<Vec3b>(r, c + 1);
			mod.at<uchar>(r, c) = mod.at<uchar>(r, c + 1);
		}
	}
	//resize the image
	img = img(Rect(0, 0, img.cols - 1, img.rows));
	mod = mod(Rect(0, 0, img.cols - 1, img.rows));
	return img;
}


Mat addVerticalSeam(Mat img, vector<uint> seam)
{
	Mat ret(img.rows, img.cols+1, CV_8UC3);
	cout << ret.rows << " Function  " << ret.cols << endl;
	for (int r = 0; r < img.rows; r++)
	{
		for (int c = 0; c < seam[r]; c++)
			ret.at<Vec3b>(r, c) = img.at<Vec3b>(r, c);
		ret.at<Vec3b>(r, seam[r]) = img.at<Vec3b>(r, seam[r]);
		for (int c = seam[r]; c < img.cols; c++)
		{
			ret.at<Vec3b>(r, c+1) = img.at<Vec3b>(r, c);
		}
	}
	return ret;
}

Mat markImage(Mat src)
{
	Mat img(src.rows,src.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<src.rows;i++)
	{
		for(int j=0;j<src.cols;j++)
		{
				
			if(src.at<Vec3b>(i,j)[0]<=123 && src.at<Vec3b>(i,j)[0]>=119 && src.at<Vec3b>(i,j)[1]>=230 && src.at<Vec3b>(i,j)[1]<=255)
			{
				img.at<uchar>(i,j)=255;
			}
		}
		//cout<<endl;
	}
	return img;
}

int computePixel(Pnt &n, Mat mod)
{
	int flag=0;
		
	if(n.y == mod.cols)
	{
		n.y=0;
		n.x=n.x + 1;
	}
	
	if(n.x == mod.rows)
		return flag;
		
	int j=n.y;
	
	for(int i=n.x;i<mod.rows;i++)
	{
		for(;j<mod.cols;j++)
		{
			if(mod.at<uchar>(i,j) == 255)
			{
				n.x=i;
				n.y=j;
				flag=1;
				return flag;
			}
		}
		j=0;
	}
	return flag;
}

int main()
{
	Mat src = imread("../lake_test.jpg", CV_LOAD_IMAGE_COLOR);
	Mat mod = imread("../newlake_test.jpg", CV_LOAD_IMAGE_COLOR);
	cvtColor(mod,mod,CV_RGB2HSV);
	if (!src.data)
	{
		cout << "Invalid Input\n";
		return 0;
	}
	if (!mod.data)
	{
		cout << "Invalid Input\n";
		return 0;
	}
	
	//rgb 2 lab
	Mat lab;
	cvtColor(src, lab, CV_RGB2Lab);
	
	//mark object in mod
	mod = markImage(mod);
	
	
	int cx = 0, cy = 50;
	int cnt=1;
	Pnt n;
	n.x=0;
	n.y=0;
	vector<uint> seam; 
	Mat energy;
	
	while (computePixel(n, mod))
	{
		cout<<cnt<<"-> "<<n.x<<", "<<n.y<<endl;
		cout<<"size "<<mod.rows<<" "<<mod.cols<<endl;
		energy = computeFullEnergy(lab);
		seam = findVerticalSeam(lab, energy, n);
		lab = removeVerticalSeam(lab, seam, mod);
		cnt++;
	}
	
	cvtColor(lab, lab, CV_Lab2RGB);
	namedWindow("Original", CV_WINDOW_NORMAL);
	namedWindow("Changed", CV_WINDOW_NORMAL);
	imshow("Original", src);
	imshow("Changed", lab);
	cout << src.rows << " " << src.cols << endl;
	cout << lab.rows << " " << lab.cols << endl;
	waitKey(0);
	destroyAllWindows();
	return 0;
}
