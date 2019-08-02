#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 300001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

struct Trie{
  ll child[2];
  ll cnt;
  Trie(){
    child[0]=child[1]=-1;
    cnt=0;
  }
};

Trie trie[N*32];

ll node=0;

void insert(ll n){
  ll bit,cur=0;

  rf(i,30,0){
    if(n&(1<<i)) bit=1;
    else bit=0;

    if(trie[cur].child[bit]==-1){
      trie[cur].child[bit]=++node;
      trie[node]=Trie();
    }

    cur=trie[cur].child[bit];
    trie[cur].cnt++;
  }
}

ll query(ll n){
  ll bit,res=0,cur=0;

  rf(i,30,0){
    if(n&(1<<i)) bit=1;
    else bit=0;

    if(trie[cur].child[bit]!=-1 && trie[trie[cur].child[bit]].cnt){
      cur=trie[cur].child[bit];
      trie[cur].cnt--;
    }
    else{
      res+=(1<<i);
      cur=trie[cur].child[1-bit];
      trie[cur].cnt--;
    }
  }

  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n],x;

  fr(i,0,n) cin>>a[i];

  fr(i,0,n){
    cin>>x;
    insert(x);
  }

  fr(i,0,n) cout<<query(a[i])<<" ";

  return 0;
}
