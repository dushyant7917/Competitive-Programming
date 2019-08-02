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

ll check(string s){
  fr(i,0,SZ(s)-1){
    if((s[i]=='c' && s[i+1]=='h')||(s[i]=='h' && s[i+1]=='e')||(s[i]=='e' && s[i+1]=='f')) return 1;
  }
  
  fr(i,0,SZ(s)-2){
    if((s[i]=='c' && s[i+1]=='h' && s[i+2]=='e')||(s[i]=='h' && s[i+1]=='e' && s[i+2]=='f')) return 1;
  }

  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  string s;
  ll ans=0;
  fr(i,0,n){
    cin>>s;
    ans+=check(s);
  }

  cout<<ans;

  return 0;
}
