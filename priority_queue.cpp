
/*
 * Name :sharad Dixit
 * Institute :IIIT -A
 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct node{
	int h;
	struct node*next;

};
class compare{
	public:
		bool operator()(node& t1, node& t2)
		{
			if (t1.h > t2.h) return true;
	//		if (t1.h == t2.h && t1.m < t2.m) return true;
	//		if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
			return false;
		}
};

int main()
{
	priority_queue< node ,vector<node>, compare>p;
	node r[10]={{3,NULL},{42,NULL},{5,NULL}};

	for ( int i =0;i<3;i++){
		p.push(r[i]);
	}

	while(!p.empty()){
		node t = p.top();
		cout << t.h <<" " <<endl;
		p.pop();
	}

	return 0;
}


