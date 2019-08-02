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

bool balanced(string s){
  stack<char> st;

  fr(i,0,s.size()){
    if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
      st.push(s[i]);
    }
    else{
      if(st.empty()==true){
        return false;
      }
      if(s[i]==')' && st.top()=='(') st.pop();
      else if(s[i]==']' && st.top()=='[') st.pop();
      else if(s[i]=='}' && st.top()=='{') st.pop();
      else return false;
    }
  }
  if(st.empty()) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string s;
  while(t--){
    cin>>s;
    if(balanced(s)) cout<<"YES\n";
    else cout<<"NO\n";
  }

  return 0;
}
