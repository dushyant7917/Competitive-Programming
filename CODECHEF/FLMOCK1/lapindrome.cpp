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
    cin>>s;
    ll f1[26]={0},f2[26]={0};
    fr(i,0,s.size()/2){
      f1[s[i]-'a']++;
    }
    fr(i,(s.size()%2==0)?(s.size()/2):((s.size()/2)+1),s.size()){
      f2[s[i]-'a']++;
    }
    bool flag=true;
    fr(i,0,26){
      if(f1[i]!=f2[i]){
        flag=false;
        break;
      }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
