#include <iostream>
#include <string>

using namespace std;

// Struktur Buku
struct Book {
    int ID;
    string Title;
    string Author;
};

// Deklarasi array global dengan kapasitas maksimum 100 buku
const int MAX_BOOKS = 100;
Book catalog[MAX_BOOKS];
int bookCount = 0; // Menyimpan jumlah buku saat ini

// Fungsi untuk menambahkan buku ke katalog
void addBook(const Book& book) {
    if (bookCount >= MAX_BOOKS) {
        cout << "Katalog penuh! Tidak dapat menambahkan buku baru." << endl;
        return;
    }
    catalog[bookCount++] = book; // Menambahkan buku dan meningkatkan jumlah buku
}


// Fungsi Bubble Sort Rekursif untuk mengurutkan katalog berdasarkan ID
void bubbleSortRecursive(int n) {
    if (n == 1) {
        return;
    }
    for (int j = 0; j < n - 1; ++j) {
        if (catalog[j].ID > catalog[j + 1].ID) {
            Book temp = catalog[j];
            catalog[j] = catalog[j + 1];
            catalog[j + 1] = temp;
        }
    }
    bubbleSortRecursive(n - 1);
}

// Fungsi Linear Search Rekursif untuk mencari buku berdasarkan ID
int linearSearchRecursive(int targetID, int index) {
    if (index >= bookCount) {
        return -1;
    }
    if (catalog[index].ID == targetID) {
        return index;
    }
    return linearSearchRecursive(targetID, index + 1);
}

// Fungsi rekursif Binary Search untuk mencari buku berdasarkan ID
int binarySearchRecursive(int targetID, int low, int high) {
    if (high < low) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (catalog[mid].ID == targetID) {
        return mid;
    } else if (catalog[mid].ID > targetID) {
        return binarySearchRecursive(targetID, low, mid - 1);
    } else {
        return binarySearchRecursive(targetID, mid + 1, high);
    }
}


// Fungsi untuk menghapus buku dari katalog berdasarkan ID
bool removeBook(int targetID) {
    int index = linearSearchRecursive(targetID, 0);
    if (index == -1) {
        return false;
    }
    // Menggeser buku setelah yang dihapus
    for (int i = index; i < bookCount - 1; ++i) {
        catalog[i] = catalog[i + 1];
    }
    bookCount--;
    return true;
}

// Fungsi untuk menampilkan katalog buku
void displayCatalog() {
    if (bookCount == 0) {
        cout << "Katalog kosong." << endl;
        return;
    }
    cout << "Katalog Buku:" << endl;
    for (int i = 0; i < bookCount; ++i) {
        cout << " ID: " << catalog[i].ID << ", Title: " << catalog[i].Title << ", Author: " << catalog[i].Author << endl;
    }
}

int main() {
    addBook({1, "To Kill a Mockingbird", "Harper Lee"});
    addBook({4, "1984", "George Orwell"});
    addBook({2, "The Great Gatsby", "F. Scott Fitzgerald"});
    addBook({7, "Pride and Prejudice", "Jane Austen"});
    addBook({3, "The Catcher in the Rye", "J.D. Salinger"});
    addBook({6, "War and Peace", "Leo Tolstoy"});
    addBook({5, "Harry Potter dan Batu Bertuah", "J.K. Rowling"});
    
    // Mengurutkan katalog menggunakan Bubble Sort Iteratif
    bubbleSortRecursive(bookCount);

    // Menampilkan katalog buku
    displayCatalog();

    // Mencari buku dengan ID 3 secara iteratif
    int targetID = 3;
    int index = linearSearchRecursive(targetID, 0);
    if (index != -1) {
        cout << "\nLinear Search Rekursif: Buku dengan ID " << targetID << " ditemukan di indeks " << index
             << ": {ID:" << catalog[index].ID << ", Title:" << catalog[index].Title << ", Author:" << catalog[index].Author << "}" << endl;
    } else {
        cout << "\nLinear Search Iteratif: Buku dengan ID " << targetID << " tidak ditemukan." << endl;
    }

    // Menghapus buku dengan ID 1
    targetID = 1;
    if (removeBook(targetID)) {
        cout << "\nRemove Book: Buku dengan ID " << targetID << " berhasil dihapus." << endl;
    } else {
        cout << "\nRemove Book: Buku dengan ID " << targetID << " gagal dihapus (tidak ditemukan)." << endl;
    }

    // Menampilkan katalog buku setelah penghapusan
    displayCatalog();

    // Menambahkan buku lagi untuk demonstrasi Bubble Sort Rekursif
    addBook({6, "War and Peace", "Leo Tolstoy"});
    addBook({0, "The Catcher in the Rye", "J.D. Salinger"});

    // Mengurutkan katalog menggunakan Bubble Sort Rekursif
    bubbleSortRecursive(bookCount);

    // Menampilkan katalog setelah pengurutan rekursif
    displayCatalog();

    return 0;
}