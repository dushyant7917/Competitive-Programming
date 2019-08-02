#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)
#define m 100000

int main(){
  ll t,n;
  cin>>t;
  ll a,b;
  while(t--){
    cin>>n;
    a=1;
    loop(0,n){
      a=((a%m)*(2%m))%m;
      //Below line is less efficient
      //a=(a%m)*(2%m);
    }
    cout<<(a-1)<<"\n";
    //cout<<(a-1)%m<<"\n";
  }
  return 0;
}
