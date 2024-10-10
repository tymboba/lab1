#include "poet.h"
#include <iostream>
#include <fstream>

using namespace std;

Poet::Poet() : name(""), years(""), poems("") {}

Poet::Poet(const string& n, const string& y, const string& p) : name(n), years(y), poems(p) {}

Poet::Poet(const Poet& other) : name(other.name), years(other.years), poems(other.poems) {}

Poet::~Poet() {}

void Poet::set_name(string n) {
    name = n;
}

string Poet::get_name() {
    return name;
}

void Poet::set_years(string y) {
    years = y;
}

string Poet::get_years() {
    return years;
}

void Poet::set_poems(string p) {
    poems = p;
}

string Poet::get_poems() {
    return poems;
}

void Poet::display_obj() {
    cout << "Poet Name: " << name << endl;
    cout << "Years: " << years << endl;
    cout << "Poems: " << poems << endl;
}

void Poet::change_info() {
    cout << "Enter new name: ";
    getline(cin, name);
    cout << "Enter new years: ";
    getline(cin, years);
    cout << "Enter new poems: ";
    getline(cin, poems);
}

void Poet::save_in_file(ostream& out) {
    out << name << endl;
    out << years << endl;
    out << poems << endl;
}

void Poet::load_from_file(istream& in) {
    getline(in, name);
    getline(in, years);
    getline(in, poems);
}
