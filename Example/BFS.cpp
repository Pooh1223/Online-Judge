#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	//initialize;
	printf("Please enter the amount of the points.\n");
	int p;
	scanf("%d",&p);
	printf("Now please two points to suggest the line.\nAnd enter \"0 0\" to stop this part.\n");
	int l1,l2;
	bool line[p + 1][p + 1],pass[p + 1];
	memset(line,0,sizeof(line));
	memset(pass,0,sizeof(pass));
	while(scanf("%d %d",&l1,&l2) && l1 && l2){
		line[l1][l2] = 1;
		line[l2][l1] = 1;
	}
	printf("The traversal of BFS is : ");
	//
	//BFS;
	queue<int> q; //a queue;
	for(int i = 1;i <= p;i++){
		if(!pass[i]){
			
			q.push(i);//add the start to queue;
			pass[i] = 1;//label it to mean "passed";
			
			//if it's not empty,repeat the following steps;
			while(!q.empty()){
				//step(1) take the first element in the queue and pop it;
				int k = q.front();
				printf("%d ",k);
				q.pop();
				//step(2) find the all points which is not "passed" and put it into queue;
				for(int j = 1;j <= p;j++)
					if(line[k][j] && !pass[j]){
						q.push(j);
						pass[j] = 1;	
					}
			}
		}
	}
	printf("\n");
	return 0;
}
