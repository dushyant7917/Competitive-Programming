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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;

  string hello="hello";
  ll j=0;
  bool flag=false;
  fr(i,0,s.size()){
    if(s[i]==hello[j]){
      j++;
      if(j==5){
        cout<<"YES";
        flag=true;
        break;
      }
    }
  }

  if(!flag) cout<<"NO";

  return 0;
}
