#include<bits/stdc++.h>
using namespace std;
vector<string> a;
int n;
// ke tiep : gap 0 sang 1, doi tat ca ve 0;
//-> lien trc: gap 1 doi sang 0, doi tat ca 0 sau ve 1

string sinh(string s){
   int len=s.length();
   int i= len-1;
   while (i>=0 && s[i]=='0'){
      s[i--]='1';
   }
   if (i>=0){
      s[i]='0';
   }
   else{
      s="";
      for(int i=0;i<len;i++) s+="1";
      return s;
   }
   return s;
}
void xuat(){
   for(auto i:a){
      cout<<i<<" ";
   }
   cout<<endl;
}
int main(){
   cin>>n;
   a.assign(n,"");
   for(int i=0;i<n;i++){
      getline(cin>>ws, a[i]);
   }
   for(int i=0;i<n;i++){
      cout<<sinh(a[i])<<endl;
   }
}