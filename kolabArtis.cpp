#include "kolabArtis.h"

void createListLagu(listLagu &LP){
    first(LP) = NULL;
    last(LP) = NULL;
}

void createListArtis(listArtis &LC){
	first(LC) = NULL;
}

void createListAlbum(listAlbum &LR){
	first(LR) = NULL;
}

adrLagu createNewElmLagu(infoLagu P){
	adrLagu L = new elmLagu;
    info(L) = P;
    next(L) = NULL;
    prev(L) = NULL;
    return L;
}

adrArtis createNewElmArtis(infoArtis P){
	adrArtis C = new elmArtis;
    info(C) = P;
    next(C) = NULL;
    return C;
}

adrAlbum createNewElmAlbum(listLagu LP, listArtis LC, string judulLagu, string namaArtis){
	adrAlbum P = new elmAlbum;
	adrLagu x = searchLagu(LP, judulLagu);
	adrArtis y = searchArtis(LC, namaArtis);
    detailLagu(P) = x;
    detailArtis(P) = y;
    next(P) = NULL;
    return P;
}

void insertFirstLagu(listLagu &LP, adrLagu P){
	if(first(LP) == NULL && last(LP) == NULL){
        first(LP) = P;
        last(LP) = P;
    } else {
        next(P) = first(LP);
        prev(first(LP)) = P;
        first(LP) = P;
    }
}

void insertLastLagu(listLagu &LP, adrLagu P){
    if (first(LP) == NULL && last(LP) == NULL){
        first(LP) = P;
        last(LP) = P;
    } else {
        prev(P) = last(LP);
        next(last(LP)) = P;
        last(LP) = P;
    }
}

void deleteLagu(listLagu &LP, adrLagu &P){
	if(P == NULL){
        cout << "Lagu tidak ditemukan..." << endl;
    } else {
        if (first(LP) == last(LP)){
            first(LP) = NULL;
            last(LP) = NULL;
        } else if (P == first(LP)){
            first(LP) = next(P);
            next(P) = NULL;
            prev(first(LP)) = NULL;
        } else if (P == last(LP)){
            last(LP) = prev(last(LP));
            prev(P) = NULL;
            next(last(LP)) = NULL;
        } else {
            adrLagu prec = prev(P);
            next(prec) = next(P);
            prev(next(P)) = prec;
            prev(P) = NULL;
            next(P) = NULL;
        }
        cout << "Data berhasil dihapus!" << endl;
    }
}

void insertArtis(listArtis &LC, adrArtis P){
	if (first(LC) == NULL){
        first(LC) = P;
    } else if (info(P).nama < info(first(LC)).nama){
        next(P) = first(LC);
        first(LC) = P;
    } else {
        adrArtis Q = first(LC);
        adrArtis prec = NULL;
        while (Q != NULL && info(Q).nama < info(P).nama){
            prec = Q;
            Q = next(Q);
        }
        if (Q == NULL){
            next(prec) = P;
        } else {
            next(P) = Q;
            next(prec) = P;
        }
    }
}

void deleteArtis(listArtis &LC, adrArtis &P){
	if (P == NULL) {
        cout << "Artis tidak ditemukan..." << endl;
    } else {
        if (P == first(LC) && next(P) == NULL) {
            first(LC) = NULL;
        } else if (P == first(LC) && next(P) != NULL) {
            first(LC) = next(P);
        } else {
            adrArtis Q = first(LC);
            while (Q != NULL && next(Q) != P) {
                Q = next(Q);
            }
            if (Q != NULL) {
                next(Q) = next(P);
                next(P) = NULL;
            }
        }
        cout << "Data berhasil dihapus!" << endl;
    }
}

void insertAlbum(listAlbum &LR, adrAlbum P){
	if (first(LR) == NULL){
        first(LR) = P;
    } else {
        adrAlbum Q = first(LR);
        while (next(Q) != NULL){
          Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteAlbum(listAlbum &LR, adrAlbum &P, string judulLagu, string namaArtis){
    P = searchAlbum(LR, judulLagu, namaArtis);
	if (P == NULL) {
        cout << "Kolaborasi dalam album tidak ditemukan..." << endl;
    } else {
        if (P == first(LR) && next(P) == NULL) {
            first(LR) = NULL;
        } else if (P == first(LR) && next(P) != NULL) {
            first(LR) = next(P);
        } else {
            adrAlbum Q = first(LR);
            while (Q != NULL && next(Q) != P) {
                Q = next(Q);
            }
            if (Q != NULL) {
                next(Q) = next(P);
                next(P) = NULL;
            }
        }
        cout << "Data berhasil dihapus!" << endl;
    }
}

adrLagu searchLagu(listLagu LP, string judulLagu){
	adrLagu P = first(LP);
    while (P != NULL){
        if (info(P).judul == judulLagu){
            return P;
        } else {
            P = next(P);
        }
    }
    return NULL;
}

adrArtis searchArtis(listArtis LC, string namaArtis){
	adrArtis C = first(LC);
    while(C != NULL){
        if(info(C).nama == namaArtis){
            return C;
        } else {
            C = next(C);
        }
    }
    return NULL;
}

adrAlbum searchAlbum(listAlbum LR, string judulLagu, string namaArtis){
	adrAlbum P = first(LR);
    while(P != NULL){
        if(info(detailLagu(P)).judul == judulLagu && info(detailArtis(P)).nama == namaArtis){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void showLagu(listLagu LP){
	adrLagu P = first(LP);
    cout << "List lagu yang ada di album:" << endl;
    cout << "----------------------------------------" << endl;
    while (P != NULL){
        cout << "Judul lagu   : " << info(P).judul << endl;
        cout << "Genre lagu   : " << info(P).genre << endl;
        cout << "Pencipta lagu: " << info(P).pencipta << endl;
        cout << endl;
        P = next(P);
    }
    cout << endl;
}

void showArtis(listArtis LC){
	adrArtis P = first(LC);
    cout << "List artis yang berkolaborasi di album:" << endl;
    cout << "----------------------------------------" << endl;
    while (P != NULL){
        cout << "Nama artis   : " << info(P).nama << endl;
        cout << "Agensi       : " << info(P).agensi << endl;
        cout << "Jenis kelamin: " << info(P).jenisKelamin << endl;
      	cout << "Tahun debut  : " << info(P).tahunDebut << endl;
        cout << endl;
        P = next(P);
    }
    cout << endl;
}

void showAlbum(listAlbum LR){
	adrAlbum P = first(LR);
	string song = "";
    cout << "List album dan relasi lagu dengan artis:" << endl;
    cout << "----------------------------------------" << endl;

    while (P != NULL) {
        if (song != info(detailLagu(P)).judul){
            song = info(detailLagu(P)).judul;
            cout << endl;
            cout << info(detailLagu(P)).judul << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Genre     : " << info(detailLagu(P)).genre << endl;
            cout << "Pencipta  : " << info(detailLagu(P)).pencipta << endl;
            cout << "Artis yang berkolaborasi: " << endl;
        }
        cout << "- " << info(detailArtis(P)).nama << " (" << info(detailArtis(P)).agensi << ", " << info(detailArtis(P)).jenisKelamin << ", " << "Debut: " << info(detailArtis(P)).tahunDebut << ")" << endl;
        P = next(P);
    }
  	cout << endl;
}

void showLaguByArtis(listAlbum LR, string namaArtis){
	adrAlbum P = first(LR);
    int i = 1;
    cout << "List Lagu yang dinyanyikan oleh " << namaArtis << " pada album:" << endl;
    cout << "---------------------------------------------------------------" << endl;
    while (P != NULL){
        if (info(detailArtis(P)).nama == namaArtis){
            cout << i << ". " << info(detailLagu(P)).judul << endl;
            i++;
        }
        P = next(P);
    }
    cout << endl;
}

void showArtisByLagu(listAlbum LR, string judulLagu){
    adrAlbum P = first(LR);
    int i = 1;
    cout << "List artis yang berkolaborasi pada lagu " << judulLagu << " pada album:" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    while (P != NULL){
        if (info(detailLagu(P)).judul == judulLagu){
            cout << i << ". " << info(detailArtis(P)).nama << endl;
            i++;

        }
        P = next(P);
    }
    cout << endl;
}

void countArtisOnLagu(listAlbum LR, string lagu){
    adrAlbum P = first(LR);
    int countArtis  = 0;
    int i = 1;
    cout << "Artis yang berkolaborasi pada lagu " << lagu << ": " << endl;
    while (P != NULL){
        if (info(detailLagu(P)).judul == lagu){
            cout << i << ". " << info(detailArtis(P)).nama << endl;
            i++;
            countArtis++;
        }
        P = next(P);
    }
    cout << "Terdapat " << countArtis << " artis yang berkolaborasi." << endl;
}

int menu(){
    int menu;
    cout << "--------------------------------------------" << endl;
    cout << "                   MENU                     " << endl;
    cout << "--------------------------------------------" << endl;
	cout << "1. Update data Lagu" << endl;
    cout << "2. Update data Artis" << endl;
	cout << "3. Update data Album" << endl;
    cout << "4. Search and show by Lagu atau Artis" << endl;
    cout << "5. Show Data" << endl;
    cout << "6. Show total artis in a song" << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Masukkan pilihanmu: ";
    cin >> menu;
    cout << endl;
    return menu;
}

