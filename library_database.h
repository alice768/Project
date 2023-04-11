//Абрамова Алиса Григорьевна
//Файловая БД библиотеки
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct book {
    string title;
    string author;
    int year;
};

class LibraryDatabase {
private:
    string filename;
    vector<book> books;
public:
    LibraryDatabase(string filename) {
        this->filename = filename;
        loadBooks();
    }

    void loadBooks() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                book b;
                int pos1 = line.find(",");
                int pos2 = line.find(",", pos1+1);
                b.title = line.substr(0, pos1);
                b.author = line.substr(pos1+1, pos2-pos1-1);
                b.year = stoi(line.substr(pos2+1));
                books.push_back(b);
            }
            file.close();
        }
    }

    void saveBooks() {
        ofstream file(filename);
        if (file.is_open()) {
            for (book b : books) {
                file << b.title << "," << b.author << "," << b.year << endl;
            }
            file.close();
        }
    }

    void addBook(book b) {
        books.push_back(b);
        saveBooks();
    }

    void deleteBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                books.erase(books.begin() + i);
                saveBooks();
                return;
            }
        }
    }

    vector<book> searchBook(string keyword) {
        vector<book> results;
        for (book b : books) {
            if (b.title.find(keyword) != string::npos || b.author.find(keyword) != string::npos) {
                results.push_back(b);
            }
        }
        return results;
    }

    void displayAllBooks() {
        for (book b : books) {
            cout << b.title << " by " << b.author << " (" << b.year << ")" << endl;
        }
    }
};
