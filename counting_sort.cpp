
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */


#include <iostream>

using namespace std;

void counting_sort (int a[],int count ){
	int c[100];
	int b[99];
	for ( int i = 0;i < 100;i++){
	     c[ i ]= 0;
	}	     

	for ( int j =0;j<count;j++){
		c[a[j]]=c[a[j]]+1;
	}

	for ( int j=1;j<=count;j++){
		c[j]=c[j-1]+c[j];
	}

	for ( int j= count -1 ;j>=0;j--){
		b[c[a[j]]]=a[j];
		c[a[j]] = c[a[j]]-1;

	}

	for ( int i=1;i<=count;i++){
		cout << b[i] << "  ";
	}
}


int main ( ) {
	
	int a[]={ 2,5,3,0,2,3,0,3};
	counting_sort ( a ,8);

	return 0;
}







