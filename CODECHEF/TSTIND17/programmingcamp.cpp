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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,m;
  while(t--){
    cin>>n>>m;
    if(n==1) cout<<0;
    else if(n==2) cout<<m;
    else cout<<((2*m)+n-3);
    cout<<"\n";
  }

  return 0;
}
