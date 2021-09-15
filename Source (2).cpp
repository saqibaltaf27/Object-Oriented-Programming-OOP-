#include"Hangmanclasses.h"
#include <fstream>
#include<cstdlib>
#include<time.h>
#include"Hangman.h"

string getword(int txtchoice) {
	fstream fp;
	if (txtchoice == 0) {
		string word;
		int counter = 0;
		fp.open("surah.txt");
		while (!fp.eof()) {
			fp >> word;
			counter++;
		}
		fp.close();
		fp.open("surah.txt");
		word = "";
		int wordchoice = rand() % counter;
		for (int i = 0; !fp.eof(); i++) {
			fp >> word;
			if (wordchoice == i) {
				break;
			}
		}
		return word;
	}
	else if (txtchoice == 1) {
		string word;
		int counter = 0;
		fp.open("anbiyaa.txt");
		while (!fp.eof()) {
			fp >> word;
			counter++;
		}
		fp.close();
		fp.open("anbiyaa.txt");
		word = "";
		int wordchoice = rand() % counter;
		for (int i = 0; !fp.eof(); i++) {
			fp >> word;
			if (wordchoice == i) {
				break;
			}
		}
		return word;
	}
	else if (txtchoice == 2) {
		string word;
		int counter = 0;
		fp.open("sahaba.txt");
		while (!fp.eof()) {
			fp >> word;
			counter++;
		}
		fp.close();
		fp.open("sahaba.txt");
		word = "";
		int wordchoice = rand() % counter;
		for (int i = 0; !fp.eof(); i++) {
			fp >> word;
			if (wordchoice == i) {
				break;
			}
		}
		return word;
	}
	return " ";
}


int main() {
	string word;
	string pname;
	char letterEntered;
	int txtchoice = 0;
	bool wrongcheck = false;
	srand(time(NULL));
	txtchoice = rand() % 3;
	word = getword(txtchoice);
	cout << "\t\tENTER YOUR NAME: ";
	cin >> pname;
	Hangman H(word, pname);
	cout << "\n\t Welcome " << pname << " to the game Hangman" << endl;
	if (txtchoice == 0) {
		cout << "\n\t I am thinking of Surah" << endl;
	}
	else if (txtchoice == 1) {
		cout << "\n\t I am thinking of Nabi" << endl;
	}
	else if (txtchoice == 2) {
		cout << "\n\t I am thinking of Sahabi" << endl;
	}

	while (H.getWrongChances() != 0) {
		if (H.getGuessWord() == H.getStarWord()) {
			cout << "\n\t WELLDONE YOU'VE GUESSED IT CORRECTLY\n" << endl;
			return 0;
		}
		error1:
		cout << "\n\t Current letters that are guessed: " << H.getStarWord() << endl;
		cout << " \n\t Enter a letter: ";
		cin >> letterEntered;
		if (!H.checkletter(letterEntered)) {
			cout << "\n\t *+*+*+*+*Enter A LETTER*+*+*+*+*" << endl;
			goto error1;
		}
		if (H.checkExsitence(letterEntered)) {
			cout << "\n\t *+*+*+*+*+*LETTER IS AlREADY ENTERED*+*+*+*+*+*" << endl;
			goto error1;
		}
		wrongcheck = H.setstarword(letterEntered);
		if (!wrongcheck) {
			H.setWrongChances();
		}
		cout << "\n\t Total chances you have: " << H.getWrongChances() << endl;
		printHangman(5 - H.getWrongChances()); cout << endl;
	}
	cout << "\n\t I WAS THINKING OF : " << H.getGuessWord() << endl;
	cout << "\n\t WELLPLAYED!! NICE TRY!!^_^\n" << endl;
	system("pause");
	return 0;
}