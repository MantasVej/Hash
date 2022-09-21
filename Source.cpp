#include <iostream>
#include <Vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include "Hash.h";

using std::cout;
using std::endl;

void Skaitymas(string failas, std::vector<string>& Text) {

    string eil;
    std::stringstream my_buffer;

    try {
        std::ifstream fd(failas);
        fd.exceptions(std::ifstream::failbit);
        my_buffer << fd.rdbuf();
        fd.close();
    }
    catch (std::exception& e) {
        cout << "Toks duomenu failas neegzistuoja." << endl;
        std::exit(EXIT_FAILURE);
    }

    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            Text.push_back(eil);
        }
        else break;
    }
}

int main(int argc, char* argv[])
{
    std::string file;
    if (argc != 2) {
        cout << "Iveskite duomenu failo pavadinima: "; std::cin >> file;
    }
    else file = argv[1];

    std::vector <string> Text;
    Skaitymas("test.txt", Text);
    for (auto& s : Text) {
        Hash h(s);
        cout << h.hashing() << endl;
    }

    return 0;
}

