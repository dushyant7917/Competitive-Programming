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

  string n;
  ll num[110];

  while(cin>>n){
    if(n=="1") cout<<1<<"\n";
    else{
      ll k=0;
      for(ll i=n.size()-1;i>=0;i--) num[k++]=n[i]-'0';

      ll carry=0,d;
      // Mutiplying by 2
      fr(i,0,k){
        d=(num[i]*2)+carry;
        num[i]=d%10;
        carry=d/10;
      }
      while(carry!=0){
        num[k++]=carry%10;
        carry=carry/10;
      }

      // Subtracting 2
      if(num[0]>=2) num[0]-=2;
      else{
        if(num[0]==0) num[0]=8;
        else num[0]=9;

        ll p=1;
        while(num[p]<1){
          num[p++]=9;
        }
        num[p]-=1;
      }

      bool flag=false;
      for(ll i=k-1;i>=0;i--){
        if(num[i]) flag=true;
        if(flag) cout<<num[i];
      }
      cout<<"\n";
    }
  }

  return 0;
}
