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

  ll t;
  cin>>t;

  ll n,start;
  while(t--){
    stack<ll> p;
    cin>>n>>start;

    char pt;
    ll id,prv,cur;
    cur=start;

    fr(i,0,n){
      cin>>pt;
      if(pt=='P'){
        cin>>id;
        prv=cur;
        cur=id;
      }
      else{
        swap(cur,prv);
      }
    }
    cout<<"Player "<<cur<<"\n";
  }

  return 0;
}
