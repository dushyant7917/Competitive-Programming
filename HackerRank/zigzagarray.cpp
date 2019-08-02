#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  fr(0,n) cin>>a[i];

  // Method 1 : works in O(nlogn) time
  /*
  sort(a,a+n);

  for(ll i=0;i<=n-2;i+=2){
    swap(a[i],a[i+1]);
  }
  */

  // Method 2: works in O(n) time
  for(ll i=0;i<n;i+=2){
    if(i>0 && a[i-1]>a[i]) swap(a[i],a[i-1]);
    if(i<n-1 && a[i]<a[i+1]) swap(a[i],a[i+1]);
  }

  fr(0,n) cout<<a[i]<<" ";

  return 0;
}
