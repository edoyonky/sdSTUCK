#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

typedef struct data{
	string nama;
	string posisi;
	int no;
}dData;

class simpul
{
	public :
		dData datapemain;
		simpul* pBerikutnya;
		
		
		simpul(string nam,string pos, int no)
		{
			datapemain.nama = nam;
			datapemain.posisi= pos;
			datapemain.no= no;
			pBerikutnya = NULL;
		}
		
		void tampilSimpul()
		{
			cout << datapemain.no << "--->" << datapemain.nama << "--->" << datapemain.posisi<<endl;
		}
};

class linkedlist
{
	private :
		simpul* pPertama;
	
	public :
		linkedlist() : pPertama(NULL)
		{}
		
		~linkedlist()
		{
			simpul* pSekarang = pPertama;
			while(pSekarang!=NULL)
			{
				simpul* pLama = pSekarang;
				pSekarang = pSekarang->pBerikutnya;
				delete pLama;
			}
		}
		
		bool apaKosong()
		{
			return (pPertama==NULL);
		}
		
		void sisipPertama(string nam, string pos, int no)
		{
			simpul* pSimpulBaru = new simpul(nam,pos,no);
			pSimpulBaru->pBerikutnya = pPertama;
			pPertama = pSimpulBaru;
		}
		
		void hapusPertama()
		{
			simpul* pTemp = pPertama;
			pPertama = pPertama->pBerikutnya;
			delete pTemp;
		}
		
		void tampilSenarai()
		{
			simpul* pSekarang = pPertama;
			if(pSekarang==NULL)
			{
				cout << "STACK KOSONG!!!";
			}
			while(pSekarang!=NULL)
			{
				pSekarang->tampilSimpul();
				pSekarang = pSekarang->pBerikutnya;
			}
			cout << endl;
		}
};

class stacklist
{
	private :
		linkedlist* pSenarai;
	
	public :
		stacklist()
		{
			pSenarai = new linkedlist;
		}
		
		~stacklist()
		{
			delete pSenarai;
		}
		
		void push(string nam, string pos, int no)
		{
			pSenarai->sisipPertama(nam,pos,no);
		}
		
		void pop()
		{
			pSenarai->hapusPertama();	
		}
		
		bool apaKosong()
		{
			return (pSenarai->apaKosong());
		}
		
		void tampilTumpukan()
		{
			pSenarai->tampilSenarai();
		}
};

int main()
{
	stacklist stack;
	int pilih, no;
	string nama, posisi;
	do 
	{
		cout << "\n                 DATA PEMAIN SEPAKBOLA" << endl;
		cout << "\n=====================================================" << endl << endl;
		cout << "1. PUSH" << endl;
		cout << "2. POP" << endl;
		cout << "3. Tampil Data" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Masukkan Pilihan Anda : ";
		cin >> pilih;
		cout << "=====================================================" << endl;
	
		switch(pilih)
		{
			case 1 :
				cout << "\nNomer Punggung : "; cin >> no;
				cin.ignore(256,'\n');
				cout << "Nama : "; getline(cin,nama);
				cout << "Posisi: "; getline(cin,posisi);
				stack.push(nama,posisi,no);
				break;
				
			case 2 :
				stack.pop();
				break;
			
			case 3 :
				stack.tampilTumpukan();
				break;
				
			case 4 :
				exit(0);
				break;
				
			default :
				cout << "pilihan salah!!!"<<endl;
		}
	} while (true);
	getch();
	return 0;
}


