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

string num;
bool flag=false;

ll dp[101][1001];

void solve(ll i,ll n){
  if(n%8==0 && n!=0 && !flag){
    cout<<"YES\n";
    cout<<n;
    flag=true;
    return;
  }
  if(i==num.size()){
    return;
  }
  if(dp[i][n]==0){
    solve(i+1,n);
    solve(i+1,((n*10)+(num[i]-'0'))%1000);
    dp[i][n]=1;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>num;

  fr(i,0,num.size()){
    if(num[i]=='0'){
      cout<<"YES\n0";
      flag=true;
      break;
    }
  }
  fr(i,0,num.size()+1) fr(j,0,1001) dp[i][j]=0;
  if(!flag) solve(0,0);
  if(!flag) cout<<"NO";

  return 0;
}
