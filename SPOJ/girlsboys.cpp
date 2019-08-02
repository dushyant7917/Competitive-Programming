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
#define N 100001

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll g,b;
  ll m,n,ans;
  while(cin>>g>>b && (g!=-1 && b!=-1)){
    if(!g && !b) cout<<0<<"\n";
    else{
      m=max(g,b);
      n=min(g,b);

      ans=m/(n+1);

      if(m%(n+1)) ans++;

      cout<<ans<<"\n";
    }
  }

  return 0;
}
