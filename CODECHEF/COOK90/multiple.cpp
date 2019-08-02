#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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
#define sz(s) s.size()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll k,d0,d1,sum,d,ind,x,s3;
  while(t--){
    cin>>k>>d0>>d1;

    if(k<=10){
      sum=d0+d1;
      ind=3;
      while(ind<=k){
        d=sum%10;
        sum+=d;
        ind++;
      }
      if(sum%3==0) cout<<"YES\n";
      else cout<<"NO\n";
    }

    else{
      if(k<=3){
        sum=d0+d1;
        ind=3;
        while(ind<=k){
          d=sum%10;
          sum+=d;
          ind++;
        }
        if(sum%3==0) cout<<"YES\n";
        else cout<<"NO\n";
      }
      else{
        sum=d0+d1;
        d=sum%10;
        sum+=d;
        s3=sum;
        if(s3%10==0){
          if(s3%3==0) cout<<"YES\n";
          else cout<<"NO\n";
        }
        else{
          ll p[5]={0};
          fr(i,1,5){
            p[i]=sum%10;
            sum+=p[i];
          }
          x=(k-3)/4;
          ind=(k-3)%4;
          sum=s3+(x*20);
          fr(i,0,ind+1) sum+=p[i];
          if(sum%3==0) cout<<"YES\n";
          else cout<<"NO\n";
        }
      }
    }
  }

  return 0;
}
