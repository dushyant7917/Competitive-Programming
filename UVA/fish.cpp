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

  ll n,r;
  ll x,y;
  char t;
  while(cin>>n>>r && (n && r)){
    vector<pair<dbl,dbl> > a;
    vector<pair<dbl,dbl> > b;

    fr(i,0,n){
      cin>>x>>y>>t;
      if(t=='A'){
        a.PB(MP(x,y));
      }
      else{
        b.PB(MP(x,y));
      }
    }

    

    cout<<a.size()<<" "<<b.size()<<"\n";
  }

  return 0;
}
