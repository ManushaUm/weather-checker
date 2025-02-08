#pragma once
#include <fstream>
#include <queue>

//using namespace std;

void getfiledata(string file) {
	fstream myFile;
	myFile.open("file.txt", ios::in);

    if (myFile.is_open()) {
        queue queue1;
        string line;
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
}

