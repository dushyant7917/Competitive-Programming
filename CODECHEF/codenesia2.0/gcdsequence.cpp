#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(i,a,b) for(ll i=a;i<b;i++)

bool primes[1000001];
ll gcd[1000001];
ll gcd2[1000001];

void gcd_nums(ll n){
  memset(primes, true, sizeof(primes)); // primes[0 to n] = true
  memset(gcd, 1000001, sizeof(gcd));

  ll i,j;
  for(i=2;i*i<=n;i++){
    // i is still unmarked
    if(primes[i]){
      // Mark numbers which are mutiples of i excluding i itself
      for(j=i*2;j<=n;j=j+i){
        primes[j]=false;
        gcd[j]=min(i,gcd[j]);
      }
      gcd[i]=i;
    }
  }

  gcd[0]=0;
  gcd[1]=1;
  primes[0]=primes[1]=false;
}

void gcd_nums2(ll n){
  memset(primes, true, sizeof(primes)); // primes[0 to n] = true

  ll i,j;
  for(i=2;i*i<=n;i++){
    // i is still unmarked
    if(primes[i]){
      // Mark numbers which are mutiples of i excluding i itself
      for(j=i*2;j<=n;j=j+i){
        primes[j]=false;
        gcd2[j]=i;
      }
      gcd2[i]=i;
    }
  }

  gcd2[0]=0;
  gcd2[1]=1;
  primes[0]=primes[1]=false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  gcd_nums(1000001);
  gcd_nums2(1000001);

  ll t;
  cin>>t;
  ll n;
  while(t--){
    cin>>n;

    ll a[n],b[n],c[n];
    fr(i,0,n){
      cin>>a[i];
      b[i]=gcd[a[i]];
      c[i]=gcd2[a[i]];
    }
    sort(b,b+n);
    sort(c,c+n);

    ll si=-1;
    fr(i,0,n){
      if(b[i]!=1){
        si=i;
        break;
      }
    }
    if(si==-1){
      cout<<0<<"\n";
      continue;
    }
    ll k1=1;
    ll prv=b[si];
    ll cnt=1;
    fr(i,si+1,n+1){
      if(b[i]==prv){
        cnt++;
      }
      else{
        k1=max(cnt,k1);
        cnt=1;
      }
      prv=b[i];
    }

    //////////////
    si=-1;
    fr(i,0,n){
      if(c[i]!=1){
        si=i;
        break;
      }
    }
    if(si==-1){
      cout<<0<<"\n";
      continue;
    }
    ll k2=1;
    prv=c[si];
    cnt=1;
    fr(i,si+1,n+1){
      if(c[i]==prv){
        cnt++;
      }
      else{
        k2=max(cnt,k2);
        cnt=1;
      }
      prv=c[i];
    }

    cout<<max(k1,k2)<<"\n";
  }

  return 0;
}
