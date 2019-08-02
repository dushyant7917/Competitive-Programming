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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string s;
  ll n,m;
  while(t--){
    cin>>s;
    cin>>n>>m;

    char a[s.size()];
    fr(i,0,s.size()) a[i]=s[i];

    sort(a+n,a+n+m,greater<char>());

    fr(i,0,s.size()) cout<<a[i];
    cout<<"\n";
  }

  return 0;
}
