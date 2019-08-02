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
#define N 100001

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  while(cin>>n && n!=0){
    ll a[n],b[n];
    fr(i,0,n){
      cin>>a[i];
      b[a[i]-1]=i+1;
    }

    bool flag=true;
    fr(i,0,n){
      if(a[i]!=b[i]){
        flag=false;
        break;
      }
    }

    if(flag) cout<<"ambiguous\n";
    else cout<<"not ambiguous\n";
  }

  return 0;
}
