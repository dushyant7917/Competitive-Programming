#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

ll sum_digits(ll n){
  ll sum=0;
  while(n){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  if(!n){
    cout<<0;
    return 0;
  }

  ll max_sum=0,num;
  fr(1,n+1){
    if(n%i==0 && sum_digits(i)>max_sum){
      max_sum=sum_digits(i);
      num=i;
    }
  }

  cout<<num;

  return 0;
}
