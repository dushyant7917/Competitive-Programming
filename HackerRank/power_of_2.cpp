#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

bool p2(ll x)
{
    return (!(x & (x-1)));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll c[n][2];
  while(t--){
    cin>>n;
    cout<<p2(n)<<"\n";
  }

  return 0;
}
