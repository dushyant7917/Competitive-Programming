#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k=2;
  cin>>n;
  ll a[n];

  loop(0,n){
    cin>>a[i];
  }

  sort(a,a+n);

  ll abs_min=abs(a[0]-a[1]);
  loop(2,n){
    abs_min=min(abs(a[i]-a[i-1]),abs_min);
  }

  cout<<abs_min;
  return 0;
}
