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

  ll n;
  cin>>n;
  ll a[n];

  ll p1=1,p2=2,s=3;
  fr(i,0,n) cin>>a[i];

  fr(i,0,n){
    if(a[i]==s){
      cout<<"NO";
      return 0;
    }
    else{
      if(a[i]==p1) swap(p2,s);
      else swap(p1,s);
    }
  }

  cout<<"YES";

  return 0;
}
