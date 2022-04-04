#include "webinarFunction.h"

void panduanRoleMenu();

int main(){

    int opt, kuotaWebinar = 50;
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

    char hargaWebinar[2][10] = {
        "Berbayar",
        "Gratis"
    };

    do{   
        system("cls"); 
        printf("Selamat Datang di Aplikasi Info Webinar\n\n");
        printf("=== Role Menu ===\n1. Admin\n2. Guest\n3. Panduan\n4. Exit\n\n");
        do{
            printf("Pilih role Anda\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
        
        switch (opt){
        case 1:
            adminMenu(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
            break;
        case 2:
            guestMenu(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
            break;
        case 3: 
            panduanRoleMenu();
            fflush(stdin);
            printf("Tekan Enter untuk kembali...");
            getchar();
            break;
        default:
            system("cls");
            printf("Terima Kasih telah mengunjungi aplikasi kami...\n");
            break;
        }
    } while (opt != 4);
    
    return 0;
}

void panduanRoleMenu(){
    system("cls");
    printf("Pada Menu Awal ini ada tiga pilihan\n");
    printf("1. User bisa memilih admin, jika user berupa developer dari aplikasi ini\n");
    printf("2. User bisa memilih guest, jika user adalah seorang tamu yang ingin mencari info webinar\n");
    printf("3. User bisa memilih exit, jika ingin keluar dari aplikasi\n\n");
}
