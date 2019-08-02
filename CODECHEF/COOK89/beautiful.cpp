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

  ll n,ans,sum;
  while(t--){
    cin>>n;
    ll a[n];
    ll f1,f2,f3;
    f1=f2=f3=0;
    sum=0;
    fr(i,0,n){
      cin>>a[i];
      sum+=a[i];
      if(a[i]%4==1) f1++;
      if(a[i]%4==2) f2++;
      if(a[i]%4==3) f3++;
    }

    if(sum%4!=0) cout<<-1<<"\n";
    else{
      ans=0;
      ans+=min(f1,f3);
      f1-=ans;
      f3-=ans;
      ans+=f2/2;
      f2=f2%2;
      if(f2>0 && f1>=2){
        ans+=2;
        f2=0;
        f1-=2;
      }
      if(f2>0 && f3>=2){
        ans+=2;
        f2=0;
        f3-=2;
      }
      if(f1>0) ans+=(f1/4)*3;
      if(f3>0) ans+=(f3/4)*3;

      cout<<ans<<"\n";
    }
  }

  return 0;
}
