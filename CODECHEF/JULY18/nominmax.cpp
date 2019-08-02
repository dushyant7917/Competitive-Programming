//
// reference -> https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
//

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
#define md 1000000006
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 5001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,k;
ll a[N],b[N];
ll ncr[N][N];

void cal(){
  fr(i,0,N) fr(j,0,N) ncr[i][j]=0;

  fr(i,1,N){
    fr(j,0,i+1){
      if(j==0 || j==i) ncr[i][j]=1;
      else ncr[i][j]=((ncr[i-1][j-1]%md)+(ncr[i-1][j]%md))%md;
    }
  }
}

ll power(ll x,ll y){
  ll res=1;
  x=x%mod;

  while(y>0){
    if(y&1) res=((res%mod)*(x%mod))%mod;
    y=y>>1;
    x=((x%mod)*(x%mod))%mod;
  }

  return res;
}

ll A;

ll F(ll i,ll len,ll prd){
  if(i>=n && len<k) return 1;

  if(len==k){
    A=(A*(prd%mod))%mod;
    return prd;
  }

  return F(i+1,len+1,(len>0 && len+1<k)?(prd*(a[i]%mod))%mod:prd)*F(i+1,len,prd);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  cal();

  ll ans;
  while(t--){
    cin>>n>>k;
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);

    b[0]=b[n-1]=0;

    fr(i,1,n-1){
      b[i]=0;
      fr(j,1,k-1){
        b[i]=(b[i]+(ncr[i][j]%md)*(ncr[n-i-1][k-j-1]%md))%md;
      }
    }

    //fr(i,1,n-1) cout<<b[i]<<" "; cout<<"\n";

    ans=1;
    fr(i,1,n-1){
      ans=((ans%mod)*(power(a[i],b[i])%mod))%mod;
    }
    cout<<ans<<"\n";
    //A=1;
    //ans=F(0,0,1);
    //cout<<A<<"\n";
  }

  return 0;
}
