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

  set<string> st;
  ll n;
  cin>>n;
  string s;
  fr(i,0,n){
    cin>>s;
    ll f[26]={0};
    fr(i,0,SZ(s)) f[s[i]-'a']++;
    string r="";
    fr(i,0,26) if(f[i]) r+=(i+'a');
    st.insert(r);
  }
  cout<<SZ(st);

  return 0;
}
