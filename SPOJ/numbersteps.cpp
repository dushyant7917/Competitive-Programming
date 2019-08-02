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

  ll x,y;
  while(t--){
    cin>>x>>y;
    if(x==y){
      if(x%2==0) cout<<2*x;
      else cout<<(2*x)-1;
    }
    else if(y==x-2){
      if(x%2==0) cout<<(2*x)-2;
      else cout<<(2*x)-3;
    }
    else{
      cout<<"No Number";
    }
    cout<<"\n";
  }

  return 0;
}
