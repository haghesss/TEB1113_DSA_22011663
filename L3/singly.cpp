#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        next = nullptr;
    }
};

int main() {

    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Bob");
    Node* node3 = new Node("Cade");

    node1->next = node2;
    node2->next = node3;

    cout << "Before deletion: ";
    Node* current = node1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    node1->next = node3;
    delete node2;

    cout << "After deletion: ";
    current = node1;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    current = node1;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
