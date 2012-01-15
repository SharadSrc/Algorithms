/*
 *Name :Sharad Dixit
 *Code : Quick sort
*/

#include <iostream>

using namespace std;

void show ( int a[] , int num );                                           
void quick_sort ( int a[] , int left ,int right) 
{
	int pivot;
	int start;
	int end;
	int mid = ( left+ right )/2;
	pivot = a[mid];
	start = left;
	end   = right;

	while ( start < end ) {
	

		while ( a [ start ] < pivot ) {
			start++;
		} 
		while ( a [ end ] > pivot ) {
			end --;
		}
		if ( start <= end ) {
		swap( a [start],a[end]);
		end--;
		start++;
		}
	}

	if ( left < end ){
		quick_sort(a,left,end);
	}
	if ( start < right){
		quick_sort( a, start,right);
	}
}

void show ( int a[] , int num ){
	for ( int i = 0; i < num ; i++ ){
		cout << a [i] <<  " ";
	}
	cout << endl;
}



void swap( int *a , int *b ) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main () 
{
	int a [100];
	int num;

	cin >> num;

	for ( int i = 0; i < num ; i++){
		cin >> a[i];
	}
	show ( a , num );
	quick_sort( a , 0 , num-1 );
	show ( a , num );
}

