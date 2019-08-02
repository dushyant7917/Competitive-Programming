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

  string s;
  cin>>s;

  vector<ll> f[26];
  fr(i,0,s.size()){
    f[s[i]-'a'].PB(i);
  }

  ll m;
  cin>>m;

  ll p;
  char c;
  fr(i,0,m){
    cin>>p>>c;
    cout<<f[c-'a'][p-1]<<"\n";
    s[f[c-'a'][p-1]]='.';
  }

  cout<<s<<"\n";

  return 0;
}
