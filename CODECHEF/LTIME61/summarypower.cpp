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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,k,steps,ans;
  string s;
  while(t--){
    cin>>n>>k>>s;

    steps=n-k+1;
    ll diff[n]={0};

    fr(i,1,SZ(s)){
      if(s[i]==s[i-1]) diff[i]=0;
      else diff[i]=1;
    }

    fr(i,1,SZ(s)) diff[i]+=diff[i-1];

    ans=0;
    fr(i,0,k) ans+=diff[i+steps-1]-diff[i];
    cout<<ans<<"\n";
  }

  return 0;
}
