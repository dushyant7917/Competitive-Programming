#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
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
    int val;
    LinkedListNode *next;
};
*/
bool findIntersection(LinkedListNode* head1, LinkedListNode* head2) {
  LinkedListNode *node1=head1;
  LinkedListNode *node2=head2;
  while(node1->next!=NULL){
    node1=node1->next;
  }
  while(node2->next!=NULL){
    node2=node2->next;
  }
  if(node1==node2){
    return true;
  }
  return false;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head1_size = 0;

    LinkedListNode* head1 = NULL;
    LinkedListNode* head1_tail = NULL;

    scanf("%d", &head1_size);
    for(int i = 0; i < head1_size; i++) {
        int head1_item;
        scanf("%d", &head1_item);
        head1_tail = _insert_node_into_singlylinkedlist(head1, head1_tail, head1_item);

        if(i == 0) {
            head1 = head1_tail;
        }
    }


    int head2_size = 0;

    LinkedListNode* head2 = NULL;
    LinkedListNode* head2_tail = NULL;

    scanf("%d", &head2_size);
    for(int i = 0; i < head2_size; i++) {
        int head2_item;
        scanf("%d", &head2_item);
        head2_tail = _insert_node_into_singlylinkedlist(head2, head2_tail, head2_item);

        if(i == 0) {
            head2 = head2_tail;
        }
    }

    int token;
    scanf("%d", &token);
    if (token != 0){
        token--;
        LinkedListNode* ptr = head1;
        while(token--){
            ptr = ptr->next;
        }
         if (head2 == NULL) head2 = ptr;
        else head2_tail->next = ptr;
    }

    res = findIntersection(head1, head2);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
