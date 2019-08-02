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
#define N 3000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll q;
  cin>>q;

  ll t,k;
  string s="",w;
  stack<string> st;
  while(q--){
    cin>>t;
    if(t==1){ // append w
      cin>>w;
      st.push(s);
      s+=w;
    }
    else if(t==2){ // delete last k chars
      cin>>k;
      st.push(s);
      s.erase(s.size()-k);
    }
    else if(t==3){ // print kth char
      cin>>k;
      cout<<s[k-1]<<"\n";
    }
    else{ // undo last append or delete operation
      s=st.top();
      st.pop();
    }
  }

  return 0;
}
