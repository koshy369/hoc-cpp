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
	int nang_suat;
}CongViec;

typedef struct Nguoi{
	int startPosition;
	int max_ns;
	vector<CongViec> cv;
}Nguoi;

vector<Nguoi> ng;
vb danh_dau;
vi cur_path, results;
int n;
double max_val=0;
double sum_max[maxN]; // Lưu tổng năng suất max từ người i đến người cuối cùng

bool Compare_ng(const Nguoi &a,const Nguoi &b){
	return a.max_ns > b.max_ns;
	// =>nang suat cang lon cang hieu qua
	// sắp xếp từ max đến min vì cho nó đạt lượng giá trị cần tìm nhanh hơn=> cái nhỏ bị loại sớm
	// nếu xếp từ min=> max, cái nhỏ mới vào đã được chọn rồi =>cần cập nhật max_val nhiều hơn
}
bool Compare_cv(const CongViec &a,const CongViec &b){
	return a.nang_suat > b.nang_suat;
	// logic như so sanh nguoi
}
void in(){
	cin>>n;
	ng.resize(n);
	danh_dau.resize(n);
	results.resize(n);
	
	for(int i=0; i<n; i++){
	 	ng[i].startPosition=i;
	 	ng[i].max_ns= 0;
	 	
	 	for (int j=0; j<n; j++){
	 		CongViec cviec;
	 		cviec.viec=j;
	 		cin>> cviec.nang_suat;
	 		
	 		ng[i].cv.push_back(cviec);
	 		if(ng[i].max_ns < cviec.nang_suat){
	 			ng[i].max_ns = cviec.nang_suat;
			}
		}
		sort(ng[i].cv.begin(), ng[i].cv.end(),Compare_cv);
	}
	sort(ng.begin(), ng.end(),Compare_ng);
	if(n>0){
		// tiền xử lý tính biên g: lượng còn lại lớn nhất có thể lấy => chạy từ n-1 đến 0
		sum_max[n-1]=ng[n-1].max_ns;
		for(int i=n-2;i>=0 ; i--){
			sum_max[i]= sum_max[i+1]+ng[i].max_ns;
		}
	}
}

void Try(int i, int cur_val){
	if(i==n){
		if(max_val < cur_val){
			max_val = cur_val;

			for (int j=0; j<n; j++){
	 			results[ng[j].startPosition]=cur_path[j]+1;
				// gán vị trí ban đầu là làm việc gì
			}
		}
		return;
	}
	
	double g=cur_val+sum_max[i];

	if(g<=max_val) return; //chặt

	for (int j=0; j<n; j++){
		int v = ng[i].cv[j].viec;

		if(!danh_dau[v]){
			danh_dau[v]= 1;
			cur_path.push_back(v);

			Try(i+1,cur_val+ ng[i].cv[j].nang_suat);

			danh_dau[v]= false;
			cur_path.pop_back();
		}
	}
}

void out(){
	cout<<max_val<<endl;
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