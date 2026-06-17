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
#include <windows.h>
#include <cwchar>
#include <string.h>
using namespace std;
struct TuVung {
    wstring en = L"";
    wstring vn = L"";
    wstring loaitu = L"";
    wstring phienam = L"";
    int nho=0;
};
vector<TuVung> a;
int sotuvung;
int tiendo=0;
random_device rd;
mt19937 g(rd());
void nhapstring(wstring &s){
    while (true) {
        getline(wcin,s);
        if (!s.empty()) break;
    }
}

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
    wcout<<"]"<<endl<<endl;
}

wstring trim(const wstring& s) {
    size_t first = s.find_first_not_of(L" \t");
    if (wstring::npos == first) return L"";
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

void InfoWord(wstring &s,wstring &S,wstring &K){
    wstring s1=L"";
    nhapstring(s1);
    wstringstream ss(s1);
    wstring t;
    int ok=1;
    while (ss>>t){
        int len=t.length()-1;
        if(t[0]=='('||t[len]==')') S+=t;
        else if(t[0]=='/'){
            K+=t;K+=' ';
            if( t[len]!='/') ok=0;
        }
        else if(ok==0){
            K+=t;K+=' ';
            if(t[len]=='/')  ok=1;           
        }
        else{
            s+=t;s+=' ';
        }
    }
    s.erase(s.length()-1);
}

void Input(vector<TuVung> &a,int sotuvung){
    le(); wcout << L"Nhập (Dòng 1: Anh, Dòng 2: Việt):" << endl;
    for (int i = 0; i < sotuvung; i++) {
        wstring tempVn;

        le();
        InfoWord(a[i].en ,a[i].loaitu,a[i].phienam);
        tuthuong(a[i].en);
        le();
        nhapstring(tempVn);
        tuthuong(tempVn);
        a[i].vn = trim(tempVn);
    }
}

void MemoryCard(){
    /*
    cach hoat dong:
    hien EN va phien am,enter de xem nghia, neu tu do ok thi k hien lai nua
    */
   tiendo=0;
    while (true) {
        shuffle(a.begin(), a.end(), g);
        for (int i = 0; i < sotuvung; i++) {
            if(a[i].nho!=1){
                int solansai =0;
                intienDo(tiendo,sotuvung); //+2 ->den dong 2
                le();
                wcout <<L"Nghĩa:    " << a[i].vn <<" "<<a[i].loaitu<< endl; //+1 ->den dong 3

                le();
                if(a[i].phienam == L"") wcout << L"Phiên âm: "<<L"Không có trong đầu vào"; 
                else wcout<< L"Phiên âm: "<<a[i].phienam;
                
                wcout<<endl<<endl; //+2 ->den dong 5

                
                wcout.flush();
                wstring s;
                
                le(); wcout<<L"Nhấn phím bất kì để xem từ: ";// dong 5
                s=_getwch();//dong 5
                xoaDong(1);//dong 5
                le(); wcout<<L"Nghĩa: "<<a[i].en<<endl<<endl; //den dong 7

                le(); wcout << L"Oke chưa(1 để oke)======>>> "; //dong 7
                s=_getwch();//lay 1 ki tu,khong enter-> den dong 7

                if (s == L"1") {//nho roi
                    a[i].nho++;
                    tiendo++;
                }
                xoaDong(8);
            }
        }
        if (tiendo==sotuvung) break;
    }
    for(int i=0;i<sotuvung;i++){ //reset
        a[i].nho=0;
    }
    le(); wcout<<L"Muốn ghi nhớ lại không(1/0): ";
    int ok=-1;
    wcin>>ok;
    if (ok==1) {
        xoaDong(2);
        MemoryCard();
    }
    else xoaDong(2);
    return;
}

void wiriteAgain(){
    tiendo=0;
    int lap = 1;
    while (true) {
        int lanNho=2;
        shuffle(a.begin(), a.end(), g);
        for (int i = 0; i < sotuvung; i++) {
            if(a[i].nho<lanNho){
                int solansai =0;
                while (true) {
                    intienDo(tiendo,sotuvung*lanNho); //+2 ->den dong 3
                    le();
                    wcout <<L"Nghĩa:    " << a[i].vn <<" "<<a[i].loaitu<< endl; //+1 ->den dong 4

                    le();
                    if(a[i].phienam == L"") wcout << L"Phiên âm: "<<L"Không có trong đầu vào"; 
                    else if(a[i].nho< 1 || solansai>0){
                        // nếu chưa nhập đúng lần nào hoặc đã nhập đúng đc >=1 lần nhưng vòng này while lặp 2 lần trở lên  =>in phien am
                        wcout<< L"Phiên âm: "<<a[i].phienam;
                    }
                    else wcout << L"Phiên âm: "<<L"*Đã ẩn🫥 *"; 
                    
                    wcout<<endl<<endl; //+2 ->den dong 6

                    le();
                    wcout << L"======>>> ";
                    wcout.flush();
                    wstring s;
                    getline(wcin, s);//bam enter-> den dong 7
                    s = trim(s);
                    tuthuong(s);

                    if (s != a[i].en) { // sai
                        le();
                        wcout << L"❌ Sai rồi! (Đúng là: " << a[i].en << L")"<<endl;//+1 ->den dong 8
                        le();
                        wcout.flush();
                        system("pause");//nhan enter de tiep tuc--- den dong 9
                        xoaDong(9); // Xóa sạch n dòng đã in
                        solansai++;
                    } else {
                        if(solansai==0){
                            a[i].nho++;
                            tiendo++;
                        }

                        le(); wcout << L"✅ Đúng rồiiii! "; 
                        if (a[i].nho == lanNho || ( solansai >0 && a[i].nho > 1)){
                            //nếu như đã đủ lần nhớ hoặc đã nhập đúng đc 1 lần(kphai lan nay) mà while trong vòng for này bị sai ít nhât 1 lần
                            wcout<< a[i].phienam <<endl;//den dong 8
                            le();
                            wcout.flush();
                            system("pause"); //enter-> 9
                            xoaDong(9);
                        }
                        else {
                            this_thread::sleep_for(chrono::milliseconds(750));
                            xoaDong(7);
                        }
                        break;
                    }
                }
                
                if(a[i].nho==lanNho){
                    le();
                    wcout<<L"+1 từ👏";
                    wcout.flush();
                    this_thread::sleep_for(chrono::milliseconds(750));
                    xoaDong(1);
                }
            }
        }
        lap++;
        if (tiendo==sotuvung*lanNho) break;
    }
}

void solve() {
    //tiến độ

    wcout<<endl<<endl<<endl;
    le(); wcout << L"------------------ App học từ vựng =))💀 ------------------" << endl;

    wcout<< L"                Thẻ ghi nhớ _(1)" <<endl
         << L"                Viết lại_____(2)" <<endl
         << L"                Cả 2 ________(phím bất kì)" <<endl
         << L"                Lựa chọn: ";
    wstring choose;
    wcin>>choose;


    le(); wcout<< L"Nhập số từ vựng: ";
    wcin >> sotuvung;
    wcin.ignore();

    a.resize(sotuvung);
    Input(a,sotuvung);

    system("cls"); // xoa ca man hinh
    wcout<<endl<<endl<<endl;
    le();
    wcout << L"------------------ App học từ vựng =))💀 ------------------" << endl; //den dong 1
    if(choose==L"1") MemoryCard();
    else if(choose==L"2") wiriteAgain();
    else{
        MemoryCard();
        wiriteAgain();
    }
    le(); wcout<<L"Chúc mừng bạn đã làm xong🎉👏"<<endl;
    wcin.get();
}

int main() {
    // cấu trúc thông tin về font
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Chiều rộng font
    cfi.dwFontSize.Y = 24;                  // Chiều cao font (Kích cỡ chữ)
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;             // Độ đậm của chữ
    
    //đổi font
    wcscpy(cfi.FaceName, L"Roboto");
    
    // Áp dụng font 
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    solve();
    return 0;
}
