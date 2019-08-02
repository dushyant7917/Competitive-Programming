#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  cin.ignore();
  string s;
  while(t--){
    cin>>s;

    // O(n) solution
    bool flag=false;
    ll f[26]={};

    fr(i,0,s.size()){
      f[s[i]-'a']++;
      if(f[s[i]-'a']>1){
        flag=true;
        cout<<"yes\n";
        break;
      }
    }
    if(!flag) cout<<"no\n";
  }

  return 0;
}
