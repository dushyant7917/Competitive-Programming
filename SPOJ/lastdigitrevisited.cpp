#include<iostream>

using namespace std;

typedef long long ll;
#define fr(x,a,b) for(ll x=a;x<b;x++)


ll ME(ll x,ll n,ll p){
  ll ans=1;
  x=x%p;
  while(n>0){
    if(n%2==1) ans=(ans*x)%p;
    n=n/2;
    x=(x*x)%p;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string a;
  ll b;
  while(t--){
    cin>>a>>b;
    cout<<ME(a[a.size()-1]-'0',b,10)<<"\n";
  }

  return 0;
}
