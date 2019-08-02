#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

ll number_trailing_zeroes(ll n){
  ll num=0;
  while(n>=5){
    num+=n/5;
    n/=5;
  }

  return num;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    cout<<number_trailing_zeroes(n)<<"\n";
  }

  return 0;
}
