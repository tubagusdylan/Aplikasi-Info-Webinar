#include "webinarFunction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

int batas = 5;
const int atSymbol = 64, BACKSPACE = 8, CARRIAGE_RETURN = 13;

// Fungsi ini dipakai untuk menu admin dan guest
void infoWebinar (char judulWebinar [][50], char tanggalPelaksanaan [][50], char hargaWebinar [][10], int kuotaWebinar []) {
	int i, j;
	char dummy[50];
	
	int dummyy;
	
	// ini adalah algoritma sorting pada string menggunakan bubble sort yang sedikit dimodifikasi
	for(i = 0; i < batas; i++) {
		for (j = i + 1; j < batas; j++) {
			if (strcmp (judulWebinar[i], judulWebinar [j] ) > 0) {
				strcpy (dummy, judulWebinar[i]);
				strcpy (judulWebinar[i], judulWebinar[j]);
				strcpy (judulWebinar[j], dummy);
				
				strcpy (dummy, tanggalPelaksanaan[i]);
				strcpy (tanggalPelaksanaan[i], tanggalPelaksanaan[j]);
				strcpy (tanggalPelaksanaan[j], dummy);
				
				strcpy (dummy, hargaWebinar[i]);
				strcpy (hargaWebinar[i], hargaWebinar[j]);
				strcpy (hargaWebinar[j], dummy);

				
				dummyy = kuotaWebinar[i];
				kuotaWebinar[i] = kuotaWebinar[j];
				kuotaWebinar[j] = dummyy;
			}
		}	
	}
	
	for (i = 0; i < batas; i++) { // print daftar webinar
		printf("%d. %s || %s || %s || %d\n", i + 1, judulWebinar[i], tanggalPelaksanaan[i], hargaWebinar[i], kuotaWebinar[i]);	
	}	
}

// Fungsi untuk memberi tahu apa itu role admin
void panduanAdmin () {
	
	printf ("\t\t\t\t===============================\n");
	printf ("\t\t\t\t***** Panduan Role Admin ******\n");
	printf ("\t\t\t\t===============================\n");
	
	printf ("> Admin merupakan role penting dalam aplikasi ini\n");
	printf ("> Admin memiliki beberapa kendali terhadap suatu hal yang tidak dapat dilakukan oleh 'guest'\n");
	printf (">> Untuk mendapatkan kendali sebagai seorang Admin, diperlukan proses login terlebih dahulu\n");
	printf (">> Oleh karena itu, Admin perlu mengetahui username dan password agar dapat login sebagai Admin\n");
	printf (">>> Admin dapat melihat daftar webinar seperti guest\n");
	printf (">>> Admin dapat menambahkan webinar hingga maksimal 10 webinar dapat ditampung oleh aplikasi ini\n");
	printf (">>> Admin juga dapat melakukan penghapusan webinar jika dirasa webinar tersebut sudah berlalu\n");
}

// Fungsi admin menu
void adminMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]) {
	int i, j;
    int opt;
    
    char uchar;
    char username[20];
    char password[20];
    
    int pilihan;
    int perulangan = 1;
    char kembali;
    
    int hapusWebinar;

	system("cls");
	
	// algoritma 
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 8; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Selamat Datang di Menu Admin ");
	
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");
	
	// kode login sistem
	printf ("Harap melakukan login terlebih dahulu\n\n");
	
	printf ("Username : ");
	fflush (stdin);
	scanf ("%s", username);
	
	printf ("Password : ");
	fflush (stdin);
	
	for (i = 0; (uchar = getch()) != CARRIAGE_RETURN; ++i) {
		if (uchar == BACKSPACE) {
			if (i > 0) {
				printf ("%s", "\b\033[K");
				i -= 2;
				continue; 
			}
			else {
				--i;
			}
		}
		else {
			password [i] = uchar;
			printf ("%c", '*');
		}
	}
	password[i] = '\0';
	printf ("\n");
	
	// perulangan permintaan input ketika username/password salah
	while (strcmp (username, "admin") != 0 || strcmp (password, "admin") != 0) {
		printf ("\n*** Username atau Password yang Anda masukkan salah ***\n");
		printf (">>>>>>>>>>>>>>>> Silahkan Coba Kembali <<<<<<<<<<<<<<<<\n\n");
		sleep(2);

		printf ("Username : ");
		fflush (stdin);
		scanf ("%s", username);
	
		printf ("Password : ");
		fflush (stdin);
		
		for (i = 0; (uchar = getch()) != CARRIAGE_RETURN; ++i) {
			if (uchar == BACKSPACE) {
				if (i > 0) {
					printf ("%s", "\b\033[K");
					i -= 2;
					continue; 
				}
				else {
					--i;
				}
			}
			else {
				password [i] = uchar;
				printf ("%c", '*');
			}
		}
		password[i] = '\0';
		printf ("\n");
	}
	
	if (strcmp (username, "admin") == 0) {
		if (strcmp (password, "admin") == 0) { // jika username dan password benar
			printf ("\nLogin berhasil...\n");
			printf ("Loading...\n");
			Sleep(1000);
			char a = 177;
			char b = 219;
	
			printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf ("\t\t");
	
			for (i = 0; i < 88; i++) {
				printf ("%c", a);
				printf ("\r");
				printf ("\t\t");
				for (i = 0; i < 88; i++) {
					printf ("%c", b);
					usleep(1000);
				}
			}
			// perulangan apabila pengguna ingin kembali ke menu "Daftar Fitur"
			while (perulangan == 1) {
				system("cls");
				printf ("=== Daftar Fitur ===\n");
				printf ("1. Info Webinar\n");
				printf ("2. Menambahkan Webinar\n");
				printf ("3. Menghapus Webinar\n");
				printf ("4. Panduan Admin\n");
				printf ("5. Exit\n\n");
				printf ("Pilih menu di atas : \n>");
				scanf ("%d", &pilihan);
				
				while (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5) { // error handling input "pilihan"
					printf ("\n*** Harap masukkan pilihan yang sesuai ***\n");
					sleep(1);
					system ("cls");
					
					printf ("=== Daftar Fitur ===\n");
					printf ("1. Info Webinar\n");
					printf ("2. Menambahkan Webinar\n");
					printf ("3. Menghapus Webinar\n");
					printf ("4. Panduan Admin\n");
					printf ("5. Exit\n\n");
					printf ("Pilih menu di atas : \n>");
					scanf ("%d", &pilihan);
				}
				
				switch (pilihan) // percabangan input "pilihan"
				{
				case 1: // bagian daftar webinar yang tersedia yang telah diurutkan secara alfabet (sorting berdasarkan judul)
					system ("cls");
					
					printf("Berikut Daftar Webinar yang Tersedia\n\n");
					
					infoWebinar (judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
					
					printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
					fflush(stdin);
					kembali = getchar();
					
						// error handling input "kembali"
						while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
							printf ("*** Harap masukkan jawaban yang sesuai ***\n");
							printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
							fflush(stdin);
							kembali = getchar();
						}
						
						if (kembali == 'y' || kembali == 'Y') {
							perulangan = 1;
						}	
						
						else if (kembali == 'n' || kembali == 'N') {
							perulangan = -1;
						}		
					break;
				case 2: // bagian menambahkan daftar webinar yang dapat diikuti oleh pengguna
					if (batas <= 9) {
						system ("cls");
						
						// input informasi penting webinar yang ingin ditambahkan
						printf ("Masukkan data informasi mengenai daftar webinar yang ingin ditambahkan\n\n");
						
						printf (">> Judul Webinar : ");
						scanf (" %255[^\n]s", &judulWebinar[batas]);
						fflush (stdin);
						
						printf (">> Tanggal Pelaksanaan Webinar [misal 10 Mei 2022] : ");
						scanf (" %255[^\n]s", &tanggalPelaksanaan[batas]);
						fflush (stdin);
						
						printf (">> Harga Webinar [gratis/berbayar] : ");
						scanf (" %255[^\n]s", &hargaWebinar[batas]);
						fflush (stdin);
						
						printf (">> Kuota Webinar [misal 20]: ");
						scanf (" %255[^\n]s", &kuotaWebinar[batas]);
						fflush (stdin);
		
						printf ("\n\n*** Webinar baru berhasil ditambahkan ***\n\n");
						
						batas++; // variabel batas akan bertambah (1) karena daftar webinar yang tersedia juga bertambah	
						
						printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
						fflush(stdin);
						kembali = getchar();
						
						// error handling input "kembali"
						while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
							printf ("*** Harap masukkan jawaban yang sesuai ***\n");
							printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
							fflush(stdin);
							kembali = getchar();
						}
						
						if (kembali == 'y' || kembali == 'Y') {
							perulangan = 1;
						}	
						
						else if (kembali == 'n' || kembali == 'N') {
							perulangan = -1;
						}		
					}
					
					else { // jika nilai batas > 9, maka daftar webinar yang dapat ditampung oleh aplikasi ini sudah penuh
						system ("cls");
						printf ("Kuota jumlah webinar yang dapat ditampung oleh aplikasi ini sudah penuh\n");
						
						printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
						fflush(stdin);
						kembali = getchar();
						
						// error handling input "kembali"
						while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
							printf ("*** Harap masukkan jawaban yang sesuai ***\n");
							printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
							fflush(stdin);
							kembali = getchar();
						}
						
						if (kembali == 'y' || kembali == 'Y') {
							perulangan = 1;
						}	
						
						else if (kembali == 'n' || kembali == 'N') {
							perulangan = -1;
						}		
					}
					break;
				case 3: // bagian menghapus daftar webinar yang tersedia jika memang sudah kadaluarsa / sudah terlaksana
					system ("cls");
					printf("Berikut Daftar Webinar yang Tersedia\n\n");
					
					// print daftar webinar yang telah diurutkan secara alfabet (sorting berdasarkan judul webinar)
					infoWebinar (judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
					
					// pemilihan nomor webinar yang akan dihapus
					printf ("\n> Webinar mana yang ingin Anda hapus ? ");
					scanf ("%d", &hapusWebinar);
					
					// error handling input "hapusWebinar"
					while (hapusWebinar <= 0 || hapusWebinar > batas) {
						printf ("*** Harap masukkan jawaban yang sesuai ***\n");
						printf ("Webinar mana yang ingin Anda hapus ? ");
						scanf ("%d", &hapusWebinar);
					}
					
					// algoritma penghapusan salah satu daftar webinar
					for (i = hapusWebinar; i < batas; i++) {
						strcpy (judulWebinar[i - 1], judulWebinar[i]);
						strcpy (tanggalPelaksanaan[i - 1], tanggalPelaksanaan[i]);
						strcpy (hargaWebinar[i - 1], hargaWebinar[i]);
						kuotaWebinar[i - 1] = kuotaWebinar[i];
					}
					
					printf ("\nloading");
					for (i = 0; i < 3; i++) {
						sleep (0.1);
						printf (".");
					}
					
					system ("cls");
					printf ("Berikut Daftar Webinar yang tersedia : \n"); // print daftar webinar setelah penghapusan salah satu webinar
					batas--; // variabel batas akan berkurang (1) karena daftar webinar yang tersedia juga berkurang	
					
					infoWebinar (judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);	
					
					printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
					fflush(stdin);
					kembali = getchar();
					
					// error handling input "kembali"
					while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
						printf ("*** Harap masukkan jawaban yang sesuai ***\n");
						printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
						fflush(stdin);
						kembali = getchar();
					}
					
					if (kembali == 'y' || kembali == 'Y') {
						perulangan = 1;
					}	
					
					else if (kembali == 'n' || kembali == 'N') {
						perulangan = -1;
					}
					break;
				case 4:
					system ("cls");
					
					panduanAdmin(); // memanggil fungsi panduanAdmin
					
					printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
					fflush(stdin);
					kembali = getchar();
					
					// error handling input "kembali"
					while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
						printf ("*** Harap masukkan jawaban yang sesuai ***\n");
						printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
						fflush(stdin);
						kembali = getchar();
					}
					
					if (kembali == 'y' || kembali == 'Y') {
						perulangan = 1;
					}	
					
					else if (kembali == 'n' || kembali == 'N') {
						perulangan = -1;
					}
					break;
				default:
					perulangan = -1; // kembali ke start menu
					break;
				}
			}
		}	
	}
}

// Fungsi ini untuk mengecek apakah email sudah benar atau belum, (harus terdapat @ symbol)
int emailChecking(char email[]){
	int i;
	for (i = 0; i < strlen(email); i++){
		if(email[i] == atSymbol){
			return 0;
		}
	}
	return 1;
}

// Fungsi ini untuk mengecek nomor telepon sudah benar atau belum, jumlahnya harus 12 (yang umum) dan harus berupa angka 
int phoneNumberCheck(char phoneNumber[]){
	int i;

	if(strlen(phoneNumber) != 12){
		return 1;
	}

	for (i = 0; i < strlen(phoneNumber); i++){
		if(phoneNumber[i] < '0' || phoneNumber[i] > '9'){
			return 1;
		}
	}

	return 0;
}

// Fungsi untuk mendaftar webinar
void daftarWebinar (char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]) {
	int i, j, k, pilihan, flag = 0;
    char namaGuess[50];
	char email[50]; 
	char phoneNumber[50];
	
	system ("cls");
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Proses Pendaftaran Webinar ");
	
	for (i = 0; i < 10; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");
	
	
	printf("> Masukkan Nama Anda : ");
	scanf(" %255[^\n]s", &namaGuess);  	  	
	fflush(stdin);

	do
	{
		printf("> Masukkan Email Anda : ");
		scanf(" %255[^\n]s", &email);
		fflush(stdin);
		
		if(flag = emailChecking(email)){
			printf("*** Email harus ada @, Coba Lagi! ***\n\n");
		}
		
	} while (flag);
	
	do
	{
		printf("> Masukkan No. Telepon Anda : ");
		scanf(" %255[^\n]s", &phoneNumber);
		fflush(stdin);

		if(flag = phoneNumberCheck(phoneNumber)){
			printf("*** Mohon masukkan nomor telepon dengan benar! (12 angka) ***\n\n");
		}
		
	} while (flag);
    
	
	printf("\n======== Berikut Nama Judul Webinar dan Waktunya ========\n");
	printf("\n");	
	infoWebinar (judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
	
	printf("\nPilih Webinar yang tersedia : ");
	scanf("%i", &pilihan);
 	k = pilihan;
	
	kuotaWebinar[pilihan-1]--;
	system("cls");
	
	printf ("\t\t=======================================\n");
	printf ("\t\t==== Bukti Pembelian Tiket Webinar ====\n");
	printf ("\t\t=======================================\n");
	
	printf ("\nNama \t\t\t\t : %s", namaGuess);
	printf ("\nEmail \t\t\t\t : %s", email);
	printf ("\nNo. Telepon \t\t\t : %s", phoneNumber);
	printf ("\nJudul webinar yang dipilih \t : %s", judulWebinar[k-1]);
	printf ("\nTanggal Pelaksanaan Webinar \t : %s", tanggalPelaksanaan[k-1]);
	printf ("\nSisa Kuota Webinar yang dipilih  : %d", kuotaWebinar[k-1]);
	printf ("\nWaktu Transaksi \t\t : %s", __TIME__);
	
	printf ("\n\n\t");
	printf ("==========================================================\n\t");
	printf ("Terima Kasih Telat Mendaftar Webinar Melalui Aplikasi Kami\n\t");
	printf ("==========================================================\t");
}

// Fungsi panduan pada program (start menu dan guest menu)
void panduanStartMenu () {
    system("cls");
    printf("Pada Menu Awal ini ada tiga pilihan\n");
    printf("1. User bisa memilih admin, jika user berupa developer dari aplikasi ini\n");
    printf("2. User bisa memilih guest, jika user adalah seorang tamu yang ingin mencari info webinar\n");
    printf("3. User bisa memilih exit, jika ingin keluar dari aplikasi\n\n");
}

void panduanInfoWebinar () {
    system("cls");
    printf("1. User dapat melihat berbagai macam webinar yang ada di aplikasi ini\n");
    printf("2. Informasi yang ditampilkan: \n a. Judul Webinar\n b. Tanggal Pelaksanaan\n c. Harga Webinar\n d. Kuota Webinar\n\n");
}

void panduanDaftarWebinar(){
    system("cls");
    printf("1. User memasukkan nama, email, dan nomor telepon\n");
    printf("2. User memilih webinar yang diinginkan\n");
    printf("3. User hanya dapat mendaftar webinar yang kuota masih tersedia\n");
    printf("4. User bisa mengecek kembali data yang dimasukkan, pastikan data sudah benar\n");
    printf("5. Jika sudah selesai mendaftar, user bisa kembali ke guest menu\n\n");
}

void panduanSearchWebinar(){
    system("cls");
    printf("1. User memasukkan huruf pertama judul webinar\n");
    printf("2. User bisa memasukkan huruf kedua untuk mencari judul webinar\n");
    printf("3. Jika sudah muncul webinar yang ingin diikuti, user bisa kembali ke guest menu\n\n");
}

void panduanGuestMenu(){
    int opt;
    do{   
        system("cls"); 
        printf("=== Panduan Guest Menu ===\n");
        printf ("1. Info Webinar\n");
        printf ("2. Daftar Webinar\n");
        printf ("3. Search Webinar\n");
        printf ("4. Exit\n\n");
        do{
            printf("Pilih menu di atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
        
        switch (opt){
        case 1:
            panduanInfoWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 2:
            panduanDaftarWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 3: 
            panduanSearchWebinar();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        default:
            fflush(stdin);
            break;
        }
    } while (opt != 4);
}
// akhir dari program panduan

// Fungsi untuk mencari webinar yang tersedia
void searchWebinar(char judulWebinar[][50]){
    char judul, lanjut;
    char* hasilJudul;
    int i, flag = 0;

    system("cls");
    printf("=== Search Webinar ===\n\n");

    do
    {      
        do
        {
            printf("Masukkan huruf pertama dari judul webinar: ");
            fflush(stdin);
            scanf("%c", &judul);

            if(judul < 'A' || judul > 'Z'){
                printf("Tolong masukkan huruf kapital!\n");
                flag = 1;
            } else {
                flag = 0;
            }

        } while (flag);
            
        printf("\nJudul Webinar yang tersedia: \n");
        for (i = 0; i < 10; i++){
            fflush(stdin);
            hasilJudul = strchr(judulWebinar[i], judul); 
			/* strchr adalah fungsi pada library string.h untuk mencari string dengan 
				awalan huruf yang sesuai dengan yang dicari dan diletakkan pada pointer.
			 */
            printf("%d. %s\n", i+1, hasilJudul);
        }
        
        printf("\nIngin mencari lagi? [y/n]: ");
        scanf("%c", &lanjut);
        if(lanjut == 'y' || lanjut == 'Y'){
            flag = 1;
        } else {
            flag = 0;
        }

    } while (flag);
}   

// Fungsi untuk menu guest
void guestMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]) {

	int i;
    int opt;
	int perulangan = 1;
	char kembali;
	
	system ("cls");
	printf ("\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 8; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Selamat Datang di Menu Guest ");
	
	for (i = 0; i < 9; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n\t\t\t\t\t");
	for (i = 0; i < 47; i++) {
			printf ("=");
			usleep(1000);
	} 
	printf ("\n\n");
	
	while (perulangan == 1) {
		system("cls");
		printf("=== Guest Menu ===\n");
		printf ("1. Info Webinar\n");
		printf ("2. Daftar Webinar\n");
		printf ("3. Search Webinar\n");
		printf ("4. Panduan\n");
		printf ("5. Exit\n\n");
		
	    printf("Pilih menu di atas:\n> ");
	    scanf("%d", &opt);

    	while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5) {
	    	printf ("*** Harap masukkan pilihan yang sesuai ***\n\n");
			sleep (1);
			
		    printf("Pilih menu di atas:\n> ");
		    scanf("%d", &opt);
		}

	    switch (opt){
	    case 1:
	    	system ("cls");
	    	printf ("Berikut daftar webinar yang tersedia : \n");
	        infoWebinar (judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
	        
		    printf ("\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 2:
	        daftarWebinar(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
	        
	        printf ("\n\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 3:
	        searchWebinar(judulWebinar);
	        printf ("\nApakah Anda ingin kembali ke Guest Menu [y/n] ? ");
			fflush(stdin);
			kembali = getchar();
			
			while (kembali != 'y' && kembali != 'Y' && kembali != 'n' && kembali != 'N') {
				printf ("*** Harap masukkan jawaban yang sesuai ***\n");
				printf ("\nApakah Anda ingin kembali ke Daftar Fitur Admin [y/n] ? ");
				fflush(stdin);
				kembali = getchar();
			}
			
			if (kembali == 'y' || kembali == 'Y') {
				perulangan = 1;
			}	
			
			else if (kembali == 'n' || kembali == 'N') {
				perulangan = -1;
			}		
	        break;
	        
	    case 4:
	        panduanGuestMenu();	
	        break;
	        
	    default:
			perulangan = -1;
	        break;
		}	
	}
}

// Ini untuk memnberi tahu anggota kelompok kami
void anggotaKelompok () {
	int i, j;
	
	system ("cls");
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	printf ("\t\t\t\t\t");
	
	for (j = 0; j < 47; j++) {
		printf ("=");
		usleep(1000);
	}
	printf ("\n");
	
	printf ("\t\t\t\t\t1. Irham Muslim \t\t 2006574313\n");
	usleep(100000);
	printf ("\t\t\t\t\t2. Tubagus Dylan Rachmat \t 2006574521\n");
	usleep(100000);
	printf ("\t\t\t\t\t3. Raihan Nagib \t\t 2006574654\n");
	usleep(100000);
	
	printf ("\t\t\t\t\t");
	for (j = 0; j < 47; j++) {
		printf ("=");
		usleep(1000);
	}
	printf ("\n");
}
