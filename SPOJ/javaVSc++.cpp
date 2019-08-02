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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

string cpp_to_java(string s){
  string ans="";

  fr(i,0,s.size()){
    if(s[i]=='_'){
      i++;
      ans+=toupper(s[i]);
    }
    else ans+=s[i];
  }

  return ans;
}

string java_to_cpp(string s){
  string ans="";

  fr(i,0,s.size()){
    if(isupper(s[i])){
      ans+='_';
      ans+=tolower(s[i]);
    }
    else ans+=s[i];
  }

  return ans;
}

bool is_java(string s){
  if(s[0]<='Z') return false;

  fr(i,0,s.size()){
    if(s[i]=='_') return false;
  }

  return true;
}

bool is_cpp(string s){
  if(s[0]=='_' || s[s.size()-1]=='_') return false;

  fr(i,0,s.size()){
    if(s[i]<='Z') return false;
    if(i<s.size()-2 && s[i]=='_' && s[i+1]=='_') return false;
  }

  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;

  while(cin>>s){
    if(is_cpp(s)) cout<<cpp_to_java(s)<<"\n";
    else if(is_java(s)) cout<<java_to_cpp(s)<<"\n";
    else cout<<"Error!\n";
  }

  return 0;
}
