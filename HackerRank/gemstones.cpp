#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  ll f[n][26];

  ll j;

  fr(0,n){
    for(j=0;j<26;j++) f[i][j]=0;
  }

  string s;
  fr(0,n){
    cin>>s;
    for(j=0;j<s.size();j++){
      f[i][s[j]-'a']++;
    }
  }

  ll cnt=0,num;
  fr(0,26){
    num=0;
    for(j=0;j<n;j++){
      if(f[j][i]) num++;
    }
    if(num>=n) cnt++;
  }

  cout<<cnt;

  return 0;
}
