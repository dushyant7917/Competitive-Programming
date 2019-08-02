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

ll n;
ll a[100];
ll b[100];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;

  ll cnt=0;
  fr(i,0,n){
    cin>>a[i];
    if(a[i]) b[i]=-1,cnt++;
    else b[i]=1;
  }

  ll m,cm;
  cm=m=b[0];
  fr(i,1,n){
    cm=max(cm+b[i],b[i]);
    m=max(m,cm);
  }

  cout<<cnt+m;

  return 0;
}
