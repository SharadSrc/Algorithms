
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */



#include <iostream>

using namespace std;

int hash_function( int  data ); 

void insert ( int data ,int a[]) {

	int key = hash_function( data );

	if (a [ key ] == NULL ){
		a [ key ] = data;
		key++;
	}
	else {
		while (  a [key] != NULL ) {
			key++;
		}
		a[ key ] = data;
	}
}

int hash_function( int  data ) {
	 int a = data % 10;
	 
	 if ( a >=0){
		 return a;
	 }
	 
	 else {
		 return (-a);
	 }


}

int remove( int data , int a[]) {

	int key = hash_function(data);

	if ( a [ key ] == data ) {
		a [ key ] = -1;
	}

	else {
		while ( a[key] != data ){
			key ++;
		/*	if ( a[key] == NULL ){
				break;
			}*/
		}
		a[ key ] = -1;
	}

}

int show ( int a [] ){

	for ( int i=0;i<20 ;i++){
		cout << "Array[ " << i << " ] = "<< a[i] << endl;
	}
}

void search ( int a[], int data){
	int key = hash_function(data);
	if ( a[key] == data){
		cout << "Number found at index :-" << key << endl;
	}

	else{
	while ( a [key] !=data ) {
		key++;
		if ( a[ key ] == NULL){
			break;
		}
	}

		cout << "Number found at index :-" << key << endl;
	}
		
}
int main ()
{
	int a[100];

	int i = 0;
	int check=1;
	int c;
	int num;



	while ( check == 1 ) {
		cout << "1-insert\n";
		cout << "2-delete\n";
		cout << "3-search\n";
		cout << "4-show \n";
		cout << "Enter choice-\n";
		cin >> c;

		switch ( c ) {

			case 1:
				cout << "Enter the 11 random Values"<< endl;
				for ( int i=0;i<20;i++){
					a[i]=NULL;
			 	}


				for ( int i=0;i<11;i++){
				cin >> num;
				insert ( num , a );
				cout << "--- Content After Insetion-\n";
				show ( a );
				}

				break;
			case 2:
				cin >> num;
				remove(num , a);
				break;

			case 3:			
				cin >> num;
				search ( a, num);
				break;
			case 4:
				show ( a );
				break;
				
		}

		cout << "1 To continue:";
		cin >> check;
	}
	return 0;
}
