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

struct Trie{
  ll num;
  Trie *child[2];
};

Trie* getNode(){
  Trie *ptr=new Trie;
  ptr->child[0]=NULL;
  ptr->child[1]=NULL;
  ptr->num=0;
  return ptr;
}

void insert(Trie*& root,ll val){
  Trie *ptr=root;
  bool bit;

  rf(i,31,0){
    bit=val&(1<<i);

    if(ptr->child[bit]==NULL) ptr->child[bit]=getNode();
    ptr=ptr->child[bit];

    ptr->num++;
  }
}

ll query(Trie* root,ll val,ll k){
  Trie *ptr=root;
  bool bit,x;
  ll cnt=0;

  rf(i,31,0){
    x=k&(1<<i);
    bit=val&(1<<i);

    if(x){
      if(ptr->child[bit]!=NULL) cnt+=ptr->child[bit]->num;

      if(ptr->child[1-bit]!=NULL) ptr=ptr->child[1-bit];
      else return cnt;
    }

    else{
      if(ptr->child[bit]!=NULL) ptr=ptr->child[bit];
      else return cnt;
    }
  }

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k;
  cin>>n>>k;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  Trie *root=getNode();

  ll p=0,ans=0;

  insert(root,0);

  fr(i,0,n){
    p=p^a[i];
    ans+=query(root,p,k);
    insert(root,p);
  }

  cout<<ans;

  return 0;
}
