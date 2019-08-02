#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 101
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

bool check(string p,string s){
  fr(i,0,SZ(s)-1) if(p[i+1]!=s[i]) return false;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  string s[2*n-2];
  fr(i,0,2*n-2) cin>>s[i];

  char ans[2*n-2],c[n];

  int x=-1,y=-1;
  fr(i,0,2*n-2){
    if(SZ(s[i])!=n-1) continue;
    if(x==-1) x=i;
    else y=i;
  }

  ll flag=-1;

  if(check(s[x],s[y])){
    ans[x]='P';
    ans[y]='S';
    fr(i,0,n-1) c[i]=s[x][i];
    c[n-1]=s[y][n-2];
    flag=0;
  }
  else if(check(s[y],s[x])){
    ans[y]='P';
    ans[x]='S';
    fr(i,0,n-1) c[i]=s[y][i];
    c[n-1]=s[x][n-2];
    flag=1;
  }
  else fr(i,0,n) c[i]='?';

  ll prf[n]={0},suf[n]={0};

  fr(i,0,2*n-2){
    if(SZ(s[i])==n-1) continue;

    bool prefix=true;
    fr(j,0,SZ(s[i])){
      if(c[j]!=s[i][j]){
        prefix=false;
        break;
      }
    }

    if(prefix && !prf[SZ(s[i])]){
      ans[i]='P';
      prf[SZ(s[i])]=1;
    }
    else if(!suf[SZ(s[i])]){
      ans[i]='S';
      suf[SZ(s[i])]=1;
    }
    else ans[i]='!';
  }

  bool re_compute=false;

  fr(i,0,2*n-2){
    if(ans[i]=='!'){
      re_compute=true;
      break;
    }
  }

  if(re_compute){
    if(flag){
      ans[x]='P';
      ans[y]='S';
      fr(i,0,n-1) c[i]=s[x][i];
      c[n-1]=s[y][n-2];
    }
    else{
      ans[y]='P';
      ans[x]='S';
      fr(i,0,n-1) c[i]=s[y][i];
      c[n-1]=s[x][n-2];
    }

    fr(i,0,n) prf[i]=suf[i]=0;

    fr(i,0,2*n-2){
      if(SZ(s[i])==n-1) continue;

      bool prefix=true;
      fr(j,0,SZ(s[i])){
        if(c[j]!=s[i][j]){
          prefix=false;
          break;
        }
      }

      if(prefix && !prf[SZ(s[i])]){
        ans[i]='P';
        prf[SZ(s[i])]=1;
      }
      else if(!suf[SZ(s[i])]){
        ans[i]='S';
        suf[SZ(s[i])]=1;
      }
      else cout<<"\nError\n";
    }
  }

  fr(i,0,2*n-2) cout<<ans[i];

  return 0;
}
