#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll string_to_num(string x){
  ll n=0;
  fr(i,0,x.size()){
    n=(x[i]-'0')+(n*10);
  }
  return n;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a,b;
  cin>>a>>b;

  ll num2=string_to_num(b);

  ll f[10]={0};
  fr(i,0,a.size()) f[a[i]-'0']++;

  ll num=0,cur,nxt;
  fr(n,0,a.size()){
    cur=num;
    rf(d,9,0){
      if(!f[d]) continue;
      nxt=cur*10+d;
      f[d]--;
      fr(j,0,10){
        fr(k,1,f[j]+1){
          nxt=nxt*10+j;
        }
      }
      if(nxt<=num2){
        num=num*10+d;
        break;
      }
      f[d]++;
    }
  }

  cout<<num;

  return 0;
}
