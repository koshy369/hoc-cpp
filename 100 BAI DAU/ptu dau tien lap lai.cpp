#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    long long value;
    int index;
};

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

    sort(a.begin(), a.end(), compare);

    int min_idx = n + 1;
    long long result = -1;

    for (int i = 0; i < n - 1; i++) {
        if (a[i].value == a[i+1].value) {
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