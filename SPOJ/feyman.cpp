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

  ll ns[101];
  ns[0]=0;
  fr(i,1,101){
    ns[i]=(i*i)+ns[i-1];
  }

  ll n;
  while(cin>>n && n){
    cout<<ns[n]<<"\n";
  }

  return 0;
}
