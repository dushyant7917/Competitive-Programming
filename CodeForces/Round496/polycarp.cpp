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

  string s;
  cin>>s;
  s='0'+s;

  ll dp[SZ(s)]={0};
  dp[0]=1;

  ll ind,sum;

  fr(i,1,SZ(s)){
    if((s[i]-'0')%3==0) dp[i]=1;

    else{
      sum=s[i]-'0';
      ind=i-1;
      while(dp[ind]!=1){
        sum+=s[ind]-'0';
        if(sum%3==0){
          dp[i]=1;
          break;
        }
        ind--;
      }
    }
  }

  ll ans=0;
  fr(i,1,SZ(s)) if(dp[i]) ans++;
  cout<<ans;

  return 0;
}
