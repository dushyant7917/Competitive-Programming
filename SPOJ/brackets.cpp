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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m,a[N];

struct Tree{
  ll open; // num of un-matched opening brackets
  ll close; // num of un-matched closing brackets
};

struct Tree tree[4*N];

struct Tree merge(struct Tree t1,struct Tree t2){
  struct Tree t;

  ll change=min(t1.open,t2.close);
  t.open=t1.open+t2.open-change;
  t.close=t1.close+t2.close-change;

  return t;
}

void build(ll node,ll start,ll end){
  if(start==end){
    if(a[start]==1){
      tree[node].open=1;
      tree[node].close=0;
    }
    else{
      tree[node].open=0;
      tree[node].close=1;
    }
  }
  else{
    ll mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
  }
}

void update(ll node,ll start,ll end,ll pos){
  if(start==end){
    if(a[pos]==1){
      a[pos]=-1;
      tree[node].open=0;
      tree[node].close=1;
    }
    else{
      a[pos]=1;
      tree[node].open=1;
      tree[node].close=0;
    }
  }
  else{
    ll mid=(start+end)/2;
    if(start<=pos && pos<=mid) update(node*2,start,mid,pos);
    else update(node*2+1,mid+1,end,pos);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
  }
}

struct Tree query(ll node,ll start,ll end,ll l,ll r){
  struct Tree t;

  if(r<start || end<l){
    t.open=t.close=0;
    return t;
  }

  if(l<=start && end<=r){
    return tree[node];
  }

  ll mid=(start+end)/2;
  t=merge(query(1,start,mid,l,r),query(1,mid+1,end,l,r));
  return t;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t=0;

  ll x;
  string s;
  while(++t<=10){
    cin>>n;
    cin>>s;

    fr(i,0,SZ(s)){
      if(s[i]=='(') a[i]=1;
      else a[i]=-1;
    }

    build(1,0,n-1);

    cin>>m;
    cout<<"Test "<<t<<":\n";
    struct Tree ans;
    fr(i,0,m){
      cin>>x;
      if(x) update(1,0,n-1,x-1);
      else{
        ans=query(1,0,n-1,0,n-1);
        if(ans.open==0 && ans.close==0) cout<<"YES\n";
        else cout<<"NO\n";
      }
    }
  }

  return 0;
}
