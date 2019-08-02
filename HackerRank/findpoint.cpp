#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  ll n,x1,x2,x3,y1,y2,y3;
  cin>>n;
  while(n--){
    cin>>x1>>y1>>x2>>y2;
    x3=2*x2-x1;
    y3=2*y2-y1;
    cout<<x3<<" "<<y3<<"\n";
  }
  return 0;
}
