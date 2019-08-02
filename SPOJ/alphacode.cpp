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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  while(cin>>s && s[0]!='0'){

    ll dp[s.size()]={0};
    dp[0]=1;
    fr(i,1,s.size()){
      ll num=(s[i-1]-'0')*10;
      num+=(s[i]-'0');

      if((s[i]-'0')>=1 && (s[i]-'0')<=9) dp[i]=dp[i-1];

      if(num>=10 && num<=26) dp[i]+=dp[(i-2<0)?0:i-2];
    }

    cout<<dp[s.size()-1]<<"\n";
  }

  return 0;
}
