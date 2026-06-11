#include <bits/stdc++.h>
using namespace std;

double max_val=0;
vector<int>  results;

typedef struct dovat{
    double startPosition, value, kg, rate;
}dovat;


// cur_val là tổng tiền tích lũy
// cur_kg là lượng kluong đã nhét
//cur_path đóng vai trò ghi chép lại hành trình đi xuống nhánh
void timkiem(int i, double cur_val, double cur_kg, int P, int n, vector<dovat>& things, vector<int>& cur_path) {
    // rach balo
    if (cur_kg > P) return;
    
    //da duyet het do vat
    if (i == n) {
        if (cur_val > max_val) {
            max_val = cur_val; // UPDATE FOPT
            
            // Ánh xạ lại phương án về đúng thứ tự đồ vật 
            for (int k = 0; k < n; k++) {
                results[things[k].startPosition] = cur_path[k];
            }
        }
        return;
    }
    
    // cận trên g= gtri hiện tại+rate hàng ngon nhất *kl còn lại
    double g = cur_val + (P - cur_kg) * things[i].rate;
    
    //(g)<= kỷ lục-> Chặt
    if (g <= max_val) return; 

    // NHÁNH TRÁI: LẤY
    if (cur_kg + things[i].kg <= P) { //xem có nhét vừa không
        cur_path.push_back(1);
        timkiem(i + 1, cur_val + things[i].value, cur_kg + things[i].kg, P, n, things, cur_path);
        cur_path.pop_back(); // Quay lui 
    }

    // NHÁNH PHẢI:KHÔNG LẤY 
    cur_path.push_back(0);
    timkiem(i + 1, cur_val, cur_kg, P, n, things, cur_path);
    cur_path.pop_back(); // Quay lui
}
bool comparee(const dovat &a,const dovat &b){
    return a.rate > b.rate;
}
int main() {
     int n,P; cin>>n>>P;
        //>>do_vat>>trong_luong
    vector<dovat>  things(n);
    results.assign(n, 0);
    vector<int> cur_path;
    
    for(int i=0;i<n;i++){
        cin>>things[i].kg;
        things[i].startPosition=i;
        cin>>things[i].value;
        things[i].rate =things[i].value/things[i].kg;
    }

    sort( things.begin(),things.end(),comparee);
    timkiem(0, 0, 0, P, n, things, cur_path);

    cout<<fixed<<setprecision(0)<<max_val<<endl; //chi_phi_toi_ui
    for(int i=0;i<n;i++){
        cout<<results[i]<<" ";
    }
    return 0;
}