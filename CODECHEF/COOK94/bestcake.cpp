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

  ll n,k,x,num;
  while(t--){
    cin>>n>>k;

    x=(ll)floor(log2(k))+1;
    num=1<<(ll)(log2(k));

    if(n==1) cout<<k;
    else if(k==1) fr(i,0,n) cout<<1<<" ";
    else if(k==2){
      cout<<2<<" ";
      fr(i,1,n) cout<<1<<" ";
    }
    else if(k==3){
      if(n&1) cout<<3<<" ";
      else cout<<2<<" ";
      fr(i,1,n) cout<<1<<" ";
    }
    else{
      if(n&1){
        cout<<num<<" "<<num-2<<" ";
        fr(i,2,n) cout<<1<<" ";
      }
      else{
        cout<<num<<" "<<num-1<<" ";
        fr(i,2,n) cout<<1<<" ";
      }
    }

    cout<<"\n";
  }

  return 0;
}
