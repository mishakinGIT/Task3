#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *prev;
    Node *next;
    explicit Node(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void push_front(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
    }
    void remove(int value) {
        Node *node = head;
        while (node != nullptr) {
            if (node->value == value) {
                if (node == head && node == tail) {
                    head = tail = nullptr;
                } else if (node == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (node == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }
                delete node;
                return;
            }
            node = node->next;
        }
    }
    void print() {
        Node *node = head;
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.push_back(3);
    list.print();
    list.remove(1);
    list.print();
    return 0;
}