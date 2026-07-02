#include <bits/stdc++.h>
using namespace std;

int main(){
	//ghi
    ofstream outFile("demo.txt"); // outFile chi la cai ten(doi cung dc)
    outFile<<"He lo";
    outFile.close();
    //doc
    ifstream inFile("demo.txt");
    string data;
    getline(inFile,data);
    cout<< data;
    inFile.close();
}
