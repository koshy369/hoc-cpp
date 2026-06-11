#include <iostream>  // (wcin, wcout)
#include <string>    // (wstring) để hỗ trợ tiếng Việt
#include <vector>    // vector 
#include <fcntl.h>   // cấu hình các chế độ điều khiển tệp (phục vụ _setmode)
#include <io.h>      // vào/ra ỏ mức thấp (phục vụ _setmode để in tiếng Việt trên Console)
#include <thread>    // this_thread::sleep_for (tạm dừng chương trình)
#include <chrono>    // hàm sleep
#include <algorithm> //  hàm std::shuffle để trộn ngẫu nhiên 
#include <random>    // sinh số ngẫu nhiên (random_device, mt19937)
#include <sstream>   // wstringstream 
#include <limits>    // (xóa bộ đệm wcin.ignore)
#include <iomanip>
using namespace std;

struct TuVung {
    wstring en = L"", vn = L"", loaitu = L"";
    int nho=0;
};
void le() {
    wcout<<L"                ";
}
void intienDo(int n,int m){
    float k =(n*100.0/m);
    le();
    wcout <<fixed<<setprecision(2)<<k<<L" %  [";
    for(int i=0;i<100;i+=2){
        if (i<k) wcout<<L"■";
        else wcout<<L"-";
    }
    wcout<<"]\n";
}

wstring trim(const wstring& s) {
    size_t first = s.find_first_not_of(L" \t");
    if (string::npos == first) return L"";
    size_t last = s.find_last_not_of(L" \t");
    return s.substr(first, (last - first + 1));
}
void xoaDong(int n) {
    wcout << L"\r\033[K";
    for (int i = 0; i < n-1; i++) {
        // \033[A: Di chuyển con trỏ lên 1 dòng
        // \033[K: Xóa sạch nội dung dòng đó từ vị trí con trỏ
        wcout << L"\033[A\r\033[K";
    }
    wcout.flush();
}

void tuthuong(wstring &s){
    for (size_t i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
}

void nhap(wstring &s,wstring &S){
    wstring s1=L"";
    getline(wcin,s1);
    wstringstream ss(s1);
    wstring t;
    while (ss>>t){
        if(t[0]=='('||t[t.length()-1]==')') S+=t;
        else{
            s+=t;
            s+=' ';
        }
    }
    s.erase(s.length()-1);
}
void solve() {
    int tiendo=0;//tiến độ
    int sotuvung;

    wcout<<endl<<endl<<endl;
    le();
    wcout << L"Nhập số từ vựng: ";
    wcin >> sotuvung;
    wcin.ignore();

    vector<TuVung> a(sotuvung);
    le();
    wcout << L"Nhập (Dòng 1: Anh, Dòng 2: Việt):" << endl;
    for (int i = 0; i < sotuvung; i++) {
        wstring tempEn, tempVn,temploaitu;
        le();
        nhap(tempEn,temploaitu);
        tuthuong(tempEn);
        le();
        getline(wcin, tempVn);
        tuthuong(tempVn);
        a[i].en = trim(tempEn);
        a[i].vn = trim(tempVn);
    }


    system("cls"); // xoa ca man hinh
    wcout<<endl<<endl<<endl;
    random_device rd;
    mt19937 g(rd());
    int lap = 1;

    while (true) {
        int lanNho=2;
        shuffle(a.begin(), a.end(), g);
        le();
        wcout << L"----------- Lần lặp thứ " << lap << L" -----------" << endl;
        for (int i = 0; i < sotuvung; i++) {
            if(a[i].nho<lanNho){
                int dunglandau=true;
                while (true) {
                    intienDo(tiendo,sotuvung*lanNho);
                    le();
                    wcout << L"Nghĩa: " << a[i].vn <<" "<<a[i].loaitu<< endl;
                    le();
                    wcout << L"Tiếng Anh?: ";
                    wcout.flush();
                    wstring s;
                    getline(wcin, s);
                    s = trim(s);
                    tuthuong(s);
                    if (s != a[i].en) {
                        le();
                        wcout << L"❌ Sai rồi! (Đúng là: " << a[i].en << L")";
                        wcout.flush();
                        wcin.get();//nhan enter de tiep tuc
                        xoaDong(5); // Xóa sạch n dòng đã in
                        dunglandau=false;
                    } else {
                        le();
                        wcout << L"✅ Đúng rồiiii!";
                        wcout.flush();
                        this_thread::sleep_for(chrono::milliseconds(600));
                        xoaDong(4);
                        break;
                    }
                }
                if(dunglandau){
                    a[i].nho++;
                    tiendo++;
                }
                if(a[i].nho==lanNho){
                    le();
                    wcout<<L"+1 từ👏";
                    wcout.flush();
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    xoaDong(1);
                }
            }
        }
        lap++;
        if (tiendo==sotuvung*lanNho) break;
        xoaDong(1);
    }
    le();
    wcout<<L"Chúc mừng bạn đã làm xong🎉👏"<<endl;
}

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    solve();
    return 0;
}