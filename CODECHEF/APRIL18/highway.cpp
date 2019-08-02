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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  dbl s,y,mn=0.000001,tm;
  while(t--){
    cin>>n>>s>>y;

    dbl v[n],d[n],p[n],c[n];

    fr(i,0,n) cin>>v[i];
    fr(i,0,n) cin>>d[i];
    fr(i,0,n) cin>>p[i];
    fr(i,0,n) cin>>c[i];

    tm=0.0;

    fr(i,0,n){
      if(d[i]){
        p[i]+=v[i]*tm;

        if(p[i]-c[i]>=0) tm+=(y/s);
        else if(p[i]>=0 && p[i]-c[i]<0) tm+=(abs(p[i]-c[i])/v[i])+(y/s);
        else if(p[i]<0 && ((abs(p[i])-mn)/v[i])<(y/s)) tm+=(abs(p[i]-c[i])/v[i])+(y/s);
        else tm+=(y/s);
      }

      else{
        p[i]-=v[i]*tm;

        if(p[i]+c[i]<=0) tm+=(y/s);
        else if(p[i]<=0 && p[i]+c[i]>0) tm+=(abs(p[i]+c[i])/v[i])+(y/s);
        else if(p[i]>0 && ((abs(p[i])-mn)/v[i])<(y/s)) tm+=(abs(p[i]+c[i])/v[i])+(y/s);
        else tm+=(y/s);
      }
    }

    cout<<fixed<<setprecision(6)<<tm<<"\n";
  }

  return 0;
}
