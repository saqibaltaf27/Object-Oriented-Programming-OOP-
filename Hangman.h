#pragma once
#include<iostream>
using namespace std;
void printHangman(int wrongchances) {
	switch (wrongchances) {
	case 1:
		cout << "\t  _____________ \n\t        |\n\t        O\n";
		break;
	case 2:
		cout << "\t  _____________ \n\t        |\n\t        O\n\t        |/\n";
		break;
	case 3:
		cout << "\t  _____________ \n\t        |\n\t        O\n\t       \\|/\n";
		break;
	case 4:
		cout << "\t  _____________ \n\t        |\n\t        O\n\t       \\|/\n";
		cout << "\t        |\n\t       /\n";
		break;
	case 5:
		cout << "\t  _____________ \n\t        |\n\t        O\n\t       \\|/\n";
		cout << "\t        |\n\t       / \\\n";
		break;
	default:
		break;
	}

}