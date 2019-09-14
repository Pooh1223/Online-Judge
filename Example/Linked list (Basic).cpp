#include <cstdio>
#include <cstdlib>

typedef struct node{
	int val;
	node* next;
}node;
node* head = NULL;
// insert val in head of a link list
void insert_in_head(int val){
   // create a node for val
   node *data = (node *) malloc(sizeof(node));
   data->val = val;
   // link head next to data
   data->next = head;
   // new head = data
   head = data;
}
node *tail = NULL;
// insert val in tail of a link list
void insert_in_tail(int val)
{
   // create a node for val
   node *data = (node *) malloc(sizeof(node));
   data->val = val;
   // link NULL to data
   data->next = NULL;

   // if there is no existing node
   if (head == NULL)
      // then this node is head and also tail
      head = tail = data;
   else {
      // otherwise, this node is new tail
      tail->next = data;
      tail = data;
   }
}

int main(){
	
	return 0;
}
