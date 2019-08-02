#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define loop(a,b) for(ll i=a;i<b;i++)
#define loop2(a,b) for(j=a;i<b;j++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  ll n=s.size();

  ll freq[26]={}; // Array to store frequency of chars of s (initialized to 0 at begining)

  loop(0,n){
    freq[s[i]-'a']++;
  }

  ll j;
  // loop starts from -1 to check if s is already valid or not
  loop(-1,26){
    if(i>=0 && freq[i]==0){
      continue; // char not present in s
    }
    if(i>=0){
      freq[i]--;
    }
    set<ll> cnt_diff_freq;
    for(j=0;j<26;j++){
      if(freq[j]!=0){
        cnt_diff_freq.insert(freq[j]);
      }
    }
    if(cnt_diff_freq.size()==1){
      cout<<"YES";
      return 0;
    }
    if(i>=0){
      freq[i]++;
    }
  }

  cout<<"NO";

  return 0;
}
