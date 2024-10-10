#include "romanist.h"
#include <iostream>
#include <fstream>

using namespace std;

Romanist::Romanist() : name(""), years(""), books(""), bio("") {}

Romanist::Romanist(const string& n, const string& y, const string& b, const string& bio)
    : name(n), years(y), books(b), bio(bio) {}

Romanist::Romanist(const Romanist& other)
    : name(other.name), years(other.years), books(other.books), bio(other.bio) {}

Romanist::~Romanist() {}

void Romanist::set_name(string n) {
    name = n;
}

string Romanist::get_name() {
    return name;
}

void Romanist::set_years(string y) {
    years = y;
}

string Romanist::get_years() {
    return years;
}

void Romanist::set_books(string b) {
    books = b;
}

string Romanist::get_books() {
    return books;
}

void Romanist::set_bio(string b) {
    bio = b;
}

string Romanist::get_bio() {
    return bio;
}

void Romanist::display_obj() {
    cout << "Romanist Name: " << name << endl;
    cout << "Years: " << years << endl;
    cout << "Books: " << poems << endl;
    cout << "Bio: " << bio << endl;
}

void Romanist::change_info() {
    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Enter new years: ";
    getline(cin, years);
    cout << "Enter new books: ";
    getline(cin, poems);
    cout << "Enter new bio: ";
    getline(cin, bio);
}

void Romanist::save_in_file(ostream& out) {
    out << name << endl;
    out << years << endl;
    out << books << endl;
    out << bio << endl;
}

void Romanist::load_from_file(istream& in) {
    getline(in, name);
    getline(in, years);
    getline(in, books);
    getline(in, bio);
}
