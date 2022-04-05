#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int i = 0;
	int j;
	int k;
	char a;
    char namaGuess[50];
	char email[50]; 
	char phoneNumber[50];
	int pilihan;
	char temp[50];
	int tempo;
	
	printf("Masukkan Nama Anda : ");
	scanf(" %255[^\n]s", &namaGuess);  	  	
	fflush(stdin);
  	  
  	printf("Masukkan Email Anda : ");
	scanf(" %255[^\n]s", &email);
  	fflush(stdin);
    
  	printf("Masukkan No. Telepon Anda : ");
	scanf(" %255[^\n]s", &phoneNumber);
	fflush(stdin);
	
	//system("cls");
	
	
	char nama[5][200] = {
		"Tips Sukses Berbisnis di Internet", 
		"Strategi Investasi", 
		"Problem Solving di dalam Bisnis", 
		"Analisis Risiko Keuangan pada UMKM", 
		"Tips Menjaga Kesehatan Tubuh"};
	
	char waktu[5][200] = {
		"13 April 2022", 
		"15 April 2022", 
		"17 Mei 2022", 
		"20 Mei 2022", 
		"26 Juni 2022"};
		
	char status[5][200] = {
		"Berbayar", 
		"Gratis", 
		"Berbayar", 
		"Berbayar", 
		"Gratis"};
	
	int kuota[5] = {50, 50, 50, 50, 50};
	
	
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(strcmp(nama[i],nama[j])>0){
			strcpy(temp,nama[i]);
			strcpy(nama[i],nama[j]);
			strcpy(nama[j],temp);
			
			strcpy(temp,waktu[i]);
			strcpy(waktu[i],waktu[j]);
			strcpy(waktu[j],temp);
			
			strcpy(temp,status[i]);
			strcpy(status[i],status[j]);
			strcpy(status[j],temp);
			
			tempo = kuota[i];
			kuota[i] = kuota[j];
			kuota[j] = tempo;
			}
		}	
	}
	
	printf("\nBerikut Nama Judul Webinar dan Waktunya\n");
	printf("\n");	
	for(i = 0; i < 5; i++){
		printf("%d. %s // %s // %s // %d\n", i + 1, nama[i], waktu[i], status[i], kuota[i]);
	}
	
	printf("\nPilih Webinar yang tersedia : ");
	scanf("%i", &pilihan);
 	k = pilihan;
	
	kuota[pilihan-1]--;
	system("cls");
	
	printf("\n=== Bukti Pembelian Tiket Webinar ===");
	
	printf("\nNama : %s", namaGuess);
	printf("\nEmail : %s", email);
	printf("\nNo. Telepon : %s", phoneNumber);
	printf("\nJudul webinar yang dipilih : %s", nama[k-1]);
	printf("\nWaktu : %s", waktu[k-1]);
	printf("\nSisa Kuota Webinar yang dipilih : %d", kuota[k-1]);
	printf("\n");
	
    return 0;
}


