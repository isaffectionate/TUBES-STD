#include "kolabArtis.h"

int main(){
	listLagu LP;
    listArtis LC;
    listAlbum LR;
    createListLagu(LP);
    createListArtis(LC);
    createListAlbum(LR);
    int pilihan = menu();
    int n, choose;
    string song, singer;
    while (pilihan != 0){
        if (pilihan == 1){
            cout << "-----------------------------" << endl;
            cout << "         UPDATE DATA         " << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Tambah lagu di awal list" << endl;
            cout << "2. Tambah lagu di akhir list" << endl;
            cout << "3. Hapus lagu" << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choose;
            cout << endl;
            if (choose == 1){
                cout << "Berapa lagu yang akan Anda tambahkan? ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++){
                    infoLagu x;
                    cout << "Judul: ";
                    getline(cin, x.judul);
                    cout << "Genre: ";
                    getline(cin, x.genre);
                    cout << "Pencipta: ";
                    getline(cin, x.pencipta);
                    insertFirstLagu(LP, createNewElmLagu(x));
                    cout << endl;
                }
                cout << "Data berhasil ditambahkan!" << endl;
                cout << endl;
            } else if (choose == 2){
                cout << "Berapa lagu yang akan Anda tambahkan? ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++){
                    infoLagu x;
                    cout << "Judul: ";
                    getline(cin, x.judul);
                    cout << "Genre: ";
                    getline(cin, x.genre);
                    cout << "Pencipta: ";
                    getline(cin, x.pencipta);
                    insertLastLagu(LP, createNewElmLagu(x));
                    cout << endl;
                }
                cout << "Data berhasil ditambahkan!" << endl;
                cout << endl;
            } else if (choose == 3){
                cout << "Lagu apa yang akan Anda hapus? ";
                cin.ignore();
                getline(cin, song);
                adrLagu x = searchLagu(LP, song);
                cout << endl;
                deleteLagu(LP, x);
                cout << endl;
            } else {
                cout << "Input tidak valid." << endl;
                cout << endl;
            }
        } else if (pilihan == 2){
            cout << "-----------------------------" << endl;
            cout << "         UPDATE DATA         " << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Tambah artis" << endl;
            cout << "2. Hapus artis" << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choose;
            cout << endl;
            if (choose == 1){
                cout << "Berapa artis yang akan Anda tambahkan? ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++){
                  infoArtis x;
                  cout << "Nama: ";
                  getline(cin, x.nama);
                  cout << "Agensi: ";
                  getline(cin, x.agensi);
                  cout << "Jenis kelamin: ";
                  getline(cin, x.jenisKelamin);
                  cout << "Tahun debut: ";
                  getline(cin, x.tahunDebut);
                  insertArtis(LC, createNewElmArtis(x));
                  cout << endl;
                }
                cout << "Data berhasil ditambahkan!" << endl;
                cout << endl;
            } else if (choose == 2){
                cout << "Siapa artis yang akan Anda hapus? ";
                cin.ignore();
                getline(cin, singer);
                adrArtis P = searchArtis(LC, singer);
                cout << endl;
                deleteArtis(LC, P);
                cout << endl;
            } else {
                cout << "Input tidak valid." << endl;
                cout << endl;
            }
        } else if (pilihan == 3){
            cout << "-----------------------------" << endl;
            cout << "         UPDATE DATA         " << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Tambah kolaborasi" << endl;
            cout << "2. Hapus kolaborasi" << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choose;
            cout << endl;
            if (choose == 1){
                cout << "Berapa kolaborasi yang akan Anda tambahkan? ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++){
                  cout << "Lagu yang ditambahkan ke album: ";
                  getline(cin, song);
                  cout << "Berapa artis yang berkolaborasi? ";
                  int jumlah;
                  cin >> jumlah;
                  cin.ignore();
                  for (int i = 0; i < jumlah; i++){
                    cout << "Silahkan tambahkan artis: ";
                    getline(cin, singer);
                    insertAlbum(LR, createNewElmAlbum(LP, LC, song, singer));
                  }
                  cout << endl;
                }
                cout << "Data berhasil ditambahkan!" << endl;
                cout << endl;
            } else if (choose == 2){
                cout << "-----------------------------" << endl;
                cout << "          HAPUS ALBUM        " << endl;
                cout << "-----------------------------" << endl;
                cout << "1. Hapus data lagu dan artis " << endl;
                cout << "2. Hapus artis pada lagu     " << endl;
                cout << "-----------------------------" << endl;
                cout << "Masukkan pilihan: ";
                cin >> choose;
                adrAlbum P;
                if (choose == 1){
                    cout << "Silahkan masukkan lagu di album yang akan Anda hapus: ";
                    cin.ignore();
                    getline(cin, song);
                    adrAlbum Q = first(LR);
                    adrLagu S = searchLagu(LP, song);
                    while (Q != NULL){
                        if (detailLagu(Q) == S){
                            singer = info(detailArtis(Q)).nama;
                            deleteAlbum(LR, P, song, singer);
                            Q = first(LR);
                        } else {
                            Q = next(Q);
                        }
                    }
                } else if (choose == 2){
                    cout << "Kolaborasi dilagu apa yang akan Anda hapus? ";
                    cin.ignore();
                    getline(cin, song);
                    cout << "Siapa artis yang akan di hapus: ";
                    getline(cin, singer);
                    cout << endl;
                    deleteAlbum(LR, P, song, singer);
                    cout << endl;
                } else {
                    cout << "Input tidak valid." << endl;
                }
            } else {
                cout << "Input tidak valid." << endl;
                cout << endl;
            }
        } else if (pilihan == 4){
            cout << "-----------------------------" << endl;
            cout << "         SEARCH DATA         " << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Cari data artis by lagu" << endl;
            cout << "2. Cari data lagu by artis" << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choose;
            cout << endl;
            if (choose == 1){
                cout << "Silahkan masukkan lagu: ";
                cin.ignore();
                getline(cin, song);
                showArtisByLagu(LR, song);
            } else if (choose == 2){
                cout << "Silahkan masukkan artis: ";
                cin.ignore();
                getline(cin, singer);
                showLaguByArtis(LR, singer);
            } else {
                cout << "Input tidak valid." << endl;
            }
        } else if (pilihan == 5){
            cout << "-----------------------------" << endl;
            cout << "          SHOW DATA          " << endl;
            cout << "-----------------------------" << endl;
            cout << "1. Tampilkan data lagu" << endl;
            cout << "2. Tampilkan data artis" << endl;
            cout << "3. Tampilkan data album" << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> choose;
            cout << endl;
            if (choose == 1){
                showLagu(LP);
            } else if (choose == 2){
                showArtis(LC);
            } else if (choose == 3){
                showAlbum(LR);
            } else {
                cout << "Input tidak valid." << endl;
            }
        } else if (pilihan == 6){
            cout << "Masukkan lagu: ";
            cin.ignore();
            getline(cin, song);
            countArtisOnLagu(LR, song);
            cout << endl;
        } else if (pilihan == 0){
            break;
        } else {
            cout << "Input tidak valid." << endl;
        }
        pilihan = menu();
    }
    cout << endl;
    cout << "Anda telah keluar dari program!" << endl;
    return 0;
}
