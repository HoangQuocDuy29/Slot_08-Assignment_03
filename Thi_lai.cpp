#include<iostream>
#include<string.h>
using namespace std;
class NGUOI{
	private:
		char ht[20];
		int cmnd;
		char hk[10];
		public:
			NGUOI(char*hoten = "",int chungminhthu=0,char*hokhau=""){
				strcpy(ht,"hoten");
				cmnd=chungminhthu;
				strcpy(hk,"hokhau");
			}
			~NGUOI(){}
		void nhap(){
			fflush(stdin);
			cout<<"nhap ho va ten: ";cin.getline(ht,20);
			cout<<"nhap so cmnd: ";cin>>cmnd;
			cin.ignore();
			cout<<"nhap ho khau: ";cin.getline(hk,10);
		}
		void xuat(){
			cout<<"ho va ten la: "<<ht<<endl;
			cout<<"so cmnd la: "<<cmnd<<endl;
			cout<<"ho khau la: "<<hk<<endl;
		}
};
class NV:public NGUOI{
	
	private:
		int mnv;
		float doanhthu;
	public:
		NV(char*hoten = "",int chungminhthu=0,char*hokhau="",int ma=0,float dt = 0):NGUOI(hoten,chungminhthu,hokhau){
			mnv = ma;
			doanhthu = dt;
		}
		~NV(){}
		void nhap(){
			fflush(stdin);
			cout<<"nhap ma nhan vien: ";cin>>mnv;
			cout<<"nhap doanh thu: ";cin>>doanhthu;
		}
		void xuat(){
			cout<<"ma nhan vien la: "<<mnv<<endl;
			cout<<"doanh thu cua nhan vien la: "<<doanhthu<<endl;
			cout<<"luong cua nhan vien la: "<<tinhluong();
		}
			friend istream& operator >> (istream &is, NV &a){
				a.nhap();
			}
			friend ostream& operator << (ostream &os, NV a){
				a.xuat();
			}
			int getdoanhthu(){
				return doanhthu;
			}
			float tinhluong(){
				if(doanhthu > 100)
				return 10;
				if(doanhthu >= 50)
				return 8;
				return 6;
			}
				bool operator > (float n ){
				if(doanhthu>n)
				return true;
			else
			return false;
			}
};
int main(){
	int n,m;
	cout<<"\n Nhap so nguoi : ";cin>>n;
	cout<<"\n Nhap so nhan vien :";
	cin>>m;
	NGUOI *d =  new NGUOI[n];
    for(int i; i<n; i++){
   	cout<<"\n Nhap thong tin nguoi thu "<<i+1<<":"<<endl;
    d[i].nhap();
	}
	cout<<"\n ---------------------Danh sach nguoi ------------------------"<<endl;
	for(int i = 0; i<n;i++){
		d[i].xuat();
	}
	NV *e = new NV[m];
	for(int i = 0; i<m;i++){
		cout<<"\n Nhap thong tin nhan vien thu "<<i+1<<":"<<endl;
		e[i].nhap();
	}
	cout<<"\n ======================Danh sach nhan vien======================="<<endl;
	for(int i = 0; i<m; i++){
		e[i].xuat();
	}
	cout<<"\n -------------------------Danh sach nhan vien co  doanh thu >100 trieu-----------------------------"<<endl;
	for(int i=0;i<m;i++){
		if(e[i].getdoanhthu()>100){
			e[i].xuat();
		}
	}
//	cout<<"\n----------------------------DAnh sach nhan vien o ha noi co luong >10 tr-------------------------";
//	for(int i = 0; i<n;i++){
//		strcmpi()	}
	return 0;
}

