#include <stdio.h>
#include <stdlib.h>

void panduanRoleMenu();

int main(){

    int opt;

    do{   
        system("cls"); 
        printf("Selamat Datang di Aplikasi Info Webinar\n\n");
        printf("===Role Menu===\n1. Admin\n2. Guest\n3. Panduan\n4. Exit\n\n");
        do{
            printf("Pilih role Anda\n> ");
            scanf("%d", &opt);

            if(opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("Mohon masukkan pilihan yang benar!\n\n");
            }

        } while (opt != 1 && opt != 2 && opt != 3 && opt != 4);
        
        switch (opt){
        case 1:
            // adminFunc();
            break;
        case 2:
            // guestFunc();
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
