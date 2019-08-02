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

  ll n,d;
  cin>>n>>d;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  ll msv[n],mv=-INF;
  msv[n-1]=0;
  for(ll i=n-2;i>=0;i--){
    if(a[i+1]>=0) msv[i]=msv[i+1]+a[i+1];
    else msv[i]=0;
    mv=max(mv,msv[i]);
  }

  if(a[0]>d){
    cout<<-1;
    return 0;
  }

  ll cb=a[0];
  ll cnt=0;

  fr(i,1,n){
    if(a[i]==0 && cb<0){
      if(abs(cb-0)>d){
        cout<<-1;
        return 0;
      }
      else{
        cb+=(d-mv-cb);
        cnt++;
      }
    }
    else{
      cb+=a[i];
      if(cb>d){
        cout<<-1;
        return 0;
      }
    }
  }

  cout<<cnt;

  return 0;
}
