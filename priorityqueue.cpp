
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int length;

void heapify ( int arr[], int bound )
{
	int root;
	int lchild;
	int mchild;
	int rchild;
	int i;
	int temp;

	for ( i = bound/2;i >=1;i--){
		//		root=a[i];
		lchild=2*i;
		rchild=2*i+1;
		if ( lchild  <= bound && rchild<=bound) {

			if(arr[rchild] >= arr[lchild])
				mchild = rchild;
			else
				mchild = lchild;
		}


		else{
			mchild= lchild;
		}

		//printf("value of arr[mchild] %d",arr[mchild]);

		//printf("value of arr[i] %d",arr[i]);

		if (arr[i] < arr[mchild])
		{
			temp = arr[i];
			arr[i] = arr[mchild];
			arr[mchild] = temp;
		}

	}

	/*	temp = arr[1];
		arr[1] = arr[bound];
		arr[bound] = temp;*/
	return;
}

void increase_key( int a[], int i, int key,int length ){
	int j;
	if ( i < 0) {
		cout << "INDEX CAN'T BE LESS THAN ZERO" << endl;
	}

	a[i] = key;
	for ( j = 0; j < length; j++) {
		heapify( a, length);
	}

}
void insert ( int a[], int num, int length ) 
{
	length = length+1;
	increase_key( a,length, num,length);
}

void max( int a[] ) 
{

	cout << " MAX PRIORITY " << a[1] << endl;
}

void maxextract ( int a[] ) 
{
	int temp = a[1];
	a[1] = a[length];
	a[length] = temp;

	length =  length - 1;


	for ( int j = 0; j < length; j++) {
		heapify( a, length);
	}
}

void display ( int a[] )
{
	cout << "length" << length << endl; 
	for ( int j = 1; j <=length; j++) {
		cout << a[j] << "	";
	}
}



int main()
{
	int a [100];
	int i=1,j;
	int u;
	int v;
	int menu =1;
	length =10;

	while ( i <= 10){ 
		a[i]= rand()%100;
		i++;
	}
	
	for ( j = 0; j < length; j++) {
		heapify( a, length);
	}
	
	cout << "INITIAL HEAP " << endl;
	for ( j = 1; j <=length; j++) {
		cout << a[j] << "	";
	}
	cout << endl;
	cout << "1 -INSERT " << endl;
	cout << "2 -MAX " << endl;
	cout << "3 -MAX EXTRACT " << endl;
	cout << "4 -INCREASE KEY " << endl;
	cout << "5 -DISPLAY " << endl;
	while (  menu  == 1 ) {
		int choice;	
		cout << "ENTER YOUR CHOICE " << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				int num;
				cout << "ENTER NUMBER" << endl;
				cin >> num;
				insert( a , num, length );
				length = length ++;
				break;
			case 2:
				max ( a );
				break;
			case 3:
				maxextract(a);
	//			length =  length --;
				break;
			case 4:
				cout << endl <<"WHICH POSITION YOU WANT TO CHANGE " << endl;
				cin >>u;
				cout << "ENTER VALUE OF INDEX"<< endl;
				cin >>v;
				increase_key( a, u,v,length );
				break;
			case 5 :
				display( a);
		}
		cout << "PRESS 1 TO PERFORM MORE" << endl;
		cin >> menu;
	}
	return 0;
}


