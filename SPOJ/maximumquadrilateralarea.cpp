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
  ll t;
  cin>>t;

  dbl a,b,c,d,s,area;
  while(t--){
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/2;
    area=sqrt((s-a)*(s-b)*(s-c)*(s-d));
    cout<<fixed<<setprecision(2)<<area<<"\n";
  }

  return 0;
}
