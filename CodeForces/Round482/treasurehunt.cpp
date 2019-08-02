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
#define INF 2e10
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string a,b,c;
  cin>>a>>b>>c;

  ll x=SZ(a);

  ll ma=0,mb=0,mc=0;
  map<char,ll> fa,fb,fc;

  fr(i,0,x){
    fa[a[i]]++;
    fb[b[i]]++;
    fc[c[i]]++;
    ma=max(ma,fa[a[i]]);
    mb=max(mb,fb[b[i]]);
    mc=max(mc,fc[c[i]]);
  }

  if(n==1){
    ma++;
    mb++;
    mc++;
    if(ma>x) ma=x-1;
    if(mb>x) mb=x-1;
    if(mc>x) mc=x-1;
  }
  else{
    ma=min(ma+n,x);
    mb=min(mb+n,x);
    mc=min(mc+n,x);
  }

  if(ma>mb && ma>mc) cout<<"Kuro";
  else if(mb>ma && mb>mc) cout<<"Shiro";
  else if(mc>mb && mc>ma) cout<<"Katie";
  else cout<<"Draw";

  return 0;
}
