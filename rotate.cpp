#include <iostream>
using namespace std;
void rotateArray( int a[] , int start , int end ) {
	
	while ( start < end ) {
		 int temp =  a[start];
		 a[start] =  a[end];
		 a[end] = temp;
		
		start++;
		end--;
	}
}

void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
    cout << arr[i] << " "; 
} 

int main()
{
	
	int a[] = { 1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(int);
	int d = 2;
	rotateArray(a,0,d-1);
	rotateArray(a,d,n-1);
	rotateArray(a,0,n-1);
	printArray(a,n);
}
