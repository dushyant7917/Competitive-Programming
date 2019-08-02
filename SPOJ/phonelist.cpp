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

  bool flag;
  ll n,cnt;
  string s1,s2;
  while(t--){
    cin>>n;
    string a[n];
    fr(i,0,n) cin>>a[i];
    sort(a,a+n);

    flag=true;
    s1=a[0];
    fr(i,1,n){
      s2=a[i];
      cnt=0;
      fr(j,0,s1.size()){
        if(s1[j]==s2[j]) cnt++;
      }
      if(cnt==s1.size()){
        cout<<"NO\n";
        flag=false;
        break;
      }
      s1=s2;
    }
    if(flag) cout<<"YES\n";
  }

  return 0;
}
