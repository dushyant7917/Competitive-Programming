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
#define N 10
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll flag;

struct Trie{
  struct Trie *child[N]; // reference to a to z alphabets(N=26)
  bool is_EOW; // flag for indicating end of word or not
};

struct Trie *get_node(){
  struct Trie *ptr = new Trie;

  ptr->is_EOW=false;

  fr(i,0,N) ptr->child[i]=NULL;

  return ptr;
}

void insert(struct Trie *root,string word){
  struct Trie *ptr=root;

  ll pos;
  fr(i,0,word.size()){
    pos=word[i]-'0';
    if(ptr->child[pos]==NULL){
      ptr->child[pos]=get_node();
    }
    ptr=ptr->child[pos];
    if(ptr->is_EOW==true && i<word.size()-1) flag=0;
  }

  ptr->is_EOW=true;

  fr(i,0,N){
    if(ptr->child[i]!=NULL) flag=0;
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
    struct Trie *root=get_node();

    flag=1;

    cin>>n;
    string a[n];
    fr(i,0,n){
      cin>>a[i];
      insert(root,a[i]);
    }

    if(flag==0) cout<<"NO\n";
    else cout<<"YES\n";
  }

  return 0;
}
