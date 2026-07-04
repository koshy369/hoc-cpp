#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 
cấu hình đầu: 12345=> cấu hình cuối :54321
=> cấu hình sau luôn lớn hơn cấu hình trước(neu k phai la trc 12345, sau 54321)
*/

void solve(vector<int>& a, int n) {
    int i=-1,j;
    // tìm vị trí đầu tiên số đứng trước nhỏ hơn số đứng sau
    for (i=n-2; i>=0 ;i-- ){
        if(a[i]<a[i+1]){
            break;
        }
    }//-> tim duoc a[i] = 2

    // neu nhu la cau hinh vdu: 5 4 3 2 1
    if(i< 0){
        cout<<"0"<<endl;
        return;
    }
    //Tìm số nhỏ nhất trong các số bên phải a[i] mà vẫn lớn hơn a[i].
    int min = n-1; 
    while (a[min] <= a[i]) min--;//-> tim duoc 4
    
    swap(a[i],a[min]);// doi cho
    //->1 3 4 5 2
    // Bước 4: Lật ngược đoạn từ i + 1 đến cuối dãy
    // Vì sau khi swap, đoạn sau đang giảm, lật ngược lại để nó thành nhỏ nhất có thể(tăng dần)
    // vd doan sau 321 thành 123
    
    reverse(a.begin()+  i + 1, a.end());
    //-> nho nhat gom 1,2,3,4,5 ma lon hon 13254 la 13425
    for (int k=0; k<n;k++ )
        cout<< a[k]<<" ";
    cout<< endl;
}

int main() {
    int n,k;
    cin >> n>> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (k--) solve(a,n);
    return 0;
}