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

  ll n;
  string s;
  while(t--){
    cin>>n>>s;

    ll cnt=0;
    fr(i,0,s.size()) if(s[i]=='1') cnt++;
    cout<<cnt+((cnt*(cnt-1))/2)<<"\n";
  }

  return 0;
}
