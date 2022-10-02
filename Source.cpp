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
void Isvedimas(std::vector<string>& Hashes) {
    std::ofstream fr("hash.txt");
    std::stringstream my_buffer;
    for (auto a : Hashes) {
        my_buffer << a << endl;
    };
    fr << my_buffer.str();
    fr.close();
}
void Collisions(std::vector<string>& Hashes) {
    int c = 0;
    std::unordered_map<string, int> m;
    for (auto a : Hashes) {
        if (!m.count(a)) m[a] = 1;
        else { m[a]++; c++; cout << a << endl; }
    }
    cout << c << " collisions out of " << Hashes.size() << " hashes" << endl;
}
int main(int argc, char* argv[])
{
    std::string file;
    if (argc != 2) {
        cout << "Iveskite duomenu failo pavadinima: "; std::cin >> file;
    }
    else file = argv[1];

    std::vector <string> Text;
    std::vector <string> Hashes;
    Skaitymas(file, Text);
    for (auto a : Text) {
        Hash h(a);
        Hashes.push_back(h.hashing());
    };
    Collisions(Hashes);
    Isvedimas(Hashes);

    return 0;
}

