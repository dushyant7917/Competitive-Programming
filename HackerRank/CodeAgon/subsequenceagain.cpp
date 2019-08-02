#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  string s;
  ll k;
  cin>>s;
  cin>>k;
  ll freq[26]={};
  ll n=s.size();
  loop(0,n){
    freq[s[i]-'a']++;
  }
  string m="";
  loop(0,n){
    if(freq[s[i]-'a']>=k){
      m+=s[i];
    }
  }
  cout<<m;
  return 0;
}
