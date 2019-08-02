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

  ll a1,a2,a3;

  while(cin>>a1>>a2>>a3 && !(a1==0 && a2==0 && a3==0)){
    if(a3-a2==a2-a1) cout<<"AP "<<a3+(a3-a2);
    else cout<<"GP "<<a3*(a3/a2);
    cout<<"\n";
  }

  return 0;
}
