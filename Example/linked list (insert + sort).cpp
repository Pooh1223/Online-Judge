#include <cstdio>
#include <cstdlib>

typedef struct node {
   int val;
   struct node *next;
}node;

node *head = NULL;
// insert value "val" into link list
void insert_value(int val)
{
   node *prev, *rush;
   // create node for that insertor
   node *data = (node*) malloc(sizeof(node));
   // put the value in that node
   data->val = val;

   prev = rush = head;
   // find out the correct position for val
   while (rush != NULL && val > rush->val) {
      prev = rush;
      rush = rush->next;
   }

   // link it next to the bigger value
   data->next = rush;
   // if there is no element in link list
   // or val is the smallest
   if (rush == head)
      head = data;
   else
      prev->next = data;

}

// show link list elements
void show_list(void)
{
   node *rush = head;
   printf("\nThe result is:\n");
   while (rush != NULL) {
      printf("%d ", rush->val);
      rush = rush->next;
   }
   puts("");


}
int main()
{
   int n;
   printf("Enter values:\n");
   while(scanf("%d", &n) != EOF) {
      printf("%d ", n);
      insert_value(n);
   }
   show_list();
   return 0;

}
