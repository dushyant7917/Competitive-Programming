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
  ll t;
  cin>>t;

  ll n,num;
  while(t--){
    cin>>n;

    ll f[200];

    f[0]=1;
    ll num_digits=1,carry,x;
    fr(i,2,n+1){
      carry=0;
      fr(k,0,num_digits){
        x=(f[k]*i+carry);
        f[k]=x%10;
        carry=x/10;
      }
      while(carry){
        f[num_digits++]=carry%10;
        carry=carry/10;
      }
    }

    for(ll i=num_digits-1;i>=0;i--) cout<<f[i];
    cout<<"\n";
  }

  return 0;
}
