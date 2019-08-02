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

bool divisible_by_8(ll n){
  return (n%8==0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string n;
  cin>>n;
  bool flag=false;
  string s;
  fr(i,0,n.size()){
    if(!flag && divisible_by_8(n[i]-'0')){
      cout<<"YES\n";
      cout<<n[i];
      flag=true;
      break;
    }
    fr(j,i+1,n.size()){
      if(!flag && divisible_by_8((n[i]-'0')*10+(n[j]-'0'))){
        cout<<"YES\n";
        cout<<n[i]<<n[j];
        flag=true;
        break;
      }
      fr(k,j+1,n.size()){
        s=n[i]+n[j]+n[k];
        if(!flag && divisible_by_8((n[i]-'0')*100+(n[j]-'0')*10+(n[k]-'0'))){
          cout<<"YES\n";
          cout<<n[i]<<n[j]<<n[k];
          flag=true;
          break;
        }
      }
    }
  }
  if(!flag) cout<<"NO";

  return 0;
}
