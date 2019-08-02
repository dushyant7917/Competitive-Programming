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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    string a[n];
    map<string,ll> mp;
    ll mv=0;
    fr(i,0,n){
      cin>>a[i];
      mp[a[i]]++;
      mv=max(mv,mp[a[i]]);
    }
    set<string> team;
    set<string>::iterator itr;
    fr(i,0,n){
      if(mp[a[i]]==mv){
        team.insert(a[i]);
      }
    }
    if(team.size()==1){
      itr=team.begin();
      cout<<(*itr)<<"\n";
    }
    else cout<<"Draw\n";
  }

  return 0;
}
