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

  ll n,m,a;
  while(t--){
    cin>>n;
    vector<ll> ing[n];
    fr(i,0,n){
      cin>>m;
      fr(j,0,m){
        cin>>a;
        ing[i].PB(a);
      }
    }

    fr(i,0,n){
      sort(ing[i].begin(),ing[i].end());
    }
    ll sum=0;
    fr(i,0,n-1){
      sum+=abs(ing[i][0]-ing[i+1][ing[i+1].size()-1])*(i+1);
    }
    cout<<sum<<"\n";
  }

  return 0;
}
