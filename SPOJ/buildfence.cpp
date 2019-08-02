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

  ll l;
  dbl a;
  while(cin>>l && l!=0){
    a=(dbl)(l*l)/(dbl)(2.0*3.14159);
    cout<<fixed<<setprecision(2)<<a<<"\n";
  }

  return 0;
}
