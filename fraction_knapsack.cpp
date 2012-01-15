
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */


#include <iostream>

using namespace std;
void sort ( int table[][100],int a)
{
	for ( int i = 0; i < a; i++ ) {
		for ( int j = 0 ; j < a-1; j++){
			float k = table[j][1]/table[j][0];
			float l = table[j+1][1]/table[j+1][0];
				if (l > k){
					int temp = table[j][1];
					table[j][1] = table[j+1][1];
					table[j+1][1] = temp;

					temp =  table[j][0];
					table[j][0] = table[j+1][0];
					table[j+1][0] = temp;
				}
		}
	}
}

void knapsack(int b[][100],int a,int capacity){
	int total = 0;
	int price=0;
	int i =0;
	while ( total < capacity && i<a) {
		total  = total + b[i][0];
		price = price + b[i][1];
		i++;


	}
	i--;
	price = price - b[i][1];
	total = total - b[i][0];
	int difference = capacity -total;
//	cout << difference;
	price = price + (difference)*b[i][1]/b[i][0];

	cout << "OPTIMUM MONEY TAKEN  - " << price;

}	

int main()
{
	int a;
	int weight;
	int cost;
	int table[100][100];
	int capacity;
	cout << "NO. of items"<< endl;
	cin >> a;
	cout << "ENTER WEIGHT AND COST" << endl;
	for ( int i =0; i<a; i++) {
		cin >> weight>> cost;
		table[i][0] = weight;
		table[i][1]= cost;
	}
	cout << "CAPACITY OF KNAPSACK"<< endl;
	cin >> capacity;
	sort ( table,a);
/*
	for ( int i = 0; i< a; i++) {
		cout << table[i][0] << " " <<  table[i][1] << endl;
	}*/

	knapsack(table,a,capacity);


}
