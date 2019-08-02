#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

bool valid(ll n){
  if(abs(n)<=15) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  t=10;

  srand((unsigned)time(0));

  ll n,ans1,ans2,x,ind;
  while(t--){
    n=(rand()%10)+1;

    ll a[n],b[n];
    map<ll,ll> mp;
    ll f[N]={0};
    vector<ll> v;
    fr(i,0,n){
      //cin>>a[i];
      a[i]=(rand()%31)-15;
      b[i]=2*a[i];
      mp[b[i]]++;
      if(a[i]<0){
        f[abs(a[i])+15]++;
        if(f[abs(a[i])+15]==1) v.PB(a[i]);
      }
      else{
        f[a[i]]++;
        if(f[a[i]]==1) v.PB(a[i]);
      }
    }

    // BRUTE FORCE //

    ans1=0;

    fr(i,0,n){
      fr(j,i+1,n){
        if(mp[a[i]+a[j]]) ans1++;
      }
    }


    ////////////////

    ans2=0;
    ll prv=0;

    cout<<"*******************\n";

    fr(i,0,SZ(v)){
      //cout<<v[i]<<"->"<<2*v[i]<<"\n";

      if(v[i]<0){
        rf(j,0,max(-15,v[i])){
          x=2*v[i]-j;
          //cout<<"Considering..."<<j<<" "<<x<<"\n";
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(j==0 && x==0) ans2+=(f[0]*(f[0]-1))/2;
            else if(j==0 && x!=0) ans2+=f[abs(x)+15]*f[0];
            else if(j!=0 && x==0) ans2+=f[abs(j)+15]*f[0];
            else if(j!=0 && x==j) ans2+=(f[abs(j)+15]*(f[abs(j)+15]-1))/2;
            else ans2+=f[(x<0)?abs(x)+15:x]*f[abs(j)+15];

            if(ans2>prv){
              //cout<<"INCREMENT 1\n";
              prv=ans2;
            }
          }
        }
        rf(j,max(-15,2*v[i])-1,-15){
          x=2*v[i]-j;
          //cout<<"Considering..."<<j<<" "<<x<<"\n";
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(x==j) ans2+=(f[abs(j)+15]*(f[abs(j)+15]-1))/2;
            else ans2+=f[(x<0)?abs(x)+15:x]*f[abs(j)+15];

            if(ans2>prv){
              //cout<<"INCREMENT 2\n";
              prv=ans2;
            }
          }
        }
        //cout<<"\n";
      }

      else{
        fr(j,0,min(15,v[i])+1){
          x=2*v[i]-j;
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(j==0 && x==0) ans2+=(f[0]*(f[0]-1))/2;
            else if(j==0 && x!=0) ans2+=f[x]*f[0];
            else if(j!=0 && x==0) ans2+=f[j]*f[0];
            else if(j!=0 && x==j) ans2+=(f[j]*(f[j]-1))/2;
            else ans2+=f[(x<0)?abs(x)+15:x]*f[j];

            if(ans2>prv){
              //cout<<"INCREMENT 3\n";
              prv=ans2;
            }
          }
        }
        fr(j,min(15,2*v[i])+1,15+1){
          x=2*v[i]-j;
          if(valid(x) && valid(j)){
            //cout<<j<<" "<<x<<"\n";
            if(x==j) ans2+=(f[j]*(f[j]-1))/2;
            else ans2+=f[(x<0)?abs(x)+15:x]*f[j];

            if(ans2>prv){
              //cout<<"INCREMENT 4\n";
              prv=ans2;
            }
          }
        }
        //cout<<"\n";
      }
    }

    if(ans1!=ans2){
      fr(i,0,n){
        cout<<a[i]<<" ";
      }
      cout<<"\n\n\n*************************";
      cout<<"RIGHT:"<<ans1<<" WRONG:"<<ans2<<"\n\n\n";
    }

  }

  return 0;
}
