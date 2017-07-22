#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstlib>
#include <algorithm>
using namespace std;
string addition(string str1,string str2)
{
    string rev_str1, rev_str2;
    int int1 = 0, int2 = 0;
    string final; //Final product string, sum of two original strings
    int temp_int = 0, buffer_int, remainder = 0;
    string temp_str = "", buffer_str;
    char buffer[100] = {0};
    rev_str1 = string(str1.rbegin(), str1.rend());
    rev_str2 = string(str2.rbegin(), str2.rend());

    for (int i = 0; i < 10; i++)
    {
        buffer_str = rev_str1.at(i);
        int1 = atoi(buffer_str.c_str());
        buffer_str = rev_str2.at(i);
        int2 = atoi(buffer_str.c_str());
        buffer_int += (int1 + int2 + remainder);
        remainder = 0;

        while (buffer_int > 9)
        {
            buffer_int -= 10;
            remainder += 10;
        }

        temp_str = itoa(buffer_int, buffer, 10);
        final += temp_str;
    }

    final = string(final.rbegin(), final.rend());

    return final;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	return 0;
}