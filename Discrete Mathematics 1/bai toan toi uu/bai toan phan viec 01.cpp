#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define maxN 100005
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define ml map<ll,int>
#define pb push_back
#define pob pop_back
#define vpii vector<pair<int,int>>
using namespace std;
typedef struct CongViec{
	int viec;
	int chiphi;
}CongViec;

typedef struct Nguoi{
	int startPosition;
	int min_cp;
	vector<CongViec> cv;
}Nguoi;

vector<Nguoi> ng;
vb danh_dau;
vi cur_path, results;
int n;
double min_val=1e9;

bool Comparee(const Nguoi &a,const Nguoi &b){
	return a.min_cp < b.min_cp;
	// nguoc lai bai 02, tgian cang nho cang tot, lớn càng ở sau thì sau này càng dễ loại
}
void in(){
	cin>>n;
	ng.resize(n);
	danh_dau.resize(n);
	results.resize(n);
	
	for(int i=0; i<n; i++){
	 	ng[i].startPosition=i;
	 	ng[i].min_cp= 1e9;
	 	
	 	for (int j=0; j<n; j++){
	 		CongViec cviec;
	 		cviec.viec=j;
	 		cin>> cviec.chiphi;
	 		
	 		ng[i].cv.push_back(cviec);
	 		if(ng[i].min_cp > cviec.chiphi){
	 			ng[i].min_cp = cviec.chiphi;
			}
		}
	}
	sort(ng.begin(), ng.end(),Comparee);
}


double timCanDuoi(int i, int cur_val){
	double g=cur_val;
	for(int k=i; k<n; k++){
		int min=1e9;
	 	for (int j=0; j<n; j++){
	 		int v = ng[k].cv[j].viec;
	 		if(!danh_dau[v]){
	 			if(min > ng[k].cv[j].chiphi){
	 				min = ng[k].cv[j].chiphi;
				}
			}
		}
		if (min!= 1e9) g+=min;
	}
	return g;
}

void Try(int i, int cur_val){
	if(i==n){
		if(min_val > cur_val){
			min_val = cur_val;

			for (int j=0; j<n; j++){
	 			results[ng[j].startPosition]=cur_path[j]+1;
			}
		}
		return;
	}
	
	double g= timCanDuoi(i,cur_val);

	if(g>=min_val) return;

	for (int j=0; j<n; j++){
		int v = ng[i].cv[j].viec;

		if(!danh_dau[v]){
			danh_dau[v]= 1;
			cur_path.push_back(v);

			Try(i+1,cur_val+ng[i].cv[j].chiphi);

			danh_dau[v]= false;
			cur_path.pop_back();
		}
	}
}

void out(){
	cout<<min_val<<endl;
	 for(int i=0; i<n; i++){
	 	cout<<results[i]<<" ";
	 }
	 cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	in();
	Try(0,0);
	out();
}