#ifndef KOLABARTIS_H_INCLUDED
#define KOLABARTIS_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define detailLagu(P) P->detailLagu
#define detailArtis(P) P->detailArtis

struct lagu{
    string judul;
    string genre;
    string pencipta;
};

struct artis{
    string nama;
    string agensi;
    string jenisKelamin;
    string tahunDebut;
};

typedef struct lagu infoLagu;
typedef struct artis infoArtis;
typedef struct elmLagu *adrLagu;
typedef struct elmArtis *adrArtis;
typedef struct elmAlbum *adrAlbum;

struct elmLagu{
    infoLagu info;
    adrLagu prev;
    adrLagu next;
};

struct elmArtis{
    infoArtis info;
    adrArtis next;
};

struct elmAlbum{
    adrLagu detailLagu;
    adrArtis detailArtis;
    adrAlbum next;
};

struct listLagu{
    adrLagu first;
    adrLagu last;
};

struct listArtis{
    adrArtis first;
};

struct listAlbum{
    adrAlbum first;
};

void createListLagu(listLagu &LP);
void createListArtis(listArtis &LC);
void createListAlbum(listAlbum &LR);
adrLagu createNewElmLagu(infoLagu P);
adrArtis createNewElmArtis(infoArtis P);
adrAlbum createNewElmAlbum(listLagu LP, listArtis LC, string judulLagu, string namaArtis);
void insertFirstLagu(listLagu &LP, adrLagu P);
void insertLastLagu(listLagu &LP, adrLagu P);
void deleteLagu(listLagu &LP, adrLagu &P);
void insertArtis(listArtis &LC, adrArtis P);
void deleteArtis(listArtis &LC, adrArtis &P);
void insertAlbum(listAlbum &LR, adrAlbum P);
void deleteAlbum(listAlbum &LR, adrAlbum &P, string judulLagu, string namaArtis);
adrLagu searchLagu(listLagu LP, string judulLagu);
adrArtis searchArtis(listArtis LC, string namaArtis);
adrAlbum searchAlbum(listAlbum LR, string judulLagu, string namaArtis);
void showLagu(listLagu LP);
void showArtis(listArtis LC);
void showAlbum(listAlbum LR);
void showLaguByArtis(listAlbum LR, string namaArtis);
void showArtisByLagu(listAlbum LR, string judulLagu);
void countArtisOnLagu(listAlbum LR, string lagu);
int menu();

#endif // KOLABARTIS_H_INCLUDED
