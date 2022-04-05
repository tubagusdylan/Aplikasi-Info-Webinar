#include "webinarFunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void panduanInfoWebinar(){
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
        printf("=== Panduan Guest Menu ===\n1. Info Webinar\n2. Daftar Webinar\n3. Search Webinar\n4. Exit\n\n");
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

void adminMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar){

    int opt;

    do
    {
        system("cls");
        printf("=== Admin Menu ===\n1. Login\n2. Logout\n\n");
        do{
            printf("Pilih manu di atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2);

        switch (opt){
        case 1:
            // login();
            break;
        default:
            break;
        }
    } while (opt != 2);
}

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
            printf("%d. %s\n", i+1, hasilJudul);
        }
        
        printf("\nIngin mencari lagi? (y/n): ");
        scanf("%c", &lanjut);
        if(lanjut == 'y' || lanjut == 'Y'){
            flag = 1;
        } else {
            flag = 0;
        }
        printf("\nTekan Enter untuk kembali...");

    } while (flag);
}   

void guestMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar){

    int opt;

    do
    {
        system("cls");
        printf("=== Guest Menu ===\n1. Info Webinar\n2. Daftar Webinar\n3. Search Webinar\n4. Panduan\n5. Exit\n\n");
        do{
            printf("Pilih menu di atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5);

        switch (opt){
        case 1:
            infoWebinar(judulWebinar, tanggalPelaksanaan, hargaWebinar, kuotaWebinar);
            fflush(stdin);
            getchar();
            break;
        case 2:
            // daftarWebinar();
            fflush(stdin);
            getchar();
            break;
        case 3:
            searchWebinar(judulWebinar);
            fflush(stdin);
            getchar();
            break;
        case 4:
            panduanGuestMenu();
            fflush(stdin);
            break;
        default:
            break;
        }
    } while (opt != 5);
}