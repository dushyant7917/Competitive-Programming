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

  ll n;
  while(t--){
    cin>>n;
		ll a[n];

		fr(i,0,n) cin>>a[i];

		ll ans=0,sum,prd;
		fr(i,0,n){
			sum=0;
			prd=1;
			fr(j,i,n){
				sum=((sum%mod)+(a[j]%mod))%mod;
				prd=((prd%mod)*(a[j]%mod))%mod;
				if(sum==prd) ans++;
			}
		}

		cout<<ans<<"\n";
  }

  return 0;
}