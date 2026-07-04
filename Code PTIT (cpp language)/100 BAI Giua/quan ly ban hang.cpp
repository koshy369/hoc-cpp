#include <bits/stdc++.h>

using namespace std;

struct KhachHang {
    string maKH, tenKH, gioiTinh, ngaySinh, diaChi;
};

struct MatHang {
    string maMH, tenMH, donVi;
    long long giaMua, giaBan;
};

struct HoaDon {
    string maHD, maKH, maMH;
    int soLuong;
    long long thanhTien, loiNhuan;
};

bool cmp(HoaDon a, HoaDon b) {
    if (a.loiNhuan != b.loiNhuan) {
        return a.loiNhuan > b.loiNhuan;
    }
    return a.maHD < b.maHD;
}

string formatID(string prefix, int n) {
    string s = to_string(n);
    while (s.length() < 3) s = "0" + s;
    return prefix + s;
}

int main() {
    ifstream fKH("KH.in");
    ifstream fMH("MH.in");
    ifstream fHD("HD.in");

    int n;
    fKH >> n;
    map<string, KhachHang> dsKH;
    for (int i = 1; i <= n; i++) {
        fKH.ignore();
        KhachHang x;
        x.maKH = formatID("KH", i);
        getline(fKH, x.tenKH);
        getline(fKH, x.gioiTinh);
        getline(fKH, x.ngaySinh);
        getline(fKH, x.diaChi);
        dsKH[x.maKH] = x;
    }

    int m;
    fMH >> m;
    map<string, MatHang> dsMH;
    for (int i = 1; i <= m; i++) {
        fMH.ignore();
        MatHang x;
        x.maMH = formatID("MH", i);
        getline(fMH, x.tenMH);
        getline(fMH, x.donVi);
        fMH >> x.giaMua >> x.giaBan;
        dsMH[x.maMH] = x;
    }

    int k;
    fHD >> k;
    vector<HoaDon> dsHD(k);
    for (int i = 0; i < k; i++) {
        string mkh, mmh;
        int sl;
        fHD >> mkh >> mmh >> sl;
        
        dsHD[i].maHD = formatID("HD", i + 1);
        dsHD[i].maKH = mkh;
        dsHD[i].maMH = mmh;
        dsHD[i].soLuong = sl;
        
        MatHang mh = dsMH[mmh];
        dsHD[i].thanhTien = (long long)sl * mh.giaBan;
        dsHD[i].loiNhuan = dsHD[i].thanhTien - ((long long)sl * mh.giaMua);
    }

    sort(dsHD.begin(), dsHD.end(), cmp);

    for (auto x : dsHD) {
        KhachHang kh = dsKH[x.maKH];
        MatHang mh = dsMH[x.maMH];
        cout << x.maHD << " " << kh.tenKH << " " << kh.diaChi << " " 
             << mh.tenMH << " " << x.soLuong << " " << x.thanhTien << " " << x.loiNhuan << endl;
    }

    fKH.close();
    fMH.close();
    fHD.close();
    return 0;
}