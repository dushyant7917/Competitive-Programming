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
#define N 1001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool prime[N];

void sieve(){
	MS(prime,true);
	prime[0]=prime[1]=false;

	for(ll i=2;i*i<=N;i++){
		if(prime[i]){
			for(ll j=i*2;j<=N;j+=i){
				prime[j]=false;
			}
		}
	}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	sieve();

	ll n,x;
	cin>>n;

	vector<ll> v;

	fr(i,1,n+1){
		if(prime[i]){
			x=i;
			while(x<=n){
				v.PB(x);
				x*=i;
			}
		}
	}

	cout<<SZ(v)<<"\n";
	fr(i,0,SZ(v)) cout<<v[i]<<" ";

  return 0;
}
