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
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll cnt=0,prv=0;
  fr(i,0,n){
    if(!a[i]){
      cnt++;
      prv=0;
    }
    else if(a[i]==3){
      prv=3-prv;
    }
    else if(prv==1 && a[i]==1){
      cnt++;
      prv=0;
    }
    else if(prv==2 && a[i]==2){
      cnt++;
      prv=0;
    }
    else{
      prv=a[i];
    }
  }

  cout<<cnt;

  return 0;
}
