#include<bits/stdc++.h>

using namespace std;

struct Node{
  int val;
  struct Node *nxt;
};

Node* getNode(int x){
  Node* ptr=new Node;
  ptr->val=x;
  ptr->nxt=NULL;
  return ptr;
}

void printList(Node* root){
  Node* ptr=root;

  cout<<"\n\nPrinting linked list elements : ";
  while(ptr!=NULL){
    cout<<ptr->val<<" ";
    ptr=ptr->nxt;
  }
  cout<<"\n";
}

void insertEnd(Node*& root,int x){
  Node* ptr=root;

  if(ptr==NULL) root=getNode(x);
  else{
    while(ptr->nxt!=NULL) ptr=ptr->nxt;
    ptr->nxt=getNode(x);
  }

  cout<<"\n"<<x<<" inserted at the end of the linked list";
}

void insertBeg(Node*& root,int x){
  Node* ptr=getNode(x);
  ptr->nxt=root;
  root=ptr;

  cout<<"\n"<<x<<" inserted at the begining of the linked list";
}

void insertAfter(Node*& root,int v,int x){
  Node* ptr=root;
  bool found=false;

  while(ptr!=NULL && ptr->val!=v) ptr=ptr->nxt;

  if(ptr!=NULL && ptr->val==v){
    found=true;
    Node* tmp=getNode(x);
    tmp->nxt=ptr->nxt;
    ptr->nxt=tmp;
  }

  if(!found) cout<<"\n"<<v<<" not found in the linked list";
  else cout<<"\n"<<x<<" inserted after "<<v<<" in the linked list";
}

void insertBefore(Node*& root,int v,int x){
  Node* ptr=root;
  bool found=false;

  if(ptr!=NULL && ptr->val==v){
    found=true;
    Node* tmp=getNode(x);
    tmp->nxt=ptr;
    root=tmp;
  }

  else{
    while(ptr->nxt!=NULL && ptr->nxt->val!=v) ptr=ptr->nxt;

    if(ptr->nxt!=NULL && ptr->nxt->val==v){
      found=true;
      Node* tmp=getNode(x);
      tmp->nxt=ptr->nxt;
      ptr->nxt=tmp;
    }
  }

  if(!found) cout<<"\n"<<v<<" not found in the linked list";
  else cout<<"\n"<<x<<" inserted before "<<v<<" in the linked list";
}

void deleteVal(Node*& root,int v){
  Node* ptr=root;
  bool found=false;

  if(ptr!=NULL && ptr->val==v){
    found=true;
    root=ptr->nxt;
    free(ptr);
  }

  else{
    while(ptr->nxt!=NULL && ptr->nxt->val!=v) ptr=ptr->nxt;

    if(ptr->nxt!=NULL && ptr->nxt->val==v){
      found=true;
      Node* tmp=ptr->nxt;
      ptr->nxt=ptr->nxt->nxt;
      free(tmp);
    }
  }

  if(!found) cout<<"\n"<<v<<" not found in the linked list";
  else cout<<"\n"<<v<<" deleted from the linked list";
}

void deleteList(Node*& root){
  Node* ptr=root;
  Node* tmp;

  while(ptr!=NULL){
    tmp=ptr->nxt;
    free(ptr);
    ptr=tmp;
  }

  root=NULL;

  cout<<"\nLinked list deleted";
}

void reverseList(Node*& root){
  Node *cur=root,*prv=NULL,*nxt=NULL;

  while(cur!=NULL){
    nxt=cur->nxt;
    cur->nxt=prv;
    prv=cur;
    cur=nxt;
  }

  root=prv;

  cout<<"\nLinked list reversed";
}

int lenList(Node* root){
  Node* ptr=root;

  int len=0;

  while(ptr!=NULL){
    ptr=ptr->nxt;
    len++;
  }

  return len;
}

bool isPalindrome(Node* root){
  Node* ptr=root;

  int cnt=0,len=lenList(root);

  Node *prv=NULL,*cur=root,*nxt=NULL;

  while(cnt<(len/2)){
    nxt=cur->nxt;
    cur->nxt=prv;
    prv=cur;
    cur=nxt;
    cnt++;
  }

  Node *left=prv,*right=(len&1)?(cur->nxt):(cur);

  bool flag=true;

  while(left!=NULL && right!=NULL){
    if(left->val!=right->val){
      flag=false;
      break;
    }
    left=left->nxt;
    right=right->nxt;
  }

  if(flag) return true;
  else return false;
}

void addList(Node*& res,Node* list1,Node* list2){
  Node *ptr1=list1,*ptr2=list2;
  int carry=0,sum;

  while(ptr1!=NULL && ptr2!=NULL){
    sum=ptr1->val+ptr2->val+carry;
    carry=sum/10;
    sum=sum%10;
    insertBeg(res,sum);
    ptr1=ptr1->nxt;
    ptr2=ptr2->nxt;
  }

  if(ptr1==NULL && ptr2!=NULL){
    while(ptr2!=NULL){
      sum=ptr2->val+carry;
      carry=sum/10;
      sum=sum%10;
      insertBeg(res,sum);
      ptr2=ptr2->nxt;
    }
  }

  if(ptr1!=NULL && ptr2==NULL){
    while(ptr1!=NULL){
      sum=ptr1->val+carry;
      carry=sum/10;
      sum=sum%10;
      insertBeg(res,sum);
      ptr1=ptr1->nxt;
    }
  }

  if(ptr1==NULL && ptr2==NULL && carry) insertBeg(res,carry);
}

Node* reverseInGroupK(Node* root,int k){
  Node *cur=root,*tmp,*prv=NULL;
  int cnt=0;

  while(cnt<k && cur!=NULL){
    tmp=cur->nxt;
    cur->nxt=prv;
    prv=cur;
    cur=tmp;
    cnt++;
  }

  if(cur!=NULL) root->nxt=reverseInGroupK(cur,k);

  return prv;
}

int main(){
  /*
  // intializing a linked list
  Node *root=NULL;

  printList(root);

  insertBeg(root,3);
  printList(root);

  insertEnd(root,2);
  insertEnd(root,5);
  printList(root);

  insertBeg(root,3);
  printList(root);

  insertAfter(root,7,9);
  printList(root);

  insertAfter(root,3,9);
  printList(root);

  insertBefore(root,2,9);
  printList(root);

  deleteVal(root,2);
  printList(root);

  reverseList(root);
  printList(root);

  deleteList(root);
  printList(root);

  insertEnd(root,2);
  insertEnd(root,3);
  insertEnd(root,1);
  insertEnd(root,1);
  insertEnd(root,3);
  insertEnd(root,2);
  printList(root);

  if(isPalindrome(root)) cout<<"\nLinked list is palindromic\n";
  else cout<<"\nLinked list is not palindromic\n";

  deleteList(root);
  printList(root);

  insertEnd(root,2);
  insertEnd(root,3);
  insertEnd(root,1);
  insertEnd(root,3);
  insertEnd(root,1);
  printList(root);

  if(isPalindrome(root)) cout<<"\nLinked list is palindromic\n";
  else cout<<"\nLinked list is not palindromic\n";
  */

  Node *list1=NULL;
  //Node *list2=NULL;
  //Node *res;

  insertEnd(list1,1);
  insertEnd(list1,2);
  insertEnd(list1,3);
  insertEnd(list1,4);
  insertEnd(list1,5);
  //insertEnd(list1,6);
  printList(list1);

  /*
  insertEnd(list2,9);
  insertEnd(list2,9);
  insertEnd(list2,9);
  insertEnd(list2,9);
  insertEnd(list2,9);
  insertEnd(list2,9);
  printList(list2);

  res=NULL;
  reverseList(list1);
  reverseList(list2);
  addList(res,list1,list2);
  printList(res);
  deleteList(res);
  */

  list1=reverseInGroupK(list1,3);
  printList(list1);

  return 0;
}
