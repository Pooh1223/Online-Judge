#include <cstdio>
#include <cstdlib>

struct que{
	int data;
	que* next;
	que(){data = 0;next = NULL;}
};

que* front[105];
que* end[105];

void init(){
	for(int i = 0;i < 105;i++){
		front[i] = new que();
		end[i] = front[i];
	}
}

void add(int sid,int cid){
	que* back = new que();
	back -> data = cid;
	end[sid] -> next = back;
	end[sid] = back;
}

void leave(int sid){
	if(front[sid] -> next == NULL) printf("queue %d is empty!\n",sid);
	else{
		front[sid] -> next = front[sid] -> next -> next;
		if(front[sid] -> next == NULL){
			end[sid] = front[sid];
		}
	} 
}

void join(int st,int ed){
	if(front[st] -> next == NULL)return;
	end[ed] -> next = front[st] -> next;
	end[ed] = end[st];
	front[st] -> next = NULL;
	end[st] = front[st];
}

int main(){
	int n,store;
	scanf("%d %d",&store,&n);
	init();
	while(n--){
		char order[10];
		scanf("%s",order);
		if(order[0] == 'A'){
			int shopid,cosid;
			scanf("%d %d",&shopid,&cosid);
			add(shopid,cosid);
		}
		else if(order[0] == 'L'){
			int shopid;
			scanf("%d",&shopid);
			leave(shopid);
		}
		else{
			int st,ed;
			scanf("%d %d",&st,&ed);
			join(st,ed);
		}
	}
	for(int i = 1;i <= store;i++){
		if(front[i] -> next == NULL) printf("queue %d: empty\n",i);
		else {
			printf("queue %d:",i);
			que* temp = front[i]->next;
			while(temp != NULL){
				printf(" %d",temp -> data);
				temp = temp -> next;
			}
			printf("\n");
		}
	}
	return 0;
}
