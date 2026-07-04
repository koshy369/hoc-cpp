#include<bits/stdc++.h>
using namespace std;

typedef struct dovat{
    double startPosition, value, kg, rate;
} dovat;

vector<int> results;
double max_val=0;

/*
    cur_val: gia tri
    cur_kg: kg da nhet
    vector cur_path: ghi lai hanh trinh di xuong re nhanh

*/
void timkiem(int i, int cur_val, int cur_kg,int n, int P, vector<dovat>& things,vector<int>& cur_path){
    if(cur_kg > P) return;
    if(i==n){
        if(cur_val > max_val){
            max_val = cur_val;
            for(int k=0;k<n;k++){
                results[things[k].startPosition]= cur_path[k];
            }
        }
        return;
    }
    double g=cur_val + things[i].rate*(P - cur_kg);
    if(g <= max_val) return;
    
    if(things[i].kg<= P - cur_kg){ //xem lay duoc ko
        //neu lay
        cur_path[i]=1;
        timkiem(i+1, cur_val+ things[i].value, cur_kg +things[i].kg,n,P,things,cur_path);
        cur_path[i]=-1;
        
    }
    //khong lay
    cur_path[i]=0;
    timkiem(i+1, cur_val, cur_kg, n, P, things, cur_path);
    cur_path[i]=-1;
}
bool compare_handmade(const dovat a,const dovat b){
    return a.rate > b.rate;
}
int main(){
    int n,P; cin>>n>>P;
    vector<dovat> things(n);
    results.assign(n,0);
    vector<int> cur_path;
    cur_path.assign(n,-1);

    for(int i=0; i<n ; i++){
        things[i].startPosition=i;
        cin>> things[i].kg>>things[i].value;
        things[i].rate= things[i].value/things[i].kg;
    }
    sort(things.begin(),things.end(),compare_handmade);
    timkiem(0,0,0,n,P,things,cur_path);

    //in
    cout<<fixed<<setprecision(0)<<max_val<<endl;
    for (auto num: results){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}