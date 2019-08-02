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

void ps(stack<char> s){
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string a;
  ll cnt;
  while(t--){
    cin>>a;

    map<char,ll> mp;
    stack<char> s;

    fr(i,0,a.size()){
      if(!s.empty() && a[i]=='.'){
        s.push(a[i]);
      }
      else if(s.empty() && a[i]!='.'){
        s.push(a[i]);
      }
      else if(!s.empty() && a[i]!='.'){
        cnt=0;
        while(s.top()=='.'){
          s.pop();
          cnt++;
        }
        if(s.top()==a[i]){
          mp[a[i]]+=cnt;
        }
        s.pop();
        s.push(a[i]);
      }
      else{
        //
      }
      //ps(s);
    }

    fr(i,0,a.size()) mp[a[i]]++;

    cout<<mp['A']<<" "<<mp['B']<<"\n";
  }

  return 0;
}
