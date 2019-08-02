#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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

  ll t,k;
  cin>>t;
  while(t--){
    cin>>k;
    cout<<192+((k-1)*250)<<"\n";
  }

  return 0;
}
