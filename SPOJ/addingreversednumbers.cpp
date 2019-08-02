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

ll rev_num(ll n){
  ll r=0;
  while(n){
    r=(n%10)+(r*10);
    n/=10;
  }
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n1,n2;
  while(t--){
    cin>>n1>>n2;
    cout<<rev_num(rev_num(n1)+rev_num(n2))<<"\n";
  }

  return 0;
}
