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

struct Num{
  ll num;
  ll ones;
};

bool cmp(struct Num x,struct Num y){
  return x.ones>y.ones;
}

ll num_ones(ll n){
  ll cnt=0;

  while(n){
      n=n&(n-1);
      cnt++;
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,k;
  while(t--){
    cin>>n>>k;

    struct Num a[n];
    fr(i,0,n){
      cin>>a[i].num;
      a[i].ones=num_ones(a[i].num);
    }

    sort(a,a+n,cmp);

    ll num_cakes=0;
    fr(i,0,k){
      num_cakes+=a[i].ones;
    }
    cout<<num_cakes<<"\n";
  }

  return 0;
}
