#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define K 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m,k;
  cin>>n>>m>>k;

  ll a[n],s[k];

  ll sum=0;
  fr(0,n){
    cin>>a[i];
    sum+=a[i];
  }

  fr(0,k)cin>>s[i];

  vector<ll> ifn;
  ll j;
  fr(0,n){
    for(j=0;j<k;j++){
      if(s[j]==a[i]){
        ifn.pb(i+1);
      }
    }
  }

  ll l,r,x;
  while(m--){
    cin>>l>>r>>x;
    ll cnt=0;
    vector<ll> ifn2;
    fr(l-1,r){
      bool inc=true;
      for(j=0;j<ifn.size();j++){
        if(i+1==ifn[j]){
          inc=false;
        }
        if(a[i]+x==ifn[j]) ifn2.pb(i+1),cout<<i+1<<" "<<a[i]+x<<"\n";
      }
      if(inc){
        cnt++;
        a[i]+=x;
      }
    }
    fr(0,ifn2.size()){
      ifn.pb(ifn2[i]);
    }
    //fr(0,n)cout<<a[i]<<" ";
    //cout<<endl;
    //cout<<sum+cnt*x<<"\n";
  }

  return 0;
}
