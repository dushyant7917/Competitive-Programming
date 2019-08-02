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

ll fact[19];

void cal(){
  fact[1]=1;
  fr(i,2,19) fact[i]=fact[i-1]*i;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin>>s;

  ll f[10]={0};
  fr(i,0,SZ(s)) f[s[i]-'0']++;

  ll ans=0,den;
  fr(i,0,10){
    if(!f[i]) continue;

    den=1;
    fr(j,0,10) if(j!=i) den*=f[j];

    fr(j,1,f[i]+1){
      den*=(f[i]-j>0)?(f[i]-j):(1);
      
    }
  }

  return 0;
}
