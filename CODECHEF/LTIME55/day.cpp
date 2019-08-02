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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string day[]={"mon","tues","wed","thurs","fri","sat","sun"};

  ll w;
  string s;
  ll ind,e;
  while(t--){
    cin>>w>>s;
    fr(i,0,7){
      if(s==day[i]){
        ind=i;
        break;
      }
    }
    e=w%7;
    ll f[7]={0},cnt=0;
    ll k=ind;
    while(cnt<e){
      f[k]=5;
      k++;
      cnt++;
      if(k==7) k=0;
    }
    fr(i,0,7){
      if(!f[i]) f[i]=4;
    }

    fr(i,0,7) cout<<f[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
