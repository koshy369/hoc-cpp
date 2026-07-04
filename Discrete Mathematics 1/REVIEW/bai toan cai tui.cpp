#include <bits/stdc++.h>
using namespace std;

typedef struct Data{
    float sp,val,rate,kg;
}Data;
vector<Data> a;
float max_val=0;
vector<int> cur_path;
vector<int> result;
int n,p;
void tkiem (int e,int cur_val,int cur_kg){
    if(cur_kg > p) return;

    if(e>=n){
        if(cur_val >max_val){
            max_val=cur_val;
            for(int i=0; i<n; i++){
                result[a[i].sp]=cur_path[i];
            }
        }
        return;
    }
    // g= hien co+ rate_ngon_nhat*vi_tri_trong
    float g =cur_val +a[e].rate*(p-cur_kg);
    if(g<=max_val){
        return;
    }
    else {
        //lay
        if(cur_kg+a[e].kg<=p){
            cur_path.push_back(1);
            tkiem(e+1,cur_val + a[e].rate * a[e].kg, cur_kg + a[e].kg);
            cur_path.pop_back();
        }
        cur_path.push_back(0);
        tkiem(e+1,cur_val , cur_kg );
        cur_path.pop_back();
    }
}
bool SoSanh(const Data &c, const Data& b){
    return c.rate>b.rate;
}
int main(){
    cin>>n>>p;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin>>a[i].val;
        cin>>a[i].kg;
        a[i].sp=i;
        a[i].rate=a[i].val/a[i].kg;
    }
    sort(a.begin(), a.end(), SoSanh);
    tkiem(0,0,0);
    for(int i=0; i<n; i++){
        cout<<result[i]<<" ";
    }
    


}
