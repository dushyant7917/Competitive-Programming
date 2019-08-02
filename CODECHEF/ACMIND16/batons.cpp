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

  ll n,m;
  cin>>n>>m;

  ll s[n],p[m];
  fr(i,0,n) cin>>s[i];
  fr(i,0,m) cin>>p[i];

  ll cnt,ans=0;
  fr(i,0,n){
    cnt=0;
    fr(j,0,m){
      if(s[p[j]]==1) cnt++;
      p[j]=(p[j]+1)%n;
    }
    if(cnt==m) ans++;
  }

  cout<<ans;

  return 0;
}
