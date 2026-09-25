#include<bits/stdc++.h>
using namespace std;
vector<string> a;
int n;
string sinh(string s){
   int len=s.length();
   int i= len-1;
   while (i>=0 && s[i]=='1'){
      s[i--]='0';
   }
   if (i>=0){
      s[i]='1';
   }
   else{
      s="";
      for(int i=0;i<len;i++) s+="0";
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