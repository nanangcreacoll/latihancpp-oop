#include <iostream>

using namespace std;

class Mahasiswa{
    public:
        string nama;
        string NIM;
        string jurusan;
        double IPK;
        
        //constructor
        // Mahasiswa(){
        //     cout << "ini adalah constructor" << endl;
        // }

        //constructor dengan parameter
        Mahasiswa(string inputNama, string inputNIM, string inputJurusan, double inputIPK){
            Mahasiswa::nama = inputNama;
            Mahasiswa::NIM = inputNIM;
            Mahasiswa::jurusan = inputJurusan;
            Mahasiswa::IPK = inputIPK;

            cout << Mahasiswa::nama << endl;
            cout << Mahasiswa::NIM << endl;
            cout << Mahasiswa::jurusan << endl;
            cout << Mahasiswa::IPK << endl;
        }
};

int main()
{
    Mahasiswa mahasiswa1 = Mahasiswa("ucup", "1330504", "pertanian", 4.0);
    Mahasiswa mahasiswa2 = Mahasiswa("otong", "13305042", "peternakan", 3.0);

    return 0;
}
