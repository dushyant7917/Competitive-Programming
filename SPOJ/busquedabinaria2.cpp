#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define K 1000000007

ll n,t;

ll bs(ll a[], ll x){
  ll l=0,r=n-1,m;

  ll pos=-1;

  while(l<=r){
    m=(l+r)/2;
    if(a[m]==x) pos=m,l=m+1;
    else if(x<a[m]) r=m-1;
    else l=m+1;
  }

  return pos;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>t;

  ll a[n];
  fr(0,n)cin>>a[i];

  ll x;
  while(t--){
    cin>>x;
    cout<<bs(a,x)<<"\n";
  }

  return 0;
}
