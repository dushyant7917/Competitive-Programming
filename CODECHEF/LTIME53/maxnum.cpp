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
  cout.tie(NULL);
  ll t;
  cin>>t;

  string n;
  ll sum,ans;
  while(t--){
    cin>>n;

    if(n.size()<2){
      cout<<-1;
      continue;
    }

    if(n[n.size()-1]%2!=0){
      if(n[n.size()-2]%2==0){
        sum=0;
        fr(i,0,n.size()-1) sum+=n[i]-'0';
        if(sum%3==0){
          fr(i,0,n.size()-1) cout<<n[i];
          cout<<"\n";
          continue;
        }
        else{
          cout<<-1<<"\n";
          continue;
        }
      }
      else{
        cout<<-1<<"\n";
        continue;
      }
    }
    else{
      sum=0;
      fr(i,0,n.size()) sum+=n[i]-'0';

      bool flag=false;
      ll ind;
      fr(i,0,n.size()-1){
        if((sum-n[i]-'0')%3==0 && (n[i]-'0')<(n[i+1]-'0')){
          ind=i;
          flag=true;
          break;
        }
      }
      if(!flag){
        fr(i,0,n.size()-1){
          if((sum-n[i]-'0')%3==0 && (n[i]-'0')>(n[i+1]-'0')){
            ind=i;
            flag=true;
          }
        }
      }
      if(!flag){
        cout<<-1<<"\n";
      }
      else{
        fr(i,0,n.size()){
          if(i!=ind) cout<<n[i];
        }
        cout<<"\n";
      }
    }

  }

  return 0;
}
