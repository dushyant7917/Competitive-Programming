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

    if(s.size()<3) cout<<0;
    else{
      ll unique[s.size()];
      ll cnt=0;
      map<char,ll> mp;
      for(ll i=s.size()-1;i>=0;i--){
        mp[s[i]]++;
        if(mp[s[i]]==1){
          unique[i]=++cnt;
        }
        else unique[i]=cnt;
      }

      ll ans=0;
      ll two_char[26][26]={0};
      fr(i,0,s.size()-2){
        fr(j,i+1,s.size()-1){
          two_char[s[i]-'A'][s[j]-'A']++;
          if(two_char[s[i]-'A'][s[j]-'A']==1){
            ll k=j+1;
            ans+=unique[k];
          }
        }
      }
      cout<<ans;
    }
    cout<<"\n";
  }

  //cout<<"Executed in "<< clock() / CLOCKS_PER_SEC<<" sec"<<"\n";

  return 0;
}
