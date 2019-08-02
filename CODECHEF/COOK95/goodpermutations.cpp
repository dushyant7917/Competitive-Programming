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

  ll n,k,ans,cnt,x,ind;
  while(t--){
    cin>>n>>k;

    vector<ll> arr;
    vector<ll> num;
    ll f[n+1]={0};
    ll a[n];

    fr(i,0,n){
      cin>>x;
      arr.PB(x);
      if(x) f[x]=1;
    }

    fr(i,1,n+1) if(!f[i]) num.PB(i);
    sort(num.begin(),num.end());

    ans=0;

    do{
      ind=0;
      fr(i,0,n){
        if(arr[i]) a[i]=arr[i];
        else a[i]=num[ind++];
      }

      cnt=0;
      fr(i,1,n) if(a[i]>a[i-1]) cnt++;
      if(cnt==k) ans++;
    }while(next_permutation(num.begin(),num.end()));

    cout<<ans<<"\n";
  }

  return 0;
}
