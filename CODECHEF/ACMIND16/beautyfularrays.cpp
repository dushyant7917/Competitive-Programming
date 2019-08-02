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

  ll n;
  while(t--){
    cin>>n;
    ll a[n];
    ll c1=0,c0=0,cm1=0,c=0;

    fr(i,0,n){
      cin>>a[i];
      if(a[i]==1) c1++;
      else if(a[i]==0) c0++;
      else if(a[i]==-1) cm1++;
      else c++;
    }

    if(n==1){
      cout<<"yes\n";
      continue;
    }
    else if(c>1){
      cout<<"no\n";
      continue;
    }
    else if(cm1>1 && c1==0){
      cout<<"no\n";
      continue;
    }
    else if(cm1>0 && c==1){
      cout<<"no\n";
      continue;
    }
    else{
      cout<<"yes\n";
      continue;
    }
    
  }

  return 0;
}
