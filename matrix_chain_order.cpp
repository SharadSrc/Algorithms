
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */

#include <iostream>

using namespace std;

void print_optimum( int s[][100], int i, int j ){

       	if (i == j){
	       cout << "A" << i;
	}


	else {
		cout << "(";

	print_optimum(s, i, s[i][j]);
	print_optimum(s, s[i][j] + 1, j );
	cout << ")";
	}
}

void matrix( int p[],int n)
{
	int m[100][100]={0};
	int s[100][100]={0};
	int q;
	int j,k,i;

	for ( int l = 2; l<= n;l++){
		for (  i = 1; i<= n -l +1;i++){
			j = i+l-1;
			m[i][j]=9999999;
			for ( k =i;k <=j-1;k++){
				q =m[i][k] + m[k+ 1][j]+p[i-1]*p[k]*p[j];
				if ( q < m[i][j]){
					 m[i][j]=q;
					 s[i][j]=k;
				}
			}			
		}
	}
	cout << i << " " << j << endl;
	print_optimum(s,i-1,j );
	
	cout << "\n" << "Minimum No. of computation required --" << m[1][n];

}
int main () 
{
	int a;
	int p[100]={0};
	cout << "No. of matrix";
	cin >> a;

	for ( int i = 0; i <= a; i++){
		int temp ;
		cin >> temp;
		p[i]=temp;
	}
	matrix(p,a);
}

