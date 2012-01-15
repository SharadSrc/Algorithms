
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */

#include <iostream>
#include <vector>

using namespace std;

void print(string b[][100],string s,int i,int j) 
{
	if ( i == 0 || j == 0) {
		return ;
	}
	if (b[i][j] == "NW") {
		print(b,s,i-1,j-1);
	
	cout << s[i-1] << "  ";
	}

	else if (b[i][j] == "N") {
		print(b,s,i-1,j);
	}
	else {
		print(b,s,i,j-1);
	}


}

void lcs( string s1, string s2 )
{
	int l1;
	int l2;
	int c[100][100];
	string b[100][100];

	l1 = s1.size();
	l2 = s2.size();

//	for ( int i = 0; i<= l1; i++ ) {
//		c[i][0] = 0;
//	}

//	for ( int j = 0; j<= l2; j++ ) {
//		c[0][j] = 0;
//	}

	for ( int i = 1; i<=l1; i++){
		for ( int j = 1; j<=l2; j++){
			if (s1[i-1] == s2[j-1]){
				c[i][j]= c[i-1][j-1] +1;
				b[i][j]="NW";	

			}
			else {
				if (c[i -1][j] >= c[i][j-1] ){
					c[i][j] = c[i-1][j];
					b[i][j] = "N";
				}
				else{
					c[i][j] = c[i][j-1];
					b[i][j] = "W";
				}
			}
		}
	}

	for ( int i = 0;i <= l1; i++){
		for ( int j =0 ;j<= l2; j++){
			cout << c[i][j] <<"  ";
		}
		cout << endl;
	}
	cout << "LONGEST COMMON SUBSEQUENCE"<< endl;
	print(b,s1,l1,l2);

	cout << endl;
}



int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	lcs(s1,s2);
}
