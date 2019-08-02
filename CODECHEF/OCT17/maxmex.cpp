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

  ll n,k;
  while(t--){
    cin>>n>>k;
    ll a[n];
    fr(i,0,n){
      cin>>a[i];
    }

    sort(a,a+n);

    ll len=1000001;
    bool b[len];
    fr(i,0,len) b[i]=false;

    fr(i,0,n) b[a[i]]=true;

    ll cnt=0,i=0;
    while(cnt<k){
      if(b[i]==false){
        b[i]=true;
        cnt++;
      }
      i++;
    }

    fr(i,0,len){
      if(b[i]==false){
        cout<<i;
        break;
      }
    }

    cout<<"\n";
  }

  return 0;
}
