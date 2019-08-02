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
  ll t;
  cin>>t;

  string s,ans;
  while(t--){
    cin>>s;

    ans="";
    stack<char> st;

    fr(i,0,s.size()){
      if(s[i]=='(' || s[i]==')' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^'){ // An operator or bracket is processed
        if(s[i]==')'){
          ans+=st.top();
          st.pop();
          st.pop();
        }
        else st.push(s[i]);
      }
      else{ // An operand is processed
        ans+=s[i];
      }
    }

    cout<<ans<<"\n";
  }

  return 0;
}
