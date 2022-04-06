#include "webinarFunction.h"

int main () {
	// Animasi Pembukaan program
	system ("COLOR 70");
	
	int i, j;
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	for (i = 0; i < 3; i++) {
		printf ("\t\t\t\t\t");
		for (j = 0; j < 47; j++) {
			printf ("=");
			usleep(1000);
		}
		printf ("\n");
	}
	
	printf ("\t\t\t\t\t");
	for (i = 0; i < 17; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf (" Sejuta Ilmu ");
	
	for (i = 0; i < 17; i++) {
		printf ("=");	
		usleep(1000);	
	}
	
	printf ("\n");
	for (i = 0; i < 3; i++) {
		printf ("\t\t\t\t\t");
		for (j = 0; j < 47; j++) {
			printf ("=");
			usleep(1000);
		}
		printf ("\n");
	}
	
	char a = 177;
	char b = 219;
	
	printf ("\n\n\n\n\n\n\n\n\n\n\n");
	printf ("\t\t");
	
	for (i = 0; i < 88; i++) {
		printf ("%c", a);
		printf ("\r");
		printf ("\t\t");
		for (i = 0; i < 88; i++) {
			printf ("%c", b);
			usleep(10000);
		}
	}
	// Akhir dari animasi pembukaan program
	
	// inisialisasi variabel utama
	int opt;
    char judulWebinar[10][50] = {
        "Globalisasi",
        "Internet of Things",
        "Manusia makhluk sempurna",
        "Indonesia Merdeka",
        "Cara Investasi ala Warren Buffet"
    };

    char tanggalPelaksanaan[10][50] = {
        "30 April 2022",
        "25 Mei 2022",
        "2 Mei 2022",
        "17 Agustus 2022",
        "26 Juni 2022"
    };

    char hargaWebinar[10][10] = {
        "Berbayar",
        "Gratis",
        "Berbayar",
        "Gratis",
        "Gratis",
    };
    
    int kuotaWebinar [10] = {50, 50, 50, 50, 50};
	// akhir dari inisialisasi variavel utama

	// Program Start Menu
    do{   
        do{
        	system("cls"); 
        	printf("Selamat Datang di Aplikasi Info Webinar\n\n");
        	printf("=== Start Menu ===\n");
        	printf ("1. Admin\n");
        	printf ("2. Guest\n");
        	printf ("3. Panduan\n");
        	printf ("4. Kredit\n");
        	printf ("5. Exit\n\n");
            printf("Pilih Menu di Atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt!= 5){
                printf ("\n*** Harap masukkan pilihan yang sesuai ***\n");
				sleep(2);
				system ("cls");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5);
        
        switch (opt){
        case 1:
            adminMenu(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
            break;
        case 2:
            guestMenu(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
            break;
        case 3: 
            panduanStartMenu();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        case 4 : 
        	anggotaKelompok();
        	fflush(stdin);
            printf("\n\nTekan Enter untuk kembali...");
            getchar();
        	break;
        default:
            system("cls");
            printf("Terima Kasih telah menggunakan aplikasi kami...\n");
            break;
        }
    } while (opt != 5);
	// Akhir dari program Start Menu
    
    return 0;
}
