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

ll n,q;
ll c,x,y;
ll a[N]={0};
ll BIT[N]={0};

void update(ll pos,ll val){
  while(pos<=n){
    BIT[pos]+=val;
    pos+=(pos)&(-pos);
  }
}

ll query(ll pos){
  ll sum=0;
  while(pos>0){
    sum+=BIT[pos];
    pos-=(pos)&(-pos);
  }
  return sum;
}

void pa(){
  fr(i,1,n+1){
    cout<<i<<":"<<a[i]<<"\n";
  }
}

void pb(){
  fr(i,1,n+1){
    cout<<i<<":"<<BIT[i]<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  fr(i,1,n+1){
    cin>>a[i];
    update(i,a[i]%2);
  }

  cin>>q;

  fr(i,0,q){
    cin>>c>>x>>y;
    if(c==0){
      if(a[x]%2==1 && y%2==0) update(x,-1);
      if(a[x]%2==0 && y%2==1) update(x,1);
      a[x]=y;
    }
    else if(c==1){
      ll cnt=query(y)-query(x-1);
      cout<<(y-x+1)-cnt<<"\n";
    }
    else{
      ll cnt=query(y)-query(x-1);
      cout<<cnt<<"\n";
    }
  }

  return 0;
}
