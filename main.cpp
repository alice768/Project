//Абрамова Алиса Григорьевна
//Файловая БД библиотеки
#include <iostream>
#include "library_database.h"

using namespace std;
int main() {
    LibraryDatabase db("/Users/alice/Programming/untitled/data.txt");
    book b1 = {"Emma", "Jane Austen", 1815};
    db.addBook(b1);
    db.deleteBook("1984");
    vector<book> results = db.searchBook("Fitzgerald");
    for (book b: results) {
        cout << b.title << " by " << b.author << endl;
    }
   
    db.displayAllBooks();
    return 0;
}

