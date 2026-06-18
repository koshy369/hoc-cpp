#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct nextCity {
    int nextPlace;
    int chiphi;
    
    // Vẫn phải giữ cái này để sort mảng cho ngon
    bool operator<(const nextCity& other) const {
        return chiphi < other.chiphi;
    }
};

struct DuLich {
    int startPosition;
    vector<nextCity> nc; 
};

int n;
vector<DuLich> dlich;
vector<bool> danh_dau;
vector<int> di_chuyen; // lưu các thành phố đang đi qua
vector<int> results;  

double min_val = 1e9;  // Kỷ lục rẻ nhất
int min_cp = INF;    // Chi phí đi lại rẻ nhất toàn ma trận 

void Try(int buoc, int hien_tai, double cur_val) {
    if (buoc > n) {
        double cp_ve = INF;
        for (auto& edge : dlich[hien_tai].nc) {
            if (edge.nextPlace == 1) {
                cp_ve = edge.chiphi;
                break;
            }
        }
        
        if (cur_val + cp_ve < min_val) {
            min_val = cur_val + cp_ve;
            results = di_chuyen;
        }
        return;
    }
	// so buoc con lai: tinh ca buoc dang dung: n-buoc+1
	// lac quan nhat:
    double g = cur_val + (n - buoc + 1) * min_cp;
    if (g >= min_val) return; 

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (!(cin >> n)) return 0;

    dlich.resize(n + 1);
    danh_dau.resize(n + 1, false);
    di_chuyen.resize(n + 1);
    results.resize(n + 1);

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
        sort(dlich[i].nc.begin(), dlich[i].nc.end());
    }

    // Xuất phát từ thành phố 1
    di_chuyen[1] = 1;
    danh_dau[1] = true;
    // Bắt đầu bước thứ 2, đứng tại thành phố 1, tiền đã tiêu: 0
    Try(2, 1, 0);

    cout << min_val << "\n";
    for (int i = 1; i <= n; i++) {
        cout << results[i] << " ";
    }
    cout << "\n";

    return 0;
}