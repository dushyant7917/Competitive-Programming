#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,p;
ll pre[N],post[N],in[N];
ll a[N],b[N],c[N];
ll preInd=0;

struct Node{
  ll val;
  struct Node *left,*right;
};

Node* getNode(ll val){
  Node *ptr=new Node;
  ptr->val=val;
  ptr->left=ptr->right=NULL;
  return ptr;
}

ll search(ll l,ll r,ll val){
  fr(i,l,r+1) if(in[i]==val) return i;
}

Node* buildTree(ll inL,ll inR){
  if(inL>inR) return NULL;

  Node *ptr=getNode(pre[preInd++]);

  if(inL==inR) return ptr;

  ll ind=search(inL,inR,ptr->val);

  ptr->left=buildTree(inL,ind-1);
  ptr->right=buildTree(ind+1,inR);

  return ptr;
}

void preOrder(Node *ptr){
  if(ptr==NULL) return;
  a[p++]=ptr->val;
  preOrder(ptr->left);
  preOrder(ptr->right);
}

void postOrder(Node *ptr){
  if(ptr==NULL) return;
  postOrder(ptr->left);
  postOrder(ptr->right);
  b[p++]=ptr->val;
}

void inOrder(Node *ptr){
  if(ptr==NULL) return;
  inOrder(ptr->left);
  c[p++]=ptr->val;
  inOrder(ptr->right);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>pre[i];
  fr(i,0,n) cin>>post[i];
  fr(i,0,n) cin>>in[i];

  Node *root=NULL;
  root=buildTree(0,n-1);

  p=0;
  preOrder(root);
  p=0;
  postOrder(root);
  p=0;
  inOrder(root);

  bool flag=true;
  fr(i,0,n) if(pre[i]!=a[i]) flag=false;
  fr(i,0,n) if(post[i]!=b[i]) flag=false;
  fr(i,0,n) if(in[i]!=c[i]) flag=false;

  if(flag) cout<<"yes";
  else cout<<"no";

  return 0;
}
