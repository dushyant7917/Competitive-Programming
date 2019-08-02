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

  ll n,m,d,D;
  while(t--){
    cin>>n>>m>>d>>D;

    ll dD[n+1]={0};
    ll cnt=0,i=1;
    while(cnt<m){
      dD[i++]++;
      cnt++;
      if(i==n+1) i=1;
    }

    bool flag=true;

    fr(i,1,n+1){
      if(dD[i]<d || dD[i]>D){
        cout<<-1<<"\n";
        flag=false;
        break;
      }
    }

    if(flag){
      vector<pair<ll,ll> > edges;
      ll u,v,j;
      fr(i,1,n+1){
        u=i;
        v=i;
        j=0;
        while(j<dD[i]){
          edges.PB(MP(u,v));
          v++;
          j++;
          if(v>n) v=1;
        }
      }

      fr(i,0,edges.size()){
        cout<<edges[i].first<<" "<<edges[i].second<<"\n";
      }
    }

  }

  return 0;
}
