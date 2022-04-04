#include "webinarFunction.h"
#include <stdio.h>
#include <stdlib.h>

void adminMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar){

    int opt;

    system("cls");
    printf("=== Admin Menu ===\n1. Login\n2. Logout\n\n");

    do
    {
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

void guestMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar){

    int opt;

    system("cls");
    printf("=== Guest Menu ===\n1. Info Webinar\n2. Daftar Webinar\n3. Search Webinar\n4. Panduan\n5. Exit\n\n");

    do
    {
        do{
            printf("Pilih menu di atas:\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5);

        switch (opt){
        case 1:
            // infoWebinar();
            fflush(stdin);
            getchar();
            break;
        case 2:
            // daftarWebinar();
            fflush(stdin);
            break;
        case 3:
            // searchWebinar();
            fflush(stdin);
            break;
        case 4:
            // panduanGuestMenu();
            fflush(stdin);
            break;
        default:
            break;
        }
    } while (opt != 5);
}