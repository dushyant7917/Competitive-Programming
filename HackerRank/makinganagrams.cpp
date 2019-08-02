#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s1,s2;
  cin>>s1>>s2;

  ll f1[26]={},f2[26]={};
  ll n1=s1.size();
  ll n2=s2.size();

  fr(0,n1){
    f1[s1[i]-'a']++;
  }
  fr(0,n2){
    f2[s2[i]-'a']++;
  }

  ll diff;
  ll cnt=0;
  fr(0,26){
    diff=f1[i]-f2[i];
    cnt+=(diff>0)?diff:0;
    diff=f2[i]-f1[i];
    cnt+=(diff>0)?diff:0;
  }
  
  cout<<cnt;

  return 0;
}
