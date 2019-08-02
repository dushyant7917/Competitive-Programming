#include<bits/stdc++.h>

using namespace std;

typedef int ll;
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
  ll a[n+1];
  fr(i,0,n) cin>>a[i];
  a[n]=-1;

  ll cl,ml;
  cl=ml=1;
  fr(i,1,n+1){
    if(a[i]>a[i-1]) cl++;
    else{
      ml=max(ml,cl);
      cl=1;
    }
  }

  cout<<ml;

  return 0;
}
