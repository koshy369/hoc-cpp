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
 vector<dovat> things;
 vector<int> cur_path;
 int P,n;
void timkiem(int i, double cur_val, double cur_kg) {
    // rach balo
    if (cur_kg > P) return;
    
    //da duyet het do vat
    if (i == n) {
        if (cur_val > max_val) {
            max_val = cur_val; // UPDATE FOPT
            
            // Ánh xạ lại phương án về đúng thứ tự đồ vật 
            for (int k = 1; k <= n; k++) {
                results[things[k].startPosition] = cur_path[k];
            }
        }
        return;
    }
    
    // cận trên g= gtri hiện tại+rate hàng ngon nhất *kl còn lại
    double g = cur_val + (P - cur_kg) * things[i].rate;
    
    if (g <= max_val) return; 

    // NHÁNH LẤY
    if (cur_kg + things[i].kg <= P) {
        cur_path.push_back(1);
        timkiem(i + 1, cur_val + things[i].value, cur_kg + things[i].kg);
        cur_path.pop_back(); // Quay lui 
    }

    // NHÁNH KHÔNG LẤY (thử với các đồ vật sau đồ vật bỏ qua)
    cur_path.push_back(0);
    timkiem(i + 1, cur_val, cur_kg);
    cur_path.pop_back(); // Quay lui
}

bool comparee(const dovat &a,const dovat &b){
    return a.rate > b.rate;
}

int main() {
     cin>>n>>P;
    //>>so_do_vat>>trong_luong
    things.resize(n);
    results.assign(n, 0);
    
    for(int i=1;i<=n;i++){
        cin>>things[i].kg;
        things[i].startPosition=i;
        cin>>things[i].value;
        things[i].rate =things[i].value/things[i].kg;
    }

    sort( things.begin(),things.end(),comparee);
    timkiem(1, 0, 0);

    cout<< fixed << setprecision(0) << max_val <<endl; 
    for(int i=1;i<=n;i++){
        cout<<results[i]<<" ";
    }

    return 0;
}