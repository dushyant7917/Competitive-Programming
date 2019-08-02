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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define sz(s) s.size()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n;

  ll v[n+1],u[n+1];
  fr(i,1,n+1){
    cin>>v[i];
    u[i]=v[i];
  }
  v[0]=u[0]=0;

  sort(u,u+n+1);

  fr(i,1,n+1){
    v[i]+=v[i-1];
    u[i]+=u[i-1];
  }

  cin>>m;
  ll t,l,r;
  fr(i,0,m){
    cin>>t>>l>>r;
    if(t==1) cout<<v[r]-v[l-1]<<"\n";
    else cout<<u[r]-u[l-1]<<"\n";
  }

  return 0;
}
