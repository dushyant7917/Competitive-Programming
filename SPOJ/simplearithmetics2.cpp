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

ll num(string s){
  ll ans=0;
  fr(i,0,s.size()) ans=(s[i]-'0')+(10*ans);
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n1,n2;
  string s,op;
  while(t--){
    stack<ll> st;
    while(cin>>s && s[0]!='='){
      op=s;
      if(s=="+" || s=="-" || s=="*" || s=="/"){
        n1=st.top();
        st.pop();
        cin>>s;
        n2=num(s);

        if(op=="+") st.push(n1+n2);
        else if(op=="-") st.push(n1-n2);
        else if(op=="*") st.push(n1*n2);
        else st.push(n1/n2);

      }
      else{
        st.push(num(s));
      }
    }

    cout<<st.top()<<"\n";
  }



  return 0;
}
