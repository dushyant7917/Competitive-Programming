#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)
#define mod 1000000007

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  ll n;
  ll a1=3,a2=5,a3=15,d1=3,d2=5,d3=15,l1,l2,l3,n1,n2,n3,s1,s2,s3;
  while(t--){
    cin>>n;
    n--;
    if(n<3){
      cout<<0<<"\n";
    }
    else{
      l1=n-(n%3); n1=((l1-a1)/d1)+1;
      l2=n-(n%5); n2=((l2-a2)/d2)+1;
      l3=n-(n%15); n3=((l3-a3)/d3)+1;
      s1=(n1*(a1+l1))/2;
      s2=(n2*(a2+l2))/2;
      s3=(n3*(a3+l3))/2;
      cout<<s1+s2-s3<<"\n";
    }
  }

  return 0;
}
