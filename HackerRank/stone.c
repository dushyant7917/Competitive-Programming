#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    char val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, char val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    char val;
    LinkedListNode *next;
};
*/

LinkedListNode *top;

void push_stack(char v);
void pop_stack();
char peek_stack();

void push_stack(char v)
{
  LinkedListNode *ptr;
  ptr=(LinkedListNode *)malloc(sizeof(LinkedListNode));
  if(ptr==0)
  printf("\nMEMORY OVERFLOW!");
  else
  {
      ptr->val=v;
      ptr->next=top;
      top=ptr;
  }
}

void pop_stack()
{
  LinkedListNode *ptr;
  if(top==NULL)
  printf("\nMEMORY UNDERFLOW");
  else
  {
    ptr=top;
    top=top->next;
    free(ptr);
  }
}

char peek_stack()
{
  if(top==0)
    return -1;
  else
    return top->val;
}

bool isPalindrome(LinkedListNode* head) {

    LinkedListNode *node=head;
    LinkedListNode *stack=(LinkedListNode *) (malloc(sizeof(LinkedListNode)));
    while(node!=NULL){
      push_stack(node->val);
      node=node->next;
    }
    while(top!=NULL && head!=NULL){
      if(top->val!=head->val) return false;
      top=top->next;
      head=head->next;
    }
    return true;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    scanf("%d", &head_size);
    char s[10005];
    scanf(" %s", s);
    for(int i = 0; i < head_size; i++) {
        char head_item = s[i];
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    res = isPalindrome(head);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
