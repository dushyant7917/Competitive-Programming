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

  ll n,p,l,r,a,b;
  cin>>n>>p>>l>>r;
  a=1;
  b=n;

  ll ans=0;
  if(abs(l-p)<abs(r-p)){
    while(a<l){
      while(p>l){
        p=max(p-1,a);
        ans++;
      }
      while(p<l){
        p=min(p+1,b);
        ans++;
      }
      if(p==l){
        ans++;
        a=l;
      }
    }
    while(b>r){
      while(p<r){
        p=min(p+1,b);
        ans++;
      }
      while(p>r){
        p=max(p-1,a);
        ans++;
      }
      if(p==r){
        ans++;
        b=r;
      }
    }
  }
  else{
    while(b>r){
      while(p<r){
        p=min(p+1,b);
        ans++;
      }
      while(p>r){
        p=max(p-1,a);
        ans++;
      }
      if(p==r){
        ans++;
        b=r;
      }
    }
    while(a<l){
      while(p>l){
        p=max(p-1,a);
        ans++;
      }
      while(p<l){
        p=min(p+1,b);
        ans++;
      }
      if(p==l){
        ans++;
        a=l;
      }
    }
  }

  cout<<ans;

  return 0;
}
