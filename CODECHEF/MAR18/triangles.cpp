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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(a) a.size()

ll n,q;
ll a[N];

struct Tree{
  vector<ll> v;
};

struct Tree tree[2*N];

bool check(ll x,ll y,ll z){
  if(x+y>z && x+z>y && y+z>x) return true;
  else return false;
}

vector<ll> cal(struct Tree t1,struct Tree t2){
  struct Tree t;
  //cout<<"Calculating...\n";

  ll i=0,j=0;

  while(SZ(t.v)<50 && i<SZ(t1.v) && j<SZ(t2.v)){
    if(t1.v[i]>=t2.v[j]) t.v.PB(t1.v[i++]);
    else t.v.PB(t2.v[j++]);
  }

  while(SZ(t.v)<50 && i<SZ(t1.v) && j==SZ(t2.v)){
    t.v.PB(t1.v[i++]);
  }

  while(SZ(t.v)<50 && i==SZ(t1.v) && j<SZ(t2.v)){
    t.v.PB(t2.v[j++]);
  }

  return t.v;
};

void build(){
  fr(i,n,2*n){
    tree[i].v.PB(a[i-n]);
  }

  for(ll i=n-1;i>=1;i--) tree[i].v=cal(tree[i*2],tree[(i*2)+1]);
}

void update(ll pos,ll val){
  a[pos]=val;
  pos+=n;
  tree[pos].v[0]=val;

  while(pos>1){
    pos=pos/2;
    tree[pos].v=cal(tree[pos*2],tree[(pos*2)+1]);
  }
}

ll query(ll left,ll right){
  struct Tree ans;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      ans.v=cal(ans,tree[left]);
      left++;
    }
    if(right%2==1){
      right--;
      ans.v=cal(ans,tree[right]);
    }
    left=left/2;
    right=right/2;
  }

  if(SZ(ans.v)>=3){
    ll a,b,c;
    fr(i,0,SZ(ans.v)-3+1){
      a=ans.v[i];
      b=ans.v[i+1];
      c=ans.v[i+2];
      if(check(a,b,c)) return (a+b+c);
    }

    return 0;
  }
  else return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q;
  fr(i,0,n) cin>>a[i];

  build();

  ll t,l,r;
  fr(i,0,q){
    cin>>t>>l>>r;
    if(t==1) update(l-1,r);
    else cout<<query(l-1,r)<<"\n";
  }

  return 0;
}
