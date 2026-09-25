#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
#include <iostream>
#include <vector>
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
using namespace std;

// Hàm gộp 2 mảng con đã sắp xếp
void merge(vector<ll>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;//co ca mid
    int n2 = right - mid;// k co mid

    vector<int> L(n1), R(n2);

    // Copy dữ liệu ra 2 mảng tạm
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    
    // Bốc phần tử nhỏ hơn nhét vào mảng chính
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Vét nốt phần tử thừa của mảng L (nếu có)
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    
    // Vét nốt phần tử thừa của mảng R (nếu có)
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

// Hàm chia đôi đệ quy
void mergeSort(vector<ll>& arr, int left, int right) {
    if (left >= right) return; // Điểm dừng: mảng chỉ còn 1 phần tử

    int mid = left + (right - left) / 2; // Tránh tràn số so với (left + right)/2
    
    mergeSort(arr, left, mid);      // Cắt nửa trái
    mergeSort(arr, mid + 1, right); // Cắt nửa phải
    merge(arr, left, mid, right);   // Gộp lại
}
void out(vector<ll> k){
    for( int i=0; i<m; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
void solve(){
    
    cin>>n;
    a.assign(n,0);
    mergeSort(a, 0, a.size() - 1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    out(a);
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}

