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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll num=n,k,m;
  ll d,ld=0;
  while(n>0){
    d=n%10;
    n/=10;
    ld=max(ld,d);
  }

  cout<<ld<<"\n";

  n=num;
  while(n>0){
    m=0;
    k=1;
    num=n;
    while(n>0){
      d=n%10;
      n/=10;
      m+=(k)*((d==0)?0:1);
      k*=10;
    }
    cout<<m<<"\n";
    n=num-m;
  }

  return 0;
}
