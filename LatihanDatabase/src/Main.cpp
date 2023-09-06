#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Mahasiswa
{
public:
    string nama;
    string NIM;
    string jurusan;

    Mahasiswa(string nama, string NIM, string jurusan){
        Mahasiswa::nama = nama;
        Mahasiswa::NIM = NIM;
        Mahasiswa::jurusan = jurusan;
    }

    string stringify() {
        return nama + ";" + NIM + ";" + jurusan;
    }
};

class DB 
{
public:
    unsigned long newId = 0;
    ifstream in;
    ofstream out;
    string fileName;

    DB(const char* fileName) {
        DB::fileName = fileName;
    }

    unsigned long lastId() {
        string lastLine;

        DB::in.open(DB::fileName, ios::in);
        if (DB::in.is_open()) {
            DB::in.seekg(-1,ios_base::end);
            bool keepLooping = true;
            while (keepLooping) {
                char ch;
                DB::in.get(ch);

                if((int)DB::in.tellg() <= 1) {            
                    DB::in.seekg(0);         
                    keepLooping = false; 
                }
                else if(ch == '\n') {                   
                    keepLooping = false;                
                }
                else {                                  
                    DB::in.seekg(-2,ios_base::cur);        
                }
            }   
            getline(DB::in,lastLine);
        }

        stringstream s(lastLine);
        vector<int> result;

        unsigned long foundId;

        if (lastLine != "") {
            for (int i; s >> i;) {
                result.push_back(i);    
                if (s.peek() == ';') break;
            }
            for (size_t i = 0; i < result.size(); i++) foundId = result[i];
        } else {
            foundId = 0;
        }
        DB::in.close();
        return foundId;
    }

    void save(Mahasiswa data) {
        DB::out.open(DB::fileName, ios::app);
        DB::newId = DB::lastId() + 1;
        
        DB::in.open(DB::fileName, ios::in);
        DB::in.seekg(0, ios::end);
        if (DB::in.tellg() == 0) {    
            DB::out << "id;nama;NIM;jurusan";
        }
        DB::in.close();

        DB::out << "\n";
        DB::out << DB::newId;
        DB::out << ";" + data.stringify();
        
        DB::out.close();
    }

    void showAll() {
        DB::in.open(DB::fileName, ios::in);
        cout << "\nData Mahasiswa\n";
        cout << DB::in.rdbuf();
        cout << "\n\n";
        DB::in.close();
    }
};

int main()
{
    DB database = DB("data/data.txt");
    database.showAll();

    string nama, NIM, jurusan;
    cout << "Masukkan Data Mahasiswa" << endl;
    cout << " Nama\t\t: ";
    cin >> nama;
    cout << " NIM\t\t: ";
    cin >> NIM;
    cout << " Jurusan\t: ";
    cin >> jurusan;

    Mahasiswa dataMahasiswa = Mahasiswa(nama, NIM, jurusan);

    database.save(dataMahasiswa);
    database.showAll();

    return 0;
}
