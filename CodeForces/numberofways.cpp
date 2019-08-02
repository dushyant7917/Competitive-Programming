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
	ll a[n],cnt[n]={0};

	ll sum=0;
	fr(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}

	if(sum%3!=0) cout<<0;
	else{
		sum/=3;
		ll s=0;
		for(ll i=n-1;i>=0;i--){
			s+=a[i];
			if(s==sum) cnt[i]=1;
		}
		for(ll i=n-2;i>=0;i--) cnt[i]+=cnt[i+1];
		ll ans=0;
		s=0;
		for(ll i=0;i+2<n;i++){
			s+=a[i];
			if(s==sum){
				ans+=cnt[i+2];
			}
		}
		cout<<ans;
	}

  return 0;
}
