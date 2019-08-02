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

  ll n,p,sum,k=1,cnt;
  while(t--){
    cin>>n>>p;
    ll a[p];
    fr(i,0,p) cin>>a[i];

    sort(a,a+p);

    sum=0;
    cnt=0;
    for(ll i=p-1;i>=0;i--){
      sum+=a[i];
      cnt++;
      if(sum>=n) break;
    }

    if(sum>=n) cout<<"Scenario #"<<(k++)<<":\n"<<cnt<<"\n";
    else cout<<"Scenario #"<<(k++)<<":\nimpossible\n";
  }

  return 0;
}
