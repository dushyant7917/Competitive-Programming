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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll d,ans;
  // We are going upto k<=10 only because after that d > (10^5) [see constraints in the question]
  fr(k,1,10){
    d=((1<<k)-1)*(1<<(k-1));
    if(n%d==0) ans=d;
  }

  cout<<ans;

  return 0;
}
