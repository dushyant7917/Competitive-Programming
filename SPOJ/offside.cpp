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

  ll a,d;
  ll ma;
  while(cin>>a>>d && (a!=0 && d!=0)){
    ll b[a],c[d];

    ma=10000;
    fr(i,0,a){
      cin>>b[i];
      ma=min(ma,b[i]);
    }
    fr(i,0,d){
      cin>>c[i];
    }

    sort(c,c+d);

    if(ma>=c[1]) cout<<"N\n";
    else if(c[0]==c[1] && ma>=c[0]) cout<<"N\n";
    else cout<<"Y\n";
  }

  return 0;
}
