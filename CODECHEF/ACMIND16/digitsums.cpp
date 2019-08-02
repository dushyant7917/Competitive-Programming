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

ll ds(ll n){
  ll sum=0;
  while(n){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

map<ll,ll> mp;
ll dp[100001];

void init(ll n){
  fr(i,1,100001){
    if(!mp[ds(i)]){
      mp[ds(i)]=i;
    }
    dp[i]=ds(i);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  init(100000);

  ll n;
  while(t--){
    cin>>n;
    cout<<dp[mp[dp[n]]+1]<<"\n";
  }

  return 0;
}
