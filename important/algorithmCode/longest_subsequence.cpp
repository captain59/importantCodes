#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
// A[] is ceilIndex in the caller
int CeilIndex(long long int A[], int l, int r, long long int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}

int LongestIncreasingSubsequenceLength(long long int A[], int size) {
    // Add boundary case, when array size is one

    int *tailTable   = new int[size];
    int len; // always points empty slot

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }

    delete[] tailTable;

    return len;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long int arr[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);
	printf("%lld\n",n-LongestIncreasingSubsequenceLength(arr, n));
	return 0;
}