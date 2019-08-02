#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)

int main(){
  string s;
  getline(cin,s);

  ll f[26]={};
  loop(0,s.size()){
    f[tolower(s[i])-'a']++;
  }

  bool status=true;
  loop(0,26){
    if(!f[i]){
      status=false;
      break;
    }
  }

  if(status){
    cout<<"pangram";
  }
  else{
    cout<<"not pangram";
  }

  return 0;
}
