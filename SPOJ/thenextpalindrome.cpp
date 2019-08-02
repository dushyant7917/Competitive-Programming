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

bool palindrome(string s){
  ll i=0,j=s.size()-1;
  while(i<j){
    if(s[i]!=s[j]) return false;
    i++;
    j--;
  }
  return true;
}

bool all_9s(string s){
  ll cnt=0;
  fr(i,0,s.size()) if(s[i]=='9') cnt++;

  if(cnt==s.size()) return true;
  else return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  string n;
  while(t--){
    cin>>n;

    if(all_9s(n)){          // number consists of 9s as all th digits
      string ans="1";
      fr(i,0,n.size()-1) ans+='0';
      ans+='1';
      cout<<ans<<"\n";
    }

    else if(palindrome(n)){ // number is a palindrome
      if(n.size()%2==1){                    // number is odd in length
        if(n[n.size()/2]=='9'){                             // number has middle digit as 9
          n[(n.size()/2)-1]+=1;
          n[(n.size()/2)+1]+=1;
          n[(n.size()/2)]='0';
          cout<<n<<"\n";
        }
        else{                                               // number has middle digit < 9
          n[n.size()/2]+=1;
          cout<<n<<"\n";
        }
      }
      else{                                 // number is even in length
        if(n[n.size()/2]=='9' && n[(n.size()/2)-1]=='9'){   // number has two middle digits as 9
          n[(n.size()/2)-2]+=1;
          n[(n.size()/2)+1]+=1;
          n[(n.size()/2)-1]='0';
          n[(n.size()/2)]='0';
          cout<<n<<"\n";
        }
        else{                                               // number has two middle digits < 9
          n[(n.size()/2)-1]+=1;
          n[(n.size()/2)]+=1;
          cout<<n<<"\n";
        }
      }
    }

    else{                   // number is a not a palindrome
      if(n.size()%2==1){                    // number is odd in length
        ll i,j,ind;
        i=(n.size()/2)-1;
        j=(n.size()/2)+1;
        while(i>=0 && j<n.size()){
          if(n[i]!=n[j]){
            ind=i;
            break;
          }
          i--;
          j++;
        }
        if(n[i]<n[j]){                                      // 1st different digit on LHS is smaller than 1st different digit on RHS
          ll k=n.size()/2;
          ll carry=0,d;

          do{
            d=(n[k]-'0'+1);
            n[k]=(d%10)+'0';
            carry=d/10;
            k--;
          }while(carry!=0 && k>=0);

          string ans="",aux="";
          for(ll i=n.size()/2-1;i>=0;i--) aux+=n[i];
          fr(i,0,(n.size()/2)+1) ans+=n[i];
          fr(i,0,aux.size()) ans+=aux[i];
          cout<<ans<<"\n";
        }
        else{                                               // 1st different digit on LHS is greater than 1st different digit on RHS
          string ans="",aux="";
          for(ll i=n.size()/2;i>=0;i--) aux+=n[i];
          fr(i,0,n.size()/2) ans+=n[i];
          fr(i,0,aux.size()) ans+=aux[i];
          cout<<ans<<"\n";
        }
      }
      else{                                 // number is even in length
        ll i,j,ind;
        i=(n.size()/2)-1;
        j=(n.size()/2);
        while(i>=0 && j<n.size()){
          if(n[i]!=n[j]){
            ind=i;
            break;
          }
          i--;
          j++;
        }
        if(n[i]<n[j]){                                      // 1st different digit on LHS is smaller than 1st different digit on RHS
          ll k=(n.size()/2)-1;
          ll carry=0,d;

          do{
            d=(n[k]-'0'+1);
            n[k]=(d%10)+'0';
            carry=d/10;
            k--;
          }while(carry!=0 && k>=0);

          string ans="",aux="";
          for(ll i=n.size()/2-1;i>=0;i--) aux+=n[i];
          fr(i,0,n.size()/2) ans+=n[i];
          fr(i,0,aux.size()) ans+=aux[i];
          cout<<ans<<"\n";
        }
        else{                                               // 1st different digit on LHS is greater than 1st different digit on RHS
          string ans="",aux="";
          for(ll i=(n.size()/2)-1;i>=0;i--) aux+=n[i];
          fr(i,0,n.size()/2) ans+=n[i];
          fr(i,0,aux.size()) ans+=aux[i];
          cout<<ans<<"\n";
        }
      }
    }

  }

  return 0;
}
