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

  ll n;
  string s,r;
  string seq[8]={"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
  while(t--){
    cin>>n>>s;

    map<string,ll> mp;
    
    fr(i,0,38){
      r="";
      fr(j,i,i+3){
        r+=s[j];
      }
      mp[r]++;
    }

    cout<<n<<" ";
    fr(i,0,8){
      cout<<mp[seq[i]]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
