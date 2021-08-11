#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void baca(int m){
	string n[10]={"","Se","Dua ","Tiga ","Empat ","Lima ","Enam ","Tujuh ","Delapan ","Sembilan "};
	for (int i=0; i<10; i++){
		if (m==i)
		cout<<n[i];
	}
}
void proses(int nilai){
	int n,m;
	n=nilai%1000/100;
	if (n>0){
	baca(n);
	cout<<"ratus ";
	}
	n=nilai%100/10;  
	m=nilai%10/1;     
	if (n==1){				
		if (m==0)
		cout<<"sepuluh ";
		else {
		baca(m);
		cout<<"belas ";
		}
	}
	else {   
	baca(n);
	if(n>=1)
	cout<<"puluh ";
	    if (m>1)
		baca(m);
		if (m==1)
		cout<<"Satu ";
	}
}
void ubah(int angka){
	int nilai,x;
	nilai=angka/1000000000;
	proses(nilai);
	x=angka%1000000000000/1000000000;
	if (x!=0)
	cout<<"milyar ";
	nilai=angka/1000000;
	proses(nilai);
	x=angka%1000000000/1000000;
	if (x!=0)
	cout<<"juta ";					
	nilai=angka/1000;	
	proses(nilai);
	x=angka%1000000/1000;
	if (x!=0)
	cout<<"ribu ";			
	nilai=angka;		
	proses(nilai);
	if (angka==0)
	cout<<"nol";
	cout<<".";
}
int main(){
	int pilih,tjumlah,p=0,l=0,skor[99][99],mak=0,win=0,rata[99],jumlah[99];
	char menu;
	string nama[99],tnama;
	do
	{
		system("Color 09");
		cout<<"____________________________________________\n\n";
		cout<<"  MENU RANKING LOMPAT JAUH                 \n";
		cout<<"____________________________________________\n\n";
		cout<<"  1. Masukan Data Perlombaan                \n";
		cout<<"  2. Waktu Penilaian                        \n";
		cout<<"  3. Hasil Perlombaan                       \n";
		cout<<"  4. Keluar                                 \n";
		cout<<"____________________________________________\n";
		cout<<"\n - Masukan Pilihan : ";cin>>pilih;
		system ("cls");
		system("Color 0A");
		if (pilih==1){
			cout<<"____________________________________________\n\n";
			cout<<"  DATA PERLOMBAAN                           \n";
			cout<<"____________________________________________\n";
			cout<<"\n * Masukan Jumlah Peserta : ";cin>>p;
			cout<<endl;
			cin.ignore();
			for(int i=0; i<p; i++){
				cout<<"   - Nama Peserta ke-"<<i+1<<" Adalah : "; 
				getline(cin,nama[i]);
			}
			cout<<endl;
			cout<<" * Masukan Banyak Lompatan : ";cin>>l;
			cout<<endl;
			cout<<"\nInput [y] untuk kembali ke menu  ";
			cout<<"\nInput [z] untuk lanjut \n  :  ";cin>>menu;
			system ("cls");
			if (menu=='z')
			goto penilaian;
			if (menu!='y')
			break;
		}
		if (pilih==2){
			penilaian:
			for(int j=0; j<l; j++){
				system ("cls");
				cout<<"____________________________________________\n\n";
				cout<<"  PENILAIAN                                 \n";
				cout<<"____________________________________________\n";
				cout<<" Lompatan ke-"<<j+1<<endl;
				cout<<"____________________________\n";
				for(int i=0; i<p; i++){
					cout<<"\n Nama Peserta : "<<nama[i];
					cout<<"\n  -Skornya Adalah : ";cin>>skor[i][j];
					if (skor[i][j]<0)
					skor[i][j]=0;
					jumlah[i]=jumlah[i]+skor[i][j];
				}
			}
			for(int c=1;c<p;c++){ 
				for(int d=0;d<p-c;d++){ 
					if(jumlah[d]<jumlah[d+1]){ 
						tjumlah=jumlah[d];
						jumlah[d]=jumlah[d+1];
						jumlah[d+1]=tjumlah; 
                
						tnama=nama[d];
						nama[d]=nama[d+1];
						nama[d+1]=tnama;
					} 
				} 
			}
			for(int a=0;a<p;a++){
				if(jumlah[a]>mak)
				mak=jumlah[a];
				rata[a]=jumlah[a]/l;	
			}
			for(int b=0;b<p;b++){
				if(mak==jumlah[b])
				win=win+1;	
			}
			cout<<"\n____________________________________________\n";
			cout<<"\n   Anda Telah Berhasil Memasukan data\n";
			cout<<"\nInput [y] untuk kembali ke menu  ";
			cout<<"\nInput [z] untuk lanjut \n  :  ";
			cin>>menu;
			system ("cls");
			if (menu=='z')
			goto keluaran;
			if (menu!='y')
			break;
		}
		if (pilih==3){
			keluaran:
			system("Color 0C");
			cout<<"_____________________________________________\n\n";
			cout<<"  HASIL PENILAIAN                           \n";
			cout<<"_____________________________________________\n";
			cout<<"Jumlah Lompatan : "<<l<<endl;
			cout<<"       _____________________________\n";
			cout<<"       |    THE WINNER IS !!!!!!   | \n";
			cout<<"       |   CONGRATULATION FOR....  |\n";
			cout<<"       |___________________________|\n\n";
			for(int i=0;i<win;i++){
				cout<<"        ..*#*>   "<<nama[i]<<"   <*#*..\n";
			}
			cout<<"    __________________________________________________\n";
			cout<<"     TOTAL SKORS :  ( "<<jumlah[0]<< " ) , RATA-RATA SKORS : ( "<<rata[0]<<" )\n";
			cout<<"      atau dibaca ";
			ubah(jumlah[0]);
			cout<<endl<<endl;
			cout<<"________________________________________________________________________\n";
			cout<<"NO|       Nama Peserta      |  Total , Rata2  |      Dibaca     \n\n";
			for(int i=win;i<p;i++){
			cout<<setiosflags(ios::left)<<setw(2)<<i+1<<". "<<setw(24)<<nama[i];
			cout<<"|  "<<setw(6)<<jumlah[i]<<"  "<<setw(6)<<rata[i]<<" | ";
			ubah(jumlah[i]);
			cout<<endl;
			}
			cout<<"\n\n\nInput [y] untuk kembali ke menu : ";
			cin>>menu;
			system ("cls");
			if (menu!='y')
			break;
		}
		if (pilih==4){
			cout<<"\n\n !!! SAYANG SEKALI ANDA TELAH KELLUAR !!!";
			break;
		}
	}
	while (pilih==1 || pilih==2 || pilih==3);
	return 0;
}
