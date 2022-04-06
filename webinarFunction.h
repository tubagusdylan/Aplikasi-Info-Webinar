#ifndef webinarFunction
#define webinarFunction
#include "webinarFunction.c"

// Function Prototyping
void adminMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]);
void guestMenu(char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]);
void daftarWebinar (char judulWebinar[][50], char tanggalPelaksanaan[][50], char hargaWebinar[][10], int kuotaWebinar[]);
void infoWebinar (char judulWebinar [][50], char tanggalPelaksanaan [][50], char hargaWebinar [][10], int kuotaWebinar []);
void searchWebinar(char [][50]);
int emailChecking(char [50]);
void panduanGuestMenu();
void panduanInfoWebinar();
void panduanDaftarWebinar();
void panduanSearchWebinar();
void panduanStartMenu();
void panduanAdmin();
void anggotaKelompok();

#endif
