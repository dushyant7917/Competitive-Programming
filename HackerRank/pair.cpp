#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)
#define loop2(a,b) for(j=a;i<b;j++)

int main(){
  ll n,k;
  cin>>n>>k;
  ll cnt=0,a[n];
  loop(0,n){
    cin>>a[i];
  }
  sort(a,a+n);
  loop(0,n){
    if(binary_search(a,a+n,a[i]+k)){
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}
