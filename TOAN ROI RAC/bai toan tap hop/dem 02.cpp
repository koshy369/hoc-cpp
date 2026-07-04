#include <bits/stdc++.h>

using namespace std;

set<int> hop_hai_th(set<int> a, set<int> b){
    for (int i: a){
        b.insert(i);
    }
    return b;
}
/*
    Cho trước bốn số nguyên dương a, b, k và m.
    Yêu cầu: Tìm số lượng t các số nguyên dương trong phạm vi từ a đến b là bội của k hoặc m.
    Dữ liệu: Vào từ tệp Input chuẩn gồm một dòng chứa bốn số nguyên dương a, b, k và m
            ,mỗi số không vượt quá 2^18 và a <= b.
    Kết quả: Ghi ra tệp Output chuẩn giá trị t tìm được.
*/
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long  a, b, k, m;
    cin>>a>>b>>k>>m;
    //số số chia hết cho k mà lớn hơn a 1 t hoặc bằng, vidu a=9,k 5=> 5,10=> 2 số
    long long k1=(a/k) +1 , m1=(a/m)+1;
    set<int> boi_k;
    set<int> boi_m;
    while(k1*k<=b){
        boi_k.insert(k1*k);
        k1++;
    }
    while (m1*m<=b){
        boi_m.insert(m1*m);
        m1++;
    }
    set<int> c= hop_hai_th(boi_k,boi_m);
    cout<<c.size()<<endl;

    return 0;
}