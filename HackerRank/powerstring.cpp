#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n,sum;
  string s;
  while(t--){
    cin>>n;
    cin>>s;

    // Below code takes full sizeof(f[26]) space
    /*
    ll f[26]={};
    fr(0,s.size()) f[s[i]-'a']++;

    sum=0;
    fr(0,26){
      if(f[i]){
        sum+=pow(f[i],2);
      }
    }
    cout<<sum<<"\n";
    */

    // Below code allocates space dynamically
    map<char,ll> freq;
    map<char,ll>::iterator itr;

    fr(0,s.size()){
      freq[s[i]]++;
    }

    ll sum=0;
    for(itr=freq.begin();itr!=freq.end();itr++){
      sum+=pow(itr->second,2);
    }
    cout<<sum<<"\n";
  }

  return 0;
}
