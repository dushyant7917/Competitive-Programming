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

  ll n,m,b,g,x;
  cin>>n>>m;

  ll boy[n]={0},girl[m]={0};

  cin>>b;
  fr(i,0,b) cin>>x,boy[x]=1;

  cin>>g;
  fr(i,0,g) cin>>x,girl[x]=1;

  fr(i,0,10001) if(boy[i%n] || girl[i%m]) boy[i%n]=girl[i%m]=1;

  fr(i,0,n){
    if(!boy[i]){
      cout<<"No";
      return 0;
    }
  }

  fr(i,0,m){
    if(!girl[i]){
      cout<<"No";
      return 0;
    }
  }

  cout<<"Yes";

  return 0;
}
