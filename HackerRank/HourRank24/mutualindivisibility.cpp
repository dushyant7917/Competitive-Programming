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

  ll a,b,x;
  while(t--){
    cin>>a>>b>>x;
    if(x>min(b-a+1,(b+1)/2)) cout<<-1;
    else{
      fr(i,b-x+1,b+1) cout<<i<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
