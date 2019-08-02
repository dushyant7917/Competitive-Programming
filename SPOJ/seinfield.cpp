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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll cnt=1;
  string s,ans;
  while(cin>>s && s[0]!='-'){
    stack<char> st,rv;
    fr(i,0,s.size()){
      if(s[i]=='{') st.push('{');
      else if(s[i]=='}' && !st.empty() && st.top()=='{') st.pop();
      else st.push(s[i]);
    }
    while(!st.empty()){
      rv.push(st.top());
      st.pop();
    }
    ans="";
    while(!rv.empty()){
      ans+=rv.top();
      rv.pop();
    }
    ll lpc=0,rpc=0;
    fr(i,0,ans.size()){
      if(i%2==0 && ans[i]=='}') rpc++;
      if(i%2==1 && ans[i]=='{') lpc++;
    }
    cout<<(cnt++)<<". "<<rpc+lpc<<"\n";
  }

  return 0;
}
