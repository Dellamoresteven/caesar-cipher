#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include <fstream>
using namespace std;

int encyption(string filename){
	ifstream inFile;
	ofstream outfile;
	string enfilename = "Encrypted_" + filename;
	inFile.open(filename);
	if (!inFile) {
    	cerr << "Unable to open file datafile.txt";
    	exit(1);   // call system to stop
	}
	outfile.open(enfilename);
	srand (time(NULL));
	int rot = rand() % 25 + 1; 
	// int rot = 18;
	cout << rot << endl;
	char x;
	while (inFile >> x) {
		if((x >= 65 && x <= 90) || (x >= 97 && x <= 122)){
			if(x >= 65 && x <= 90){
				// cout << x << " : ";
				x += rot;
				if(x > 90){
					x -= 90;
					x += 64;
				}	
			}else{
				// cout << x << " ; ";
				x += rot;
				if(x > 122){
					x -= 122;
					x += 96;
				}else if(x < 0){
					x *= -1;
					x = 127 - x;
					x = x + 103;
				}
			}
		}else{
			outfile << x;
		}
		outfile << x;
		cout << x;
	}	
	cout << endl;
	outfile << "\n";
}


int main(){
	string filename;
	cout << "Enter the file you would like to encrypt" << endl;
	cin >> filename;
	encyption(filename);
}
