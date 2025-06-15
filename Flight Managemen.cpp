#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <limits>

using namespace std;

// Struktur data untuk Penumpang
struct Passenger {
    int id;
    string name;
    string flightNumber;
    string destination;
    string seatNumber;

    Passenger(int id, string name, string flight, string dest, string seat) 
        : id(id), name(name), flightNumber(flight), destination(dest), seatNumber(seat) {}

    Passenger() : id(0), name(""), flightNumber(""), destination(""), seatNumber("") {}
};

class PassengerManagementSystem {
private:
    vector<Passenger> passengers;
    unordered_map<int, vector<int>> hashTable;

    int hashFunction(int id) {
        return id % 10;
    }

    void updateHashTable() {
        hashTable.clear();
        for (int i = 0; i < passengers.size(); i++) {
            int hashKey = hashFunction(passengers[i].id);
            hashTable[hashKey].push_back(i);
        }
    }

    void sortByName() {
        for (int i = 0; i < passengers.size() - 1; i++) {
            for (int j = 0; j < passengers.size() - i - 1; j++) {
                if (passengers[j].name > passengers[j + 1].name) {
                    swap(passengers[j], passengers[j + 1]);
                }
            }
        }
        updateHashTable();
    }

    int findPassengerById(int id) {
        int hashKey = hashFunction(id);
        if (hashTable.find(hashKey) != hashTable.end()) {
            for (int index : hashTable[hashKey]) {
                if (index < passengers.size() && passengers[index].id == id) {
                    return index;
                }
            }
        }
        return -1;
    }

public:
    void addPassenger() {
        int id;
        string name, flight, destination, seat;

        cout << "\n=== TAMBAH PENUMPANG BARU ===" << endl;
        cout << "Masukkan ID Penumpang: ";
        cin >> id;

        if (findPassengerById(id) != -1) {
            cout << "ID Penumpang sudah ada! Gunakan ID yang berbeda." << endl;
            return;
        }

        cin.ignore();
        cout << "Masukkan Nama Penumpang: "; getline(cin, name);
        cout << "Masukkan Nomor Penerbangan: "; getline(cin, flight);
        cout << "Masukkan Tujuan: "; getline(cin, destination);
        cout << "Masukkan Nomor Kursi: "; getline(cin, seat);

        passengers.push_back(Passenger(id, name, flight, destination, seat));
        updateHashTable();

        cout << "Penumpang berhasil ditambahkan!" << endl;
    }

    void displayAllPassengers() {
        if (passengers.empty()) {
            cout << "\nTidak ada data penumpang." << endl;
            return;
        }

        sortByName();
        cout << "\n=== DAFTAR PENUMPANG (Terurut berdasarkan Nama) ===" << endl;
        cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
        cout << left << setw(5) << "ID" << setw(20) << "Nama" 
             << setw(15) << "No. Penerbangan" << setw(20) << "Tujuan" 
             << setw(10) << "No. Kursi" << endl;
        cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;

        for (const auto& p : passengers) {
            cout << left << setw(5) << p.id << setw(20) << p.name 
                 << setw(15) << p.flightNumber << setw(20) << p.destination 
                 << setw(10) << p.seatNumber << endl;
        }
        cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;

        cout << "\n=== INFORMASI HASH TABLE ===" << endl;
        for (const auto& pair : hashTable) {
            cout << "Hash Key " << pair.first << ": ";
            for (int index : pair.second) {
                cout << passengers[index].name << " (ID:" << passengers[index].id << ") ";
            }
            cout << endl;
        }
    }

    void editPassenger() {
        if (passengers.empty()) {
            cout << "\nTidak ada data penumpang untuk diedit." << endl;
            return;
        }

        int id;
        cout << "\n=== EDIT DATA PENUMPANG ===" << endl;
        cout << "Masukkan ID Penumpang yang akan diedit: ";
        cin >> id;

        int index = findPassengerById(id);
        if (index == -1) {
            cout << "Penumpang dengan ID " << id << " tidak ditemukan!" << endl;
            return;
        }

        cout << "\nData saat ini:" << endl;
        cout << "ID: " << passengers[index].id << endl;
        cout << "Nama: " << passengers[index].name << endl;
        cout << "No. Penerbangan: " << passengers[index].flightNumber << endl;
        cout << "Tujuan: " << passengers[index].destination << endl;
        cout << "No. Kursi: " << passengers[index].seatNumber << endl;

        cin.ignore();
        string newName, newFlight, newDestination, newSeat;

        cout << "\nMasukkan data baru (tekan Enter untuk tidak mengubah):" << endl;
        cout << "Nama baru: "; getline(cin, newName);
        if (!newName.empty()) passengers[index].name = newName;

        cout << "No. Penerbangan baru: "; getline(cin, newFlight);
        if (!newFlight.empty()) passengers[index].flightNumber = newFlight;

        cout << "Tujuan baru: "; getline(cin, newDestination);
        if (!newDestination.empty()) passengers[index].destination = newDestination;

        cout << "No. Kursi baru: "; getline(cin, newSeat);
        if (!newSeat.empty()) passengers[index].seatNumber = newSeat;

        cout << "Data penumpang berhasil diperbarui!" << endl;
    }

    void deletePassenger() {
        if (passengers.empty()) {
            cout << "\nTidak ada data penumpang untuk dihapus." << endl;
            return;
        }

        int id;
        cout << "\n=== HAPUS DATA PENUMPANG ===" << endl;
        cout << "Masukkan ID Penumpang yang akan dihapus: ";
        cin >> id;

        int index = findPassengerById(id);
        if (index == -1) {
            cout << "Penumpang dengan ID " << id << " tidak ditemukan!" << endl;
            return;
        }

        cout << "Data yang akan dihapus:" << endl;
        cout << "ID: " << passengers[index].id << endl;
        cout << "Nama: " << passengers[index].name << endl;
        cout << "No. Penerbangan: " << passengers[index].flightNumber << endl;

        char confirm;
        cout << "Yakin ingin menghapus data ini? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            passengers.erase(passengers.begin() + index);
            updateHashTable();
            cout << "Data penumpang berhasil dihapus!" << endl;
        } else {
            cout << "Penghapusan dibatalkan." << endl;
        }
    }

    void searchPassenger() {
        if (passengers.empty()) {
            cout << "\nTidak ada data penumpang." << endl;
            return;
        }

        int id;
        cout << "\n=== CARI PENUMPANG ===" << endl;
        cout << "Masukkan ID Penumpang: ";
        cin >> id;

        int index = findPassengerById(id);
        if (index != -1) {
            cout << "\nPenumpang ditemukan!" << endl;
            cout << "ID: " << passengers[index].id << endl;
            cout << "Nama: " << passengers[index].name << endl;
            cout << "No. Penerbangan: " << passengers[index].flightNumber << endl;
            cout << "Tujuan: " << passengers[index].destination << endl;
            cout << "No. Kursi: " << passengers[index].seatNumber << endl;
            cout << "\nInformasi Hash: Ditemukan di Hash Key " << hashFunction(id) << endl;
        } else {
            cout << "Penumpang dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }

    void displayMenu() {
        cout << "\n" << setfill('=') << setw(50) << "" << setfill(' ') << endl;
        cout << "     SISTEM MANAJEMEN PENUMPANG PESAWAT" << endl;
        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
        cout << "1. Tambah Penumpang" << endl;
        cout << "2. Lihat Semua Penumpang" << endl;
        cout << "3. Edit Data Penumpang" << endl;
        cout << "4. Hapus Penumpang" << endl;
        cout << "5. Cari Penumpang" << endl;
        cout << "6. Keluar" << endl;
        cout << setfill('=') << setw(50) << "" << setfill(' ') << endl;
        cout << "Pilihan Anda: ";
    }

    void run() {
        int choice;
        do {
            displayMenu();
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInput tidak valid! Harap masukkan angka." << endl;
                choice = 0;
            }

            switch (choice) {
                case 1: addPassenger(); break;
                case 2: displayAllPassengers(); break;
                case 3: editPassenger(); break;
                case 4: deletePassenger(); break;
                case 5: searchPassenger(); break;
                case 6:
                    cout << "\nTerima kasih telah menggunakan Sistem Manajemen Penumpang!" << endl;
                    break;
                default:
                    cout << "\nPilihan tidak valid! Silakan pilih 1-6." << endl;
            }

            if (choice != 6) {
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            }
        } while (choice != 6);
    }
};

int main() {
    PassengerManagementSystem pms;
    pms.run();
    return 0;
}
