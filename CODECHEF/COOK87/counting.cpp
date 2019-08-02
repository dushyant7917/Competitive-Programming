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
  while(t--){
    cin>>s;

    ll ans=0;

    ll cnt=1;
    ll prv=-1;
    ll si=0,ei;
    fr(i,0,s.size()+1){
      if(s[i]==prv){
        cnt++;
      }
      else{
        ei=i-1;
        ans+=(cnt*(cnt-1))/2;
        cnt=1;
        if(si>0 && ei<s.size()-1 && s[si-1]==s[ei+1]) ans++;
        si=i;
      }
      prv=s[i];
    }

    cout<<ans<<"\n";
  }

  return 0;
}
