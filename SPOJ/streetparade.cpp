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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  while(cin>>n && n!=0){
    ll a[n];
    fr(i,0,n) cin>>a[i];

    ll need=1;
    stack<ll> side_lane;
    bool ans=true;

    fr(i,0,n){
      while(!side_lane.empty() && side_lane.top()==need){
        need++;
        side_lane.pop();
      }

      if(a[i]==need) need++;
      else if(!side_lane.empty() && a[i]>=side_lane.top()){
        ans=false;
        break;
      }
      else{
        side_lane.push(a[i]);
      }
    }

    if(ans) cout<<"yes\n";
    else cout<<"no\n";
  }

  return 0;
}
