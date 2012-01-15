/*
 * Name :sharad Dixit
 * Institute :IIITA
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
	float data;
	struct node *next;
};

void find_bucket( float arr[], int n, node *buck[])
{
	for ( int i = 0; i < n; i++) {

		int tmp = arr[i];
		node *temp = new node;		
		temp->data = arr[i];
		temp->next = buck[tmp];
		buck [tmp] = temp;
	}
}

void sort_link( int n, node *buck[]) {

	for ( int i = 0; i < n; i++ ) {
		node *temp = buck[i];
		while ( temp != NULL) {
			node *check = temp ->next;


			while ( check != NULL) {
				if ( (temp -> data) > (check -> data) ){
					float count = temp ->data;
					temp -> data = check -> data;
					check ->data = count;

				}
				check = check->next;
			}
			temp = temp ->next;
		}
	}
}


void read_sorted(float arr[],int n , node *buckets[]){
	for (int i = 0; i<n ;i++){
		struct node * temp = new node;
		temp = buckets[i];
		while ( temp != NULL ) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}				
					

int main( int argc, char *argv[] )
{
	int n = atoi ( argv[1] );
	float arr[ n ];

	node *buckets[n];
	cout << "BEFORE\n";

	for ( int i = 0; i < n; i++){
		buckets[i] = NULL;
		float tmp = rand()%100;
		arr[i] = tmp /100;
//cout <<  arr[i] << "\n";
	}

	find_bucket(arr,n,buckets);
	sort_link( n,buckets); 
	cout << "AFTER " << endl;
	read_sorted( arr,n , buckets);

}
