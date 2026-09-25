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
typedef struct ViTri{
	int col;//cot
	int gia_tri;
}ViTri;

typedef struct Rook{
	int max_gt;
	vector<ViTri> gt;
}Rook;

vector<Rook> R;
vector<vi> save;
vb danh_dau;
vi cur_path;
int n,k;
ll max_val;
db sum_max[maxN]; // Lưu tổng năng suất max từ người i đến người cuối cùng

// sắp xếp từ max đến min vì cho nó đạt lượng giá trị cần tìm nhanh hơn=> cái nhỏ bị loại sớm
// nếu xếp từ min=> max, cái nhỏ mới vào đã được chọn rồi =>cần cập nhật max_val nhiều hơn
void in(){
	cin>>n>>k;
	R.assign(n,Rook());
	danh_dau.assign(n,0);
	cur_path.clear();
	max_val = 0;

	for(int i=0; i<n; i++){
	 	R[i].max_gt= 0;
	 	for (int j=0; j<n; j++){
	 		ViTri cviec;
	 		cviec.col=j;
	 		cin>> cviec.gia_tri;
	 		
	 		R[i].gt.push_back(cviec);
	 		if(R[i].max_gt < cviec.gia_tri){
	 			R[i].max_gt = cviec.gia_tri;
			}
		}
	}
}

void Try(int i, int SUM){
	if(i==n){
		if(SUM==k){
			save.push_back(cur_path);
		}                                                                                                                                                     max_val = SUM;
		return;
	}
	for (int j=0; j<n; j++){
		int v = R[i].gt[j].col;

		if(!danh_dau[v]){  // chưa thử
			danh_dau[v] = 1;
			cur_path.push_back(v+1);

			Try(i+1, SUM + R[i].gt[j].gia_tri);

			danh_dau[v] = 0;
			cur_path.pop_back();
		}
	}
}
void out(){
	size_t len= save.size();
	cout<<len<<"\n";
	for(auto x: save){
		for(auto y: x){
			cout<<y<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		in();
		Try(0,0);
	 	out();
	
}