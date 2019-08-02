#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll number_of_5s(ll n){
  ll cnt=0;
  while(n%5==0) n/=5,cnt++;
  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll m;
  cin>>m;

  ll x=5,n=0;
  while(1){
    n+=number_of_5s(x);
    if(n==m) break;
    else if(n>m){
      cout<<0;
      return 0;
    }
    else x+=5;
  }

  cout<<5<<"\n";
  fr(i,x,x+5) cout<<i<<" ";

  return 0;
}
