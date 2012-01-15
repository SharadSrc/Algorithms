/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */

#include <iostream>
using namespace std;

void print_matrix(int a[][100],int n){
	for ( int i = 1; i<= n; i++){
		for ( int j = 1; j <= n; j++){
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}
void floyed (int d[][100], int p[][100], int n){
	for ( int k = 1; k<= n; k++){
		for ( int i = 1; i<=n; i++){
			for ( int j = 1; j<=n; j++){

				if( d[i][j] <= d[i][k]+ d[k][j] ) {
					p[i][j]=p[i][j];
				}

				else{
					p[i][j] = p[k][j];
				}
				if(d[i][j]<d[i][k]+d[k][j]){
					d[i][j]=d[i][j];

				}
				else{
					d[i][j]=d[i][k]+d[k][j];

				}
			}
		}
	}
	cout << "SHORTEST PATH WEIGTH MATRIX"<< endl;
	print_matrix(d,n);

	cout << "SHORTEST PATH MATRIX "<< endl;
	print_matrix(p,n);
}

int main()
{
	int vertex;
	int edge;
	int weight;
	int i,j;
	int d[100][100];
	int p[100][100];
	cout <<"VERTEX" << endl;
	cin >> vertex;
	cout << "EDGE" << endl;
	cin >> edge;

	for ( i = 1; i<= vertex; i++){
		for ( j = 1; j <= vertex; j++){
			if (i == j){
				d[i][j]=0;
			}
			else {
				d[i][j]=999999;

			}
			p[i][j]=0;
		}
	}

	cout << "EDGE 1 " <<"EDGE 2 " << "WEIGHT" << endl;
	for ( int k = 0; k <= edge; k++) {
		cin >>  i >> j >> weight;
		d[i][j] = weight;
		p[i][j] = i;

	}
	floyed(d,p,vertex);


}
