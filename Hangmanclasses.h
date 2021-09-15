#include<iostream>
#include<string>
#include<xstring>
using namespace std;

class Hangman {
	string playername;
	int wrongchances;
	string guessword;
	string starword;
public:
	Hangman(string Gword, string Pname) {
		playername = Pname;
		wrongchances = 5;
		guessword = Gword;
		starword = Gword;
		int i = 0;
		for (i = 0; i < guessword.size(); i++) {
			if (guessword[i] == '-') {
				starword[i] = '-';
			}
			else {
				starword[i] = '*';
			}
		}
		starword[i] = '\0';
	}

	int getWrongChances() {
		return wrongchances;
	}

	string getStarWord() {
		return starword;
	}

	string getGuessWord() {
		return guessword;
	}

	bool setstarword(char s) {
		int count = 0;
		for (int i = 0; i < guessword.size(); i++) {
			if (guessword[i] == s) {
				starword[i] = s;
				count++;
			}
			if (guessword[i] == (s + 32)) {
				starword[i] = s+32;
				count++;
			}
			if (guessword[i] == (s - 32)) {
				starword[i] = s-32;
				count++;
			}
		}
		if (count == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	void setWrongChances() {
		wrongchances--;
	}
	bool checkExsitence(char s) {
		for (int i = 0; i < starword.size(); i++) {
			if (starword[i] == s) {
				return true;
			}
		}
		return false;
	}
	bool checkletter(char s) {
		int upper, lower;
		upper = 65, lower = 97;
		for (int i = 0; i <= 25; i++) {
			if (s == upper + i || s == lower + i) {
				return true;
			}
		}
		return false;
	}
};
