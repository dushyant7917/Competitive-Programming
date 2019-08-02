#include<iostream>
#include<map>
#include<unordered_set>
using namespace std;
typedef unsigned long long ll;
#define fr(x,a,b) for(ll x=a;x<b;x++)

ll mod_power(ll x,ll y){
  ll res=1;

  while(y>0){
    if (y%2==1)
        res=((res%10)*(x%10))%10;

    y=y>>1;
    x=((x%10)*(x%10))%10;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;
  ll x,y;
  while(t--){
    cin>>x>>y;
    cout<<mod_power(x,y)%10<<"\n";
  }
  return 0;
}
