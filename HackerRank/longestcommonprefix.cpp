#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

string longest_prefix(string s1,string s2){
  ll i,j;
  string prefix="";
  for(i=0,j=0;i<s1.size(),j<s2.size();i++,j++){
    if(s1[i]==s2[j]) prefix+=s1[i];
    else break;
  }
  return prefix;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  string s[n];
  fr(0,n) cin>>s[i];

  string ans="";

  // Method 1: O(n^2) but better than method 2 when there are large number of strings
  /*
  ll cnt,j=0,k=0;
  bool flag=true;
  char prv=s[0][0];
  do{
    cnt=1;
    prv=s[j][k];
    fr(1,n){
      if(s[i][k]!='\0' && s[i][k]==prv){
        cnt++;
      }
      else{
        flag=false;
        break;
      }
    }
    if(cnt==n) ans+=s[j][k];
    k++;
    j++;
  }while(flag);
  */

  // Method 2: O(n^2)
  ans=s[0];
  fr(1,n){
    ans=longest_prefix(ans,s[i]);
  }

  cout<<ans;

  return 0;
}
