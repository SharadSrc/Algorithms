/*
 * Name :sharad Dixit
 * Institute :IIITA
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>

using namespace std;

class node{
	public:
		char ch;
		int oc;
		node *left;
		node *right;
		node *parent;

	node(char chh,int occ, node *l=NULL,node *r=NULL)
	{
		parent=NULL;
		ch=chh;
		oc=occ;
		left=l;
		right=r;
	}

	friend bool operator < (const node &n1,const node &n2) {
//		cout << n1.ch << " " << n1.oc << " " << n2.ch << " " << n2.oc << endl;
		return n1.oc > n2.oc;
	}
};

int main()
{
	priority_queue< node > pq,pq1;
	map<char,node*> add;
	map<char,string> r;

   	cout << "\nEnter the message string\n";
	string s;
	getline(cin,s);

	for(char ch=0;ch<127;ch++) {
		int tmp=count(s.begin(),s.end(),ch);
			
		if(tmp) {
			node nnode ( ch, tmp );
			pq.push ( nnode );
//			cout << pq.top().ch << endl;
		}
	}

	pq1=pq;

	while(pq.size()>=2) {
		
		node *n1 = new node(pq.top());
	
		pq.pop();

		add[n1->ch] = n1;
	
		if(n1->left) {
			(n1->left)->parent=n1;
		}

		if(n1->right) {
			(n1->right)->parent=n1;
		}

		node *n2 = new node(pq.top());
		
		pq.pop();
		
		add[n2->ch] = n2;
	
		if(n2->left) {
			(n2->left)->parent=n2;
		}
		
		if(n2->right) {
			(n2->right)->parent=n2;
		}
		
		node n('@',n1->oc+n2->oc,n1,n2);
		
		pq.push(n);
		
	}

	node *root = new node(pq.top());

	if(root->left) {
		(root->left)->parent = root;
	}

	if(root->right) {
		(root->right)->parent = root;
	}

	while(!pq1.empty()) {
		char c = pq1.top().ch;
		pq1.pop();

		node *tmp = add[c];

		string ss="";

		while(tmp->parent) {
			if((tmp->parent)->left == tmp) {
				ss+='0';
			}
			if((tmp->parent)->right == tmp) {
				ss+='1';
			}
			tmp=tmp->parent;
		}

		reverse(ss.begin(),ss.end());
		r[c]=ss;
		cout << c <<"-"<<ss << endl;
	}
	
	cout << "\n";
	string code = "";
	
	for(int i=0;i<s.size();i++) {
		code= code + r[s.at(i)];
	}
	
	cout <<  code << endl; 
	
	return 0;
}
