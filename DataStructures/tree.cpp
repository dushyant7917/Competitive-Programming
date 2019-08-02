#include<bits/stdc++.h>

using namespace std;

struct Node{
  int val;
  struct Node *left,*right,*adj;
};

Node* createNode(int x){
  Node* ptr=new Node;
  ptr->val=x;
  ptr->left=ptr->right=ptr->adj=NULL;
  return ptr;
}

void inOrder(Node* root){
  if(root==NULL) return;

  inOrder(root->left);
  cout<<root->val<<" ";
  inOrder(root->right);
}

void preOrder(Node* root){
  if(root==NULL) return;

  cout<<root->val<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node* root){
  if(root==NULL) return;

  postOrder(root->left);
  postOrder(root->right);
  cout<<root->val<<" ";
}

bool identical(Node* t1,Node* t2){
  if(t1==NULL && t2==NULL) return true;

  if(t1->val!=t2->val) return false;

  if(identical(t1->left,t2->left) && identical(t1->right,t2->right)) return true;
  else return false;
}

void joinAdjacent(Node*& root){
  Node *ptr=root;

  queue<Node*> q;
  if(ptr!=NULL) q.push(ptr);
  q.push(NULL);

  Node *node;

  while(q.size()){
    node=q.front();
    q.pop();
    if(node!=NULL){
      node->adj=q.front();
      if(node->left!=NULL) q.push(node->left);
      if(node->right!=NULL) q.push(node->right);
    }
    else{
      if(q.size()) q.push(NULL);
    }
  }
}

void printAdjacent(Node* root){
  if(root==NULL) return;

  cout<<root->val<<" -> "<<((root->adj!=NULL)?(root->adj->val):(-1))<<"\n";
  printAdjacent(root->left);
  printAdjacent(root->right);
}

Node* lca(Node* root,int a,int b){
  if(root==NULL) return NULL;

  if(root->val==a || root->val==b) return root;

  Node* left=lca(root->left,a,b);
  Node* right=lca(root->right,a,b);

  if(left!=NULL && right!=NULL) return root;

  if(left!=NULL) return left;
  else return right;
}

Node* lcaBST(Node* root,int a,int b){
  if(root==NULL) return NULL;

  if(root->val>a && root->val>b) return lcaBST(root->left,a,b);
  else if(root->val<a && root->val<b) return lcaBST(root->right,a,b);
  else return root;
}

bool present(Node* root,int v){
  if(root==NULL) return false;

  if(root->val==v) return true;
  else return (present(root->left,v) || present(root->right,v));
}

int mx=0,mn=1000000;

void height(Node* root,int lev){
  if(root==NULL) return;

  if(root->left==NULL && root->right==NULL){
    mx=max(mx,lev);
    mn=min(mn,lev);
  }

  height(root->left,lev+1);
  height(root->right,lev+1);
}

Node *a=NULL,*b=NULL;

void swapNodesBST(Node *root,int mn,int mx){
  if(root==NULL) return;

  if(root->val<mn || root->val>mx){
    if(a==NULL){
      a=root;
      //cout<<"a:"<<a->val<<"\n";
    }
    else{
      b=root;
      //cout<<"b:"<<b->val<<"\n";
    }
  }

  swapNodesBST(root->left,mn,root->val-1);
  swapNodesBST(root->right,root->val+1,mx);
}

bool rootToLeafSum(Node* root,int sum){
  if(root==NULL){
    if(sum==0) return true;
    else return false;
  }

  return (rootToLeafSum(root->left,sum-root->val) || rootToLeafSum(root->right,sum-root->val));
}

int sumTree(Node*& root){
  if(root==NULL) return 0;

  int tmp=root->val;
  root->val=sumTree(root->left)+sumTree(root->right);
  return tmp+root->val;
}

void printDistanceK(Node* root,int k){
  if(root==NULL) return;

  if(k==0) cout<<root->val<<" ";

  printDistanceK(root->left,k-1);
  printDistanceK(root->right,k-1);
}

int main(){
  Node *t1,*t2,*t3;

  t1=createNode(1);
  t1->left=createNode(2);
  t1->right=createNode(3);
  t1->left->left=createNode(6);
  t1->right->right=createNode(5);
  t1->right->left=createNode(4);
  t1->left->left->right=createNode(7);
  /*
  cout<<"\nIn-Order traversal of tree 1 : "; inOrder(t1);
  cout<<"\nPre-Order traversal of tree 1 : "; preOrder(t1);
  cout<<"\nPost-Order traversal of tree 1 : "; postOrder(t1);
  */

  t2=createNode(5);
  t2->left=createNode(3);
  t2->right=createNode(8);
  t2->left->left=createNode(2);
  t2->left->left->left=createNode(1);
  t2->left->right=createNode(4);
  t2->right->right=createNode(9);
  t2->right->left=createNode(6);
  t2->right->left->right=createNode(7);

  //if(identical(t1,t2)) cout<<"\nTree 1 and Tree 2 are identical";
  //else cout<<"\nTree 1 and Tree 2 are not identical";

  //joinAdjacent(t1);
  //printAdjacent(t1);

  //if(present(t1,2) && present(t1,7)) cout<<lca(t1,2,7)->val<<"\n";
  //else cout<<-1<<"\n";

  //if(present(t2,7) && present(t2,9)) cout<<lcaBST(t2,7,9)->val<<"\n";
  //else cout<<-1<<"\n";

  /*
  height(t2,0);
  if(mx-mn==0 || mx-mn==1) cout<<"Tree is height balanced\n";
  else cout<<"Tree is not height balanced\n";
  */

  t3=createNode(6);
  t3->left=createNode(5);
  t3->right=createNode(10);
  t3->left->left=createNode(2);
  t3->left->right=createNode(8);
  t3->right->left=createNode(9);
  t3->right->right=createNode(11);
  t3->left->right->left=createNode(1);
  t3->left->right->right=createNode(2);

  /*
  cout<<"\nIn-Order traversal of tree 3 : "; inOrder(t3);
  swapNodesBST(t3,-100,100);
  if(b==NULL) b=t3;
  if(a!=NULL && b!=NULL) swap(a->val,b->val);
  cout<<"\nIn-Order traversal of tree 3 : "; inOrder(t3);
  */

  //if(rootToLeafSum(t3,27)) cout<<"Path exists with sum = "<<27<<"\n";
  //else cout<<"Path does not exist with sum = "<<27<<"\n";

  /*
  cout<<"\nIn-Order traversal of tree 3 : "; inOrder(t3);
  if(t3!=NULL) sumTree(t3);
  cout<<"\nIn-Order traversal of tree 3 : "; inOrder(t3);
  */

  //cout<<"\nNodes at distance k from root of tree 3 are : ";
  //printDistanceK(t3,2);

  return 0;
}
