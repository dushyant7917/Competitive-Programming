#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
  string an;
  while(t--){
    cin>>n;

    cin.ignore();

    set<string> s;
    set<string>::iterator itr;
    map<string,ll> mp;

    fr(i,0,n){
      getline(cin,an);
      mp[an]++;
      s.insert(an);
    }

    for(itr=s.begin();itr!=s.end();itr++){
      cout<<(*itr)<<" "<<mp[*itr]<<"\n";
    }
    cout<<"\n";
  }

  return 0;
}
