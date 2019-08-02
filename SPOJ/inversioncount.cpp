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

ll cnt;

void merge(ll a[],ll l,ll m,ll r){
  ll i,j,k;
  ll n1=m-l+1;
  ll n2=r-m;

  ll tmp1[n1],tmp2[n2];
  fr(i,0,n1) tmp1[i]=a[l+i];
  fr(i,0,n2) tmp2[i]=a[m+1+i];

  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2){
    if(tmp1[i]<=tmp2[j]){
      a[k++]=tmp1[i++];
    }
    else{
      a[k++]=tmp2[j++];
      cnt+=n1-i;
    }
  }

  while(i<n1){
    a[k++]=tmp1[i++];
  }
  while(j<n2){
    a[k++]=tmp2[j++];
  }
}

void merge_sort(ll a[],ll l,ll r){
  if(l<r){
    ll m=(l+r)/2;

    merge_sort(a,l,m);
    merge_sort(a,m+1,r);

    merge(a,l,m,r);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n;
  while(t--){
    cin>>n;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    cnt=0;
    merge_sort(a,0,n-1);
    cout<<cnt<<"\n";
  }

  return 0;
}
