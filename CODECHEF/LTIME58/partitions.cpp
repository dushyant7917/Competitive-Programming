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

  ll n,sum,cnt,s,j;
  while(t--){
    cin>>n;
    ll a[n+1],ans[n+1]={0};
    sum=0;
    fr(i,1,n+1){
      cin>>a[i];
      sum+=a[i];
    }

    fr(i,1,n+1){
      if(sum%i!=0) continue;
      j=1;
      cnt=0;
      s=0;
      while(j<=n){
        s+=a[j];
        if(s>sum/i) break;
        if(s==sum/i){
          cnt++;
          s=0;
        }
        j++;
      }
      if(j==n+1 && cnt==i) ans[i]=1;
    }

    fr(i,1,n+1) cout<<ans[i];

    cout<<"\n";
  }

  return 0;
}
