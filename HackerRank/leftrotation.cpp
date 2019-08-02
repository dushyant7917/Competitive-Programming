#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)

int main(){
  ll n,d,nr;
  cin>>n>>d;
  nr=d%n;

  ll a[n];
  fr(0,n){
    cin>>a[i];
  }

  fr(nr,n){
    cout<<a[i]<<" ";
  }
  fr(0,nr){
    cout<<a[i]<<" ";
  }

  return 0;
}
