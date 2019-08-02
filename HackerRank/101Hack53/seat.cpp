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

  ll n;
  cin>>n;

  if((n-1)%8==0) cout<<"LB";
  else if((n-4)%8==0) cout<<"LB";
  else if((n-2)%8==0) cout<<"MB";
  else if((n-5)%8==0) cout<<"MB";
  else if((n-3)%8==0) cout<<"UB";
  else if((n-6)%8==0) cout<<"UB";
  else if((n-7)%8==0) cout<<"SLB";
  else if((n-8)%8==0) cout<<"SUB";
  else {}

  return 0;
}
