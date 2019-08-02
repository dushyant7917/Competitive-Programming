#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll x1,y1,x2,y2;
  while(t--){
    cin>>x1>>y1>>x2>>y2;
    if(x2>x1 && y2==y1){
      cout<<"right\n";
    }
    else if(x2<x1 && y2==y1){
      cout<<"left\n";
    }
    else if(x2==x1 && y2>y1){
      cout<<"up\n";
    }
    else if(x2==x1 && y2<y1){
      cout<<"down\n";
    }
    else{
      cout<<"sad\n";
    }
  }

  return 0;
}
