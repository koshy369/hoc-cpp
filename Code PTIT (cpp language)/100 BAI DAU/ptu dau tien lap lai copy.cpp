#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    long long value;
    int index;
};

// Hàm so sánh để sắp xếp theo giá trị, nếu giá trị bằng nhau thì xếp theo vị trí
bool compare(Element a, Element b) {
    if (a.value == b.value) return a.index < b.index;
    return a.value < b.value;
}

void solve() {
    int n;
    cin >> n;
    vector<Element> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].value;
        a[i].index = i;
    }

    // Tự viết hoặc dùng sort có sẵn (vẫn là thuật toán tối ưu)
    sort(a.begin(), a.end(), compare);

    int min_idx = n + 1; // Vị trí xuất hiện của phần tử lặp lại đầu tiên
    long long result = -1;

    for (int i = 0; i < n - 1; i++) {
        // Nếu hai phần tử đứng cạnh nhau có giá trị bằng nhau
        if (a[i].value == a[i+1].value) {
            // Phần tử lặp lại là phần tử có index lớn hơn trong cặp
            if (a[i+1].index < min_idx) {
                min_idx = a[i+1].index;
                result = a[i].value;
            }
        }
    }

    cout << result << endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}