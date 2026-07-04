#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct nextCity {
    int nextPlace;
    int chiphi;

    bool operator<(const nextCity& other) const {
        return chiphi < other.chiphi;
    }
};

struct DuLich {
    int startPosition;
    vector<nextCity> nc; 
};
struct Result{
    vector<int>kqua;
    int chi_phi;
};

int n;
vector<DuLich> dlich;
vector<bool> danh_dau;
vector<int> di_chuyen; // lưu các thành phố đang đi qua
vector<Result> KQ;  

long long min_val = 1e9;  // Kỷ lục rẻ nhất
int min_cp = INF;    // Chi phí đi lại rẻ nhất toàn ma trận 
void in(){
    cin >> n;

    dlich.resize(n + 1);
    danh_dau.resize(n + 1, false);
    di_chuyen.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        dlich[i].startPosition = i;
        for (int j = 1; j <= n; j++) {
            int chiphi;
            cin >> chiphi;
            if (i != j) {
                dlich[i].nc.push_back({j, chiphi});
                if (chiphi < min_cp) {
                    min_cp = chiphi; // Tìm luôn cạnh rẻ nhất toàn cục ở đây
                }
            }
        }
    }
    

    // Xuất phát từ thành phố 1
    di_chuyen[1] = 1;
    danh_dau[1] = true;
}
void Try(int buoc, int hien_tai, double cur_val) {
    if (buoc > n) {
        double cp_ve = INF;
        for (auto& edge : dlich[hien_tai].nc) {
            if (edge.nextPlace == 1) {
                cp_ve = edge.chiphi;
                break;
            }
        }
        cur_val+=cp_ve;
        if (cur_val <= min_val) {
            min_val = cur_val;
            Result save;
            save.kqua= di_chuyen;
            save.chi_phi=min_val ;
            KQ.push_back(save);
        }
        return;
    }
	// so buoc con lai: tinh ca buoc dang dung: n-buoc+1
	// lac quan nhat:
    double g = cur_val + (n - buoc + 1) * min_cp;
    if (g > min_val) return; 

    for (auto& edge : dlich[hien_tai].nc) {
        int v = edge.nextPlace;
        double cp = edge.chiphi;

        if (!danh_dau[v]) {
            di_chuyen[buoc] = v;
            danh_dau[v] = true;

            Try(buoc + 1, v, cur_val + cp);

            danh_dau[v] = false;
        }
    }
}

void out(){
    int sl=0;
    for (const Result row : KQ) {
        if (row.chi_phi == min_val) sl++;
    }
    cout << min_val<<" ";
    if (sl>1) cout<<sl;
    cout<< endl;
    for (const Result row : KQ) {
        if (row.chi_phi == min_val){
            for (int i=1;i<=n;i++) {
                 cout << row.kqua[i] << " ";
            }
            cout << endl;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    in();
    // Bắt đầu bước thứ 2, đứng tại thành phố 1, tiền đã tiêu: 0
    Try(2, 1, 0); 
    out();
    return 0;
}