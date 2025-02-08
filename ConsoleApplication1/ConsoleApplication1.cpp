#include <iostream>
#include <string>
#include "hash.h"
#include "menu.h"
#include <fstream>
#include <time.h>

using namespace std;

//declarations
HashTable myHashTable;
string userInput;
string keys[] = {"key1", "key2", "key3", "key4", "key5", "key6", "key7", "key8", "key9", "key10", "key11", "key12", "key13", "key14", "key15", "key16", "key17", "key18", "key19", "key20", "key21", "key22", "key23", "key24", "key25"};
string district_list[] = {"Colombo", "Gampaha", "Kalutara", "Kandy", "Matale", "Nuwara Eliya", "Galle", "Matara", "Hambantota", "Jaffna", "Kilinochchi", "Mannar", "Mullaitivu", "Vavuniya", "Batticaloa", "Ampara", "Trincomalee", "Kurunegala", "Puttalam", "Anuradhapura", "Polonnaruwa", "Badulla", "Monaragala", "Ratnapura", "Kegalle"};
    


int main() {
    // ***Insert District list with csv files ***
    myHashTable.insert("Colombo", "Colombo.csv");
    myHashTable.insert("Gampaha", "Gampaha.csv");
    myHashTable.insert("Kalutara", "Kalutara.csv");
    myHashTable.insert("Kandy", "Kandy.csv");
    myHashTable.insert("Matale", "Matale.csv");
    myHashTable.insert("Nuwara Eliya", "NuwaraEliya.csv");
    myHashTable.insert("Galle", "Galle.csv");
    myHashTable.insert("Matara", "Matara.csv");
    myHashTable.insert("Hambantota", "Hambantota.csv");
    myHashTable.insert("Jaffna", "Jaffna.csv");
    myHashTable.insert("Kilinochchi", "Kilinochchi.csv");
    myHashTable.insert("Mannar", "Mannar.csv");
    myHashTable.insert("Mullaitivu", "Mullaitivu.csv");
    myHashTable.insert("Vavuniya", "Vavuniya.csv");
    myHashTable.insert("Batticaloa", "Batticaloa.csv");
    myHashTable.insert("Ampara", "Ampara.csv");
    myHashTable.insert("Trincomalee", "Trincomalee.csv");
    myHashTable.insert("Kurunegala", "Kurunegala.csv");
    myHashTable.insert("Puttalam", "Puttalam.csv");
    myHashTable.insert("Anuradhapura", "Anuradhapura.csv");
    myHashTable.insert("Polonnaruwa", "Polonnaruwa.csv");
    myHashTable.insert("Badulla", "Badulla.csv");
    myHashTable.insert("Monaragala", "Monaragala.csv");
    myHashTable.insert("Ratnapura", "Ratnapura.csv");
    myHashTable.insert("Kegalle", "Kegalle.csv");

    myHashTable.insert("colombo", "Colombo.csv");
    myHashTable.insert("gampaha", "Gampaha.csv");
    myHashTable.insert("kalutara", "Kalutara.csv");
    myHashTable.insert("kandy", "Kandy.csv");
    myHashTable.insert("matale", "Matale.csv");
    myHashTable.insert("nuwara Eliya", "NuwaraEliya.csv");
    myHashTable.insert("galle", "Galle.csv");
    myHashTable.insert("matara", "Matara.csv");
    myHashTable.insert("hambantota", "Hambantota.csv");
    myHashTable.insert("jaffna", "Jaffna.csv");
    myHashTable.insert("kilinochchi", "Kilinochchi.csv");
    myHashTable.insert("mannar", "Mannar.csv");
    myHashTable.insert("mullaitivu", "Mullaitivu.csv");
    myHashTable.insert("vavuniya", "Vavuniya.csv");
    myHashTable.insert("batticaloa", "Batticaloa.csv");
    myHashTable.insert("ampara", "Ampara.csv");
    myHashTable.insert("trincomalee", "Trincomalee.csv");
    myHashTable.insert("kurunegala", "Kurunegala.csv");
    myHashTable.insert("puttalam", "Puttalam.csv");
    myHashTable.insert("anuradhapura", "Anuradhapura.csv");
    myHashTable.insert("polonnaruwa", "Polonnaruwa.csv");
    myHashTable.insert("badulla", "Badulla.csv");
    myHashTable.insert("monaragala", "Monaragala.csv");
    myHashTable.insert("ratnapura", "Ratnapura.csv");
    myHashTable.insert("kegalle", "Kegalle.csv");

    //Header line
    cout << "+-+-+-- Weather Updates --+-+-+" << endl;


    //Menu Start
    char choice;

    do {
        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            cout << "Enter Your current District : ";
            cin >> userInput;
            // Retrieve file links
            myHashTable.get(userInput);
            myHashTable.readFileContent(userInput);
        }
        else if (choice == '2') {
            cout << "Available Districts:" << endl;
            for (int i = 0; i < 25; i++) {
                keys[i] = district_list[i];
                cout << i + 1 << ". " << district_list[i] << endl;
            }
        }
        else if (choice == '0') {
            cout << "Exiting the program." << endl;
            return 0;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '0');
    

   
    for (int i = 0; i < 25; i++) {
        keys[i] = district_list[i];
        cout << "key " << i+1 << ":  " << district_list[i] << endl;
    }
    cout << "Enter Your current District : " ;
    cin >> userInput;
    

    // Retrieve file links
    cout << "Weather update for your current city " << myHashTable.get(userInput) << endl; //print "file1.csv"
    myHashTable.readFileContent(userInput);

    return 0;
}
