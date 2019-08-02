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
  ll t;
  cin>>t;

  ll TT,TLT,sum;
  ll a,n,d;
  while(t--){
    cin>>TT>>TLT>>sum;
    n=(2*sum)/(TT+TLT);
    d=(TT-TLT)/(n-5);
    a=TLT-(2*d);
    cout<<n<<"\n";
    fr(i,1,n+1){
      cout<<a+((n-i)*d)<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
