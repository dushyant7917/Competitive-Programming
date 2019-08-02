#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)
#define ll1 1LL

int main(){
  ll n,m,k;
  cin>>n>>m>>k;

  ll x;
  vector<ll> v; // contains indices of building having items;
  loop(0,n){
    cin>>x;
    if(x==1){
      v.push_back(i);
    }
  }

  if(v.size()<m){
    cout<<-1;
    return 0;
  }

  ll ans=0;
  loop(0,m){
    if(i==0){
      ans+=v[i];
    }
    else{
      ans+=(v[i]-v[i-1])*i*k; // here i also represents number of items collected previously
    }
  }

  //cout<<"ans:"<<ans<<"\n";

  ll window=ans;
  ll diff;
  // sliding window technique
  loop(m,v.size()){
    diff=(v[i]-v[i-ll1])*(m-ll1)*k - (v[i-ll1]-v[i-m+ll1])*k + (v[i-m+ll1]-v[i-m])*(ll1-k);
    window+=diff;
    //cout<<"diff:"<<diff;
    //cout<<" window:"<<window<<"\n";
    ans=min(window,ans);
  }

  //cout<<"final ans:"<<ans;
  cout<<ans;

  return 0;
}
