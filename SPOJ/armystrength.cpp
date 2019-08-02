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
  ll t;
  cin>>t;

  ll ng,nm;
  while(t--){
    cin>>ng>>nm;

    ll ag[ng],am[nm];

    // O(nlogn) solution
    /*
    fr(i,0,ng) cin>>ag[i];
    fr(i,0,nm) cin>>am[i];

    sort(ag,ag+ng);
    sort(am,am+nm);

    queue<ll> qg,qm;
    fr(i,0,ng) qg.push(ag[i]);
    fr(i,0,nm) qm.push(am[i]);

    while(!qg.empty() && !qm.empty()){
      if(qm.front()>qg.front()) qg.pop();
      else qm.pop();
    }

    if(qg.size()>qm.size()) cout<<"Godzilla\n";
    else cout<<"MechaGodzilla\n";
    */

    // O(n) solution
    ll mg=0,mm=0;
    fr(i,0,ng){
      cin>>ag[i];
      mg=max(mg,ag[i]);
    }
    fr(i,0,nm){
      cin>>am[i];
      mm=max(mm,am[i]);
    }

    if(mg>=mm) cout<<"Godzilla\n";
    else cout<<"MechaGodzilla\n";
  }

  return 0;
}
