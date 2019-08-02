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
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  dbl d,D,a,b;
  while(t--){
    cin>>d;

    if(d==0.0) cout<<"Y "<<fixed<<setprecision(9)<<0.0<<" "<<0.0<<"\n";
    else if(d<4.0) cout<<"N\n";
    else{
      D=sqrt((d*d)-(4.0*d));
      a=(d+D)/2.0;
      b=(d-D)/2.0;
      cout<<"Y "<<fixed<<setprecision(9)<<a<<" "<<b<<"\n";
    }
  }

  return 0;
}
