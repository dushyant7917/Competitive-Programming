#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];

  fr(i,0,n) cin>>a[i];

  ll prv=gmin,cnt=0,ans=1;
  fr(i,0,n){
    if(a[i]>=prv && i<n-1) cnt++;
    else if(a[i]>=prv && i==n-1){
      cnt++;
      ans=max(ans,cnt);
    }
    else{
      ans=max(ans,cnt);
      cnt=1;
    }
    prv=a[i];
  }

  cout<<ans;

  return 0;
}
