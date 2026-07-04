#include <iostream>
#include <fstream>

using namespace std;
void solve() {
    char data;
    ifstream filedoc("PTIT.in",ios::in);
    if(!filedoc){
        exit(1);
        return;
    }
    ofstream  fileghi("PTIT.out",ios::out);
    if(!fileghi){
        exit(1);
        return;
    }
    while(filedoc.get(data)){
        fileghi<<data;
    }
    filedoc.close();
    fileghi.close();
    return;
}
int main() {
    solve();
    return 0;
}