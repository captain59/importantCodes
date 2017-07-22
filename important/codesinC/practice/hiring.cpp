#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int partition(int a[],int b[], int top, int bottom)
{
     int x = a[top];
     int i = top - 1;
     int j = bottom + 1;
     int temp;
     do
     {
           do      
           {
                  j - -;
           }while (x >a[j]);

          do  
         {
                 i++;
          } while (x <a[i]);

          if (i < j)
         { 
                 temp = a[i];    
                 a[i] = a[j];
                 a[j] = temp;
                 temp=b[i];
                 b[i]=b[j];
                 b[j]=temp;
         }
     }while (i < j);     
     return j;           // returns middle subscript  
}
void QuickSort(int a[],int b[], int top, int bottom)
{
      // top = subscript of beginning of array
      // bottom = subscript of end of array
      
     int middle;
     if (top < bottom)
    {
          middle = partition(a,b, top, bottom);
          quicksort(a,b, top, middle);   // sort first section
          quicksort(a,b, middle+1, bottom);    // sort second section
     }
     return;
}
int main()
{
	
	return 0;
}