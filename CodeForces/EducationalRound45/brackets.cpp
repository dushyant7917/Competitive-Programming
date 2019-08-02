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
#define N 300001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll open[N],close[N];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string s;
  ll l,r;
  fr(i,0,n){
    cin>>s;

    l=r=0;
    fr(j,0,SZ(s)){
      if(s[j]=='(') l++;
      else{
        if(l) l--;
        else r++;
      }
    }

    if(!l) close[r]++;
    if(!r) open[l]++;
  }

  ll ans=0;
  fr(i,0,N) ans+=open[i]*close[i];
  cout<<ans;

  return 0;
}
