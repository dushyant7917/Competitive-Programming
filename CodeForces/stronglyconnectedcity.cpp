#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
string h,v;

bool cycle(){
  if(h[0]=='>' && h[n-1]=='<' && v[0]=='^' && v[m-1]=='v') return true;
  else if(h[0]=='<' && h[n-1]=='>' && v[0]=='v' && v[m-1]=='^') return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  cin>>h>>v;

  if(cycle()) cout<<"YES";
  else cout<<"NO";

  return 0;
}
