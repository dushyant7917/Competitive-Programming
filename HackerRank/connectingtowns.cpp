#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ll t,n,nr;
  ll m=1234567;
  cin>>t;
  while(t--){
    cin>>n;
    ll a[n];
    nr=1;
    loop(0,n-1){
      cin>>a[i];
      nr=(nr%m)*(a[i]%m);
    }
    cout<<(nr%m)<<"\n";
  }

  return 0;
}
