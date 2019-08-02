#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
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

  ll n;
  cin>>n;

  vector<ll> v;
  if(n%4==0){
    cout<<0<<"\n";
    fr(i,1,n+1) if(i%4==0 || i%4==1) v.PB(i);
  }
  else if(n%4==2){
    cout<<1<<"\n";
    fr(i,1,n+1) if(i%4==0 || i%4==1) v.PB(i);
  }
  else if(n%4==3){
    cout<<0<<"\n";
    fr(i,1,n/4+1) v.PB(i);
    fr(i,n-n/4,n+1) v.PB(i);
  }
  else{
    cout<<1<<"\n";
    fr(i,1,n/4+2) v.PB(i);
    fr(i,n-n/4+1,n+1) v.PB(i);
  }

  cout<<v.size()<<" ";
  fr(i,0,SZ(v)) cout<<v[i]<<" ";

  return 0;
}
