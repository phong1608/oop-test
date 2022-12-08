#include<iostream>
#include<string.h>
using namespace std;
class SinhVien{
	
	public:
		int msv;
		string hoten;
		float DBM;
		void Nhap()
		{
			cout<<"Nhap ma sinh vien: ";
			cin>>msv;
			cout<<"Nhap ho ten";
			cin.ignore();
			getline(cin,hoten);
			
		}
		virtual void NhapDiem()=0;
		virtual float GetDBM(){
			return DBM;
		}
		void Xuat()
		{
			cout<<"\nMa sinh vien "<<msv<<endl;
			cout<<"Ho va ten "<<hoten<<endl;
			cout<<"Diem bo mon "<<GetDBM()<<endl;
			cout<<DBM;
		}
		
		
};
class NienChe :public SinhVien{
	private:
		float CC;
		float KT;
		float DT;
	public:
		void NhapDiem()
		{
			cout<<"Nhap diem chuyen can : ";
			cin>>CC;
			cout<<"Nhap diem KT : ";
			cin>>KT;
			cout<<"Nhap diem thi : ";
			cin>>DT;
		}
		float GetDBM()
		{
			DBM = 0.1*CC + 0.2*KT + 0.7*DT;
			return DBM;
		}
		NienChe *next;
		
};
class BienChe :public SinhVien{
	protected:
		float DT;
		float KT;
	public:
	
		void NhapDiem()
		{
			cout<<"Nhap diem KT :";
			cin>>KT;
			cout<<"Nhap diem thi :";
			cin>>DT;
		}
		float GetDBM(){
			DBM = 0.4* KT + 0.6*DT;
			return DBM;
		};
		
		
};

main()
{
	NienChe *d = NULL, *c = NULL, *node = NULL;

	char ch = 't';

	while(ch=='t')

	{

		node = new NienChe;

		node->Nhap();
		node->NhapDiem();

		node->next = NULL;

		if(d==NULL)

		{

			d = node;

			c = node;

		}

		else

		{

			c->next = node;

			c = node;

		}

		cout<<endl<<"Tiep tuc (t: tiep): "; cin>>ch;

	}

	NienChe *s=d;
	NienChe *i=d,*j;
	for(NienChe *i=d;i!=NULL;i=i->next)
	{
		for(NienChe *j=i->next;j!=NULL;j=j->next)
		{
				if(i->DBM<j->DBM)
				{
					int msv1=i->msv;
					string ten ;	
					ten=i->hoten;
					i->msv=j->msv;
					i->hoten=j->hoten;
					j->msv=msv1;
					j->hoten=ten;
					float diem1=i->DBM;
					i->DBM =j->DBM;
					j->DBM=diem1;
				}
		}
	}
	
	while(s!=NULL)
	{
		s->Xuat();
		s=s->next;
		
		
	}
}
