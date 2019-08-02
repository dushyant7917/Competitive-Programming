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

  ll n=14;
  ll a[n],b[n];
  fr(i,0,n){
    cin>>a[i];
    b[i]=a[i];
  }

  ll ans=0,x,cnt,left,f,r;
  fr(i,0,n){
    if(!a[i]) continue;

    x=a[i];
    b[i]=cnt=0;

    if(i+x>=n){
      fr(j,i+1,n) b[j]++;
      left=x-(n-i)+1;
      if(left<=14) fr(j,0,x-(n-i)+1) b[j]++;
      else{
        f=left/14;
        r=left%14;
        fr(j,0,n) b[j]+=f;
        fr(j,0,r) b[j]++;
      }
    }

    else fr(j,i+1,i+x+1) b[j]++;

    fr(j,0,n) if(b[j]%2==0) cnt+=b[j];

    ans=max(ans,cnt);

    fr(j,0,n) b[j]=a[j];
  }

  cout<<ans;

  return 0;
}
