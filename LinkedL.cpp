//Ad-Soyad : Aya Khalifa    NO : 1306220166
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    string name;
    int id;
    Node* next;

    // Constructor
    Node(const string& n, int i) : name(n), id(i), next(nullptr) {}
};

// Function to add a new node to the linked list
void addStudent(Node*& head, const string& name, int id) {
    Node* newNode = new Node(name, id);
    newNode->next = head;
    head = newNode;
}

// Function to delete the linked list to avoid memory leaks
void deleteLinkedList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to read student information from file and add to linked list
void readStudentsFromFile(Node*& head, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int id;

        // Parse student information
        if (ss >> name >> id) {
            // Add student to linked list
            addStudent(head, name, id);
        } else {
            cerr << "Warning: Unable to parse line: " << line << endl;
        }
    }

    file.close();
}

// Function to print the linked list
void printLinkedList(Node* head) {
    cout << "Students:" << endl;
    while (head) {
        cout << "Name: " << head->name << ", ID: " << head->id << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr; // Initialize head pointer of the linked list

    readStudentsFromFile(head, "students.txt"); // Read student information from file and add to linked list

    printLinkedList(head); // Print the linked list

    // Delete the linked list to free memory
    deleteLinkedList(head);

    return 0;
}
