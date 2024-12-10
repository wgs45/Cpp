#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<int> q;
	int i,count=0, a;
	while(cin>>a){
		count++;
		q.push(a);
		if(count%4==0){
			q.pop();
		}
	}
	while(q.size()>0){
		cout << q.front() << " ";
		q.pop();
	}
 
	return 0;
}