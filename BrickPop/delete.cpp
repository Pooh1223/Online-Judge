#include <iostream>
using namespace std;

int stat[5][5] = {{1,2,2,2,1},{1,1,3,2,1},{2,2,2,2,3},{2,1,1,2,1},{1,1,2,2,1}};
void print(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<stat[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"over"<<endl;
}
void checkXY(int x,int y,int val){
	if(stat[x][y]==val){
		stat[x][y]=0;
		if(y!=4)checkXY(x,y+1,val);
		if(y!=0)checkXY(x,y-1,val);
		if(x!=4)checkXY(x+1,y,val);
		if(x!=0)checkXY(x-1,y,val);
	}
}
 
int main(){
	print();
	checkXY(0,1,stat[0][1]);
	print();
}
