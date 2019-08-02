#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll a[n][m];
  ll i,j;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++) cin>>a[i][j];
  }

  ll rs=0,cs=0,re=n-1,ce=m-1;
  while(rs<=re && cs<=ce){
    for(j=cs;j<=ce;j++){
      cout<<a[rs][j]<<" ";
    }
    rs++;

    for(j=rs;j<=re;j++){
      cout<<a[j][ce]<<" ";
    }
    ce--;

    if(rs<=re){
      for(j=ce;j>=cs;j--){
        cout<<a[re][j]<<" ";
      }
      re--;
    }

    if(cs<=ce){
      for(j=re;j>=rs;j--){
        cout<<a[j][cs]<<" ";
      }
      cs++;
    }
  }

  return 0;
}
