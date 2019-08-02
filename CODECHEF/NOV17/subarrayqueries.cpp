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
#define N 500001

ll n,q,L,R;
ll a[N]={0};
ll BIT[N]={0};

void update(ll pos,ll val){
  while(pos<=n){
    BIT[pos]=max(BIT[pos],val);
    pos+=(pos)&(-pos);
  }
}

ll query(ll pos){
  ll me=0;
  while(pos>0){
    me=max(me,BIT[pos]);
    pos-=(pos)&(-pos);
  }
  return me;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>q>>L>>R;

  ll ty,x,y,l,r;
  while(q--){
    cin>>ty;
    if(ty==1){
      cin>>x>>y;
      update(x,y);
      a[x]=y;
    }
    else{
      cin>>l>>r;
      cout<<max(query(r),query(l-1))<<"\n";
    }
  }

  return 0;
}
