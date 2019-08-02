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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    if(n%4==0) cout<<(n/4);
    else if(n%4==1){
      if(n<9) cout<<-1;
      else cout<<1+(n-9)/4;
    }
    else if(n%4==2){
      if(n<6) cout<<-1;
      else cout<<1+(n-6)/4;
    }
    else{
      if(n<15) cout<<-1;
      else cout<<2+(n-15)/4;
    }

    cout<<"\n";
  }

  return 0;
}
