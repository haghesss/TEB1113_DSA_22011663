#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* new_node = new Node(name);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next_ptr = new_node;
            rear = new_node;
        }
    }

    void display_queue() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next_ptr;
        cout << "Dequeued: " << temp->name << endl;
        delete temp;
    }
};

int main() {
    cout << "Queue" << endl;
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alice");

    cout << "Queue: ";
    queue.display_queue();

    queue.dequeue();

    cout << "After dequeueing: " << endl;
    queue.display_queue();

    return 0;
}