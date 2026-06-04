#include <bits/stdc++.h>
using namespace std;

double money=0,empty,g;
vector<int>  save;

typedef struct dovat{
    double order, value, kg, rate;
}dovat;


// cur_val là tổng tiền tích lũy
// cur_kg là lượng kluong đã nhét
//cur_path đóng vai trò ghi chép lại hành trình đi xuống nhánh
void timkiem(int i, double cur_val, double cur_kg, int P, int n, vector<dovat>& things, vector<int>& cur_path) {
    // rach balo
    if (cur_kg > P) return;
    
    //da duyet het do vat
    if (i == n) {
        if (cur_val > money) {
            money = cur_val; // UPDATE FOPT
            
            // Ánh xạ lại phương án về đúng thứ tự đồ vật 
            for (int k = 0; k < n; k++) {
                save[things[k].order] = cur_path[k];
            }
        }
        return;
    }
    
    // cận trên g= gtri hiện tại+rate hàng ngon nhất *kl còn lại
    double g = cur_val + (P - cur_kg) * things[i].rate;
    
    //(g)<= kỷ lục-> Chặt
    if (g <= money) return; 

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
    cout<<"So loai do vat: "; int n; cin>>n;
    cout<<"Trong luong tui: "; int P; cin>>P;
    vector<dovat>  things(n);
    save.assign(n, 0);
    vector<int> cur_path;
    
    cout<<"Vector trong luong: ";
    for(int i=0;i<n;i++){
        cin>>things[i].kg;
    }
    cout<<"Vector gia tri su dung: ";
    for(int i=0;i<n;i++){
        things[i].order=i;
        cin>>things[i].value;
        things[i].rate =things[i].value/things[i].kg;
    }

    sort( things.begin(),things.end(),comparee);
    timkiem(0, 0, 0, P, n, things, cur_path);

    cout<<fixed<<setprecision(1)<<"chi phi toi uu: "<<money<<endl;
    cout<<"Phuong an toi uu: ";
    for(int i=0;i<n;i++){
        cout<<save[i]<<" ";
    }
    return 0;
}