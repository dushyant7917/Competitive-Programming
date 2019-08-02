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

bool perfect_square(ll n){
  ll r=sqrt(n);
  return (n==r*r);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  bool flag;
  while(t--){
    cin>>n;

    flag=false;
    for(ll i=0;i*i<=n;i++){
      if(perfect_square(n-(i*i))){
        flag=true;
        break;
      }
    }

    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
  }

  return 0;
}
