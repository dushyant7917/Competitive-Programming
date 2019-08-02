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

ll bs(ll v[],ll n,ll x){
  ll l=0,r=n-1,m;

  while(l<=r){
    m=(l+r)/2;
    if(v[m]==x) return m;
    else if(v[m]>x) r=m-1;
    else l=m+1;
  }

  return -1;
}

ll cal(ll v[],ll l,ll r){
  ll sum=0;

  fr(i,l,r+1){
    sum+=v[i];
  }

  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll p,ans,l1,r1,l2,r2;
  ll n1,n2;
  while(cin>>n1  && n1!=0){
    ll a[n1];
    fr(i,0,n1) cin>>a[i];

    cin>>n2;
    ll b[n2];
    fr(i,0,n2) cin>>b[i];

    vector<ll> ips;
    fr(i,0,n1){
      p=bs(b,n2,a[i]);
      if(p!=-1) ips.PB(a[i]);
    }

    l1=0;
    l2=0;
    ans=0;
    fr(i,0,ips.size()){
      r1=bs(a,n1,ips[i]);
      r2=bs(b,n2,ips[i]);
      ans+=max(cal(a,l1,r1),cal(b,l2,r2));
      l1=r1+1;
      l2=r2+1;
    }

    ans+=max(cal(a,l1,n1-1),cal(b,l2,n2-1));
    cout<<ans<<"\n";
  }

  return 0;
}
