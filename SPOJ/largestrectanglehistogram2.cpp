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

  ll n,ind,max_area,area_top_bar;
  while(cin>>n && n!=0){
    ll a[n];
    fr(i,0,n) cin>>a[i];

    stack<ll> s;
    ll i=0;
    max_area=0;
    while(i<n){
      if(s.empty() || a[i]>=a[s.top()]) s.push(i++);
      else{
        ind=s.top();
        s.pop();
        area_top_bar=a[ind]*(s.empty()?i:i-s.top()-1);
        max_area=max(max_area,area_top_bar);
      }
    }

    while(!s.empty()){
      ind=s.top();
      s.pop();
      area_top_bar=a[ind]*(s.empty()?i:i-s.top()-1);
      max_area=max(max_area,area_top_bar);
    }

    cout<<max_area<<"\n";
  }

  return 0;
}
