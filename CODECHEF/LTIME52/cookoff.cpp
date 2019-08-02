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

  ll t;
  cin>>t;

  ll n;
  string s;
  ll cc,cs,ce,cem_m,cmh_h;
  while(t--){
    cin>>n;
    cc=cs=ce=cem_m=cmh_h=0;
    fr(i,0,n){
      cin>>s;
      if(s=="cakewalk") cc++;
      if(s=="simple") cs++;
      if(s=="easy") ce++;
      if(s=="easy-medium"||s=="medium") cem_m++;
      if(s=="medium-hard"||s=="hard") cmh_h++;
    }
    if(cc>0 && cs>0 && ce>0 && cem_m>0 && cmh_h>0) cout<<"Yes\n";
    else cout<<"No\n";
  }

  return 0;
}
