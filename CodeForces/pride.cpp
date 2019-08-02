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

  ll n,cnt=0,len=INF;
  cin>>n;
  ll a[n];
  fr(i,0,n){
    cin>>a[i];
    if(a[i]==1) cnt++;
  }

  ll hcf=a[0];
  fr(i,1,n) hcf=__gcd(hcf,a[i]);

  if(hcf!=1) cout<<-1;
  else{
    if(cnt) cout<<n-cnt;
    else{
      fr(i,0,n){
        hcf=a[i];
        fr(j,i+1,n){
          hcf=__gcd(hcf,a[j]);
          if(hcf==1){
            len=min(len,j-i+1);
            break;
          }
        }
      }
      cout<<(len-1)+(n-1);
    }
  }

  return 0;
}
