#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <bit>
#include <Vector>
#include <unordered_map>

using std::string;
using std::bitset;

class Hash {
private :
	string text;
	string binary;
	string hash;
	std::vector <string> words;

public:
	Hash() {text = ""; binary = ""; hash = "";}
	Hash(const string input) {text = input; binary = ""; hash = "";}
	Hash operator= (const string input) { text = input; binary = ""; hash = "", words.clear(); return *this; }
	~Hash() {}

	string hashing() {
		mash();
		return hash;
	}

private:

	string toBinary(string s) {
		string bin = "";
		for (char const& c : s) {
			bin += bitset<8>(c).to_string();
		}
		return bin;
	}

	string binToHex(string bin) {
		string s = "";
		std::unordered_map<string, char> hex;
		hex["0000"] = '0';
		hex["0001"] = '1';
		hex["0010"] = '2';
		hex["0011"] = '3';
		hex["0100"] = '4';
		hex["0101"] = '5';
		hex["0110"] = '6';
		hex["0111"] = '7';
		hex["1000"] = '8';
		hex["1001"] = '9';
		hex["1010"] = 'a';
		hex["1011"] = 'b';
		hex["1100"] = 'c';
		hex["1101"] = 'd';
		hex["1110"] = 'e';
		hex["1111"] = 'f';

		for (int i = 0; i < bin.length(); i += 4) {
			s += hex[bin.substr(i, 4)];
		}
		return s;
	}

	void padding() {
		binary = toBinary(text);
		int l = binary.length();
		int x = l / 256 + 1;
		binary.resize(256 * x -  1, '0');
		binary += '1';
	}

	void mash() {
		padding();
		for (int i = 0; i < binary.length(); i += 32) {
			words.push_back(binary.substr(i, 32));
		}
		int n = 2 * words.size() + 40;
		for (int i = 8; i < n; i++) {

			bitset<32> a(words[i - 8]);
			bitset<32> b(words[i - 6]);
			bitset<32> c(words[i - 3]);
			bitset<32> d(words[i - 1]);

			bitset<32> xoa = (a ^ b);
			bitset<32> xob = (xoa ^ c);
			bitset<32> xoc = (xob ^ d);
			std::string word = std::bitset<32> (std::rotl(xoc.to_ulong(), 1)).to_string();
			words.push_back(word);

		}

		bitset<32> k1("10110100111001111000101000100101");
		bitset<32> k2("11010101010100100010000011110001");
		bitset<32> k3("01100111000110101000101101001000");
		bitset<32> k4("00010111000000000011100110100111");
		bitset<32> k5("00101101010111001000001001000110");
		bitset<32> k6("10101110010000000000011010101000");
		bitset<32> k7("10011011000100011100110101101110");
		bitset<32> k8("10110100011010000110110110011100");

		for (int i = 36; i < n; i++) {
			bitset<32> a(words[i - 36]);
			bitset<32> b(words[i - 33]);
			bitset<32> c(words[i - 29]);
			bitset<32> d(words[i - 23]);
			bitset<32> e(words[i - 17]);
			bitset<32> f(words[i - 11]);
			bitset<32> g(words[i - 5]);
			bitset<32> h(words[i - 1]);

			bitset<32> xoa = (a ^ b);
			bitset<32> xob = (xoa ^ c);
			bitset<32> xoc = (xob ^ d);
			bitset<32> xod = (xoc ^ e);
			bitset<32> xoe = (xoa ^ f);
			bitset<32> xof = (xob ^ g);
			bitset<32> xog = (xob ^ h);
			k1 ^= xog;
			k2 ^= xog;
			k3 ^= xog;
			k4 ^= xog;
			k5 ^= xog;
			k6 ^= xog;
			k7 ^= xog;
			k8 ^= xog;
		}
		hash = binToHex(k1.to_string() + k2.to_string() + k3.to_string() + k4.to_string() + k5.to_string() + k6.to_string() + k7.to_string() + k8.to_string());

	}

};