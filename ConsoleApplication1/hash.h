#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

const int TABLE_SIZE = 10;
using namespace std;


struct Node {
    string key;
    string fileLink;  // CSV file
    Node* next;
    
    Node(const string& k, const string& link) {
        key = k;
        fileLink = link;
        next = nullptr;
    }
    
};


class HashTable {
private:
    Node* table[TABLE_SIZE];

    
    int hash(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue = (hashValue * 31 + ch) % TABLE_SIZE;
        }
        return hashValue;
    }

public:
    
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }


    void insert(const string& key, const string& fileLink) {
        int index = hash(key);
        Node* newNode = new Node(key, fileLink);

 
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            
            newNode->next = table[index];
            table[index] = newNode;
        }
    }


    string get(const string& key) {
        int index = hash(key);

        
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->fileLink; // return the file link
            }
            current = current->next;
        }

        return ""; 
    }

    void readFileContent(const string& key) {
        string fileLink = get(key);

        if (fileLink.empty()) {
            cout << "Weather Updater for district '" << key << "' not found." << endl;
            return;
        }

        ifstream file(fileLink);

        if (file.is_open()) {
            
            cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl; 

            string line;
            while (getline(file, line)) {
                
                stringstream ss(line);
                string column1, column2, column3 , column4, column5;

                getline(ss, column1, ',');
                getline(ss, column2, ',');
                getline(ss, column3, ',');
                getline(ss, column4, ',');
                getline(ss, column5, ',');

                // Create outout table format
                cout << left << setw(15) << column1 << setw(15) << column2 << setw(15) << column3 << setw(15) << column4 << setw(15) <<column5<<endl;
            }
            file.close();
        }
        else {
            cerr << "Please Restart the program '" << key << "'." << endl;
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
    }
};

