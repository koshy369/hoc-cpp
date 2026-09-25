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

typedef struct Queen{
	int row;//hang
	int max_gt;
	vector<ViTri> gt;
}Queen;

vector<Queen> Q;
vb danh_dau;
vi cur_path, results;
vb cheo1,cheo2;
int n;
ll max_val;
db sum_max[maxN]; // Lưu tổng năng suất max từ người i đến người cuối cùng

// sắp xếp từ max đến min vì cho nó đạt lượng giá trị cần tìm nhanh hơn=> cái nhỏ bị loại sớm
// nếu xếp từ min=> max, cái nhỏ mới vào đã được chọn rồi =>cần cập nhật max_val nhiều hơn

bool Compare_ng(const Queen &a,const Queen &b){
	return a.max_gt > b.max_gt;
}
void in(){
	n=8;
	Q.assign(n,Queen());
	danh_dau.assign(n,0);
	cur_path.clear();
	max_val = 0;
	cheo1.assign(15,0);
	cheo2.assign(15,0);

	for(int i=0; i<n; i++){
	 	Q[i].max_gt= 0;
		Q[i].row=i;
	 	for (int j=0; j<n; j++){
	 		ViTri cviec;
	 		cviec.col=j;
	 		cin>> cviec.gia_tri;
	 		
	 		Q[i].gt.push_back(cviec);
	 		if(Q[i].max_gt < cviec.gia_tri){
	 			Q[i].max_gt = cviec.gia_tri;
			}
		}
	}
	sort(Q.begin(), Q.end(),Compare_ng);
	if(n>0){ 
		// lượng còn lại lớn nhất có thể lấy => chạy từ n-1 đến 0
		sum_max[n-1]=Q[n-1].max_gt;
		for(int i=n-2;i>=0 ; i--){
			sum_max[i]= sum_max[i+1]+Q[i].max_gt;
		}
	}
}

void Try(int i, int cur_val){
	if(i==n){
		if(max_val < cur_val)                                                                                                                                                        max_val = cur_val;
		return;
	}
	
	double g=cur_val+sum_max[i];

	if(g<=max_val) return;

	for (int j=0; j<n; j++){
		int v = Q[i].gt[j].col,
			u=Q[i].row;

		int c1 =v-u + 7,
			c2= v+u;

		if(!danh_dau[v]&& !cheo1[c1] && !cheo2[c2]){  // chưa thử
			danh_dau[v]= 1;
			cheo1[c1] = 1;
			cheo2[c2] = 1; 
			cur_path.push_back(v);

			Try(i+1,cur_val+Q[i].gt[j].gia_tri);

			danh_dau[v]= 0;
			cheo1[c1] = 0;
			cheo2[c2] = 0; 
			cur_path.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int test; cin>>test;
	for( int i=1; i<=test; i++){
		in();
		Try(0,0);
	 	cout<<"Test "<<i<<": "<<max_val<<endl;
	}
	
}