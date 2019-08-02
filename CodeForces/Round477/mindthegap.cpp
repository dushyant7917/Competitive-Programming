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

  ll n,s;
  cin>>n>>s;

  ll a[n],h,m;
  fr(i,0,n){
    cin>>h>>m;
    a[i]=h*60+m;
  }

  ll tm=0;
  bool flag;
  
  while(tm<=1500){
    flag=true;
    fr(i,0,n){
      if(abs(a[i]-tm)<=s){
        flag=false;
        break;
      }
    }
    if(flag){
      cout<<tm/60<<" "<<tm%60;
      break;
    }
    tm++;
  }

  return 0;
}
