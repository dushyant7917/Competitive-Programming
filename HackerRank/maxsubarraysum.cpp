#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

ll subarray_sum(ll i,ll j,ll b[]){
  ll sum=(i>0)?b[j]-b[i-1]:b[j];
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n,m;
  while(t--){
    cin>>n>>m;

    ll a[n],b[n];
    fr(0,n) {
      cin>>a[i];
      a[i]=a[i]%m;
    }

    ll prv=0;
    fr(0,n){
      b[i]=(a[i]+prv)%m;
      prv=b[i];
    }

    sort(b,b+n);
    ll lb=lower_bound(b,b+n,m)-b;
    cout<<b[lb-1]<<"\n";

  }

  return 0;
}
