#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

struct Node{
  ll data;
  ll left;
  ll right;
};

struct Node tree[N];

void in_order(struct Node root){
  if(root.left!=-1) in_order(tree[root.left]);
  cout<<root.data<<" ";
  if(root.right!=-1) in_order(tree[root.right]);
}

void swap(ll k){
  queue<pair<ll,ll> > q;
  q.push(MP(1,1));

  ll node,lev;
  while(!q.empty()){
    node=q.front().first;
    lev=q.front().second;
    q.pop();
    if(lev%k==0){
      swap(tree[node].left,tree[node].right);
    }
    if(tree[node].left!=-1) q.push(MP(tree[node].left,lev+1));
    if(tree[node].right!=-1) q.push(MP(tree[node].right,lev+1));
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll l,r;
  fr(i,1,n+1){
    cin>>l>>r;
    tree[i].data=i;
    tree[i].left=l;
    tree[i].right=r;
  }

  ll q;
  cin>>q;

  ll k;
  fr(i,0,q){
    cin>>k;
    swap(k);
    in_order(tree[1]);
    cout<<"\n";
  }

  return 0;
}
