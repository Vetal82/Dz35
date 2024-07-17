#include <iostream>

template <typename T>
class DNode {
public:
    T info;
    DNode* prev;
    DNode* next;

    DNode(T a) { info = a; next = prev = nullptr; }
};

template <typename U>
class DList {
    DNode<U>* head;
    DNode<U>* current;
public:
    DList() { head = nullptr; current = nullptr; }
    ~DList() {
        while (head) {
            DNode<U>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(U value) {
        DNode<U>* newNode = new DNode<U>(value);
        if (!head) {
            head = newNode;
        }
        else {
            DNode<U>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void show() {
        DNode<U>* temp = head;
        while (temp) {
            std::cout << temp->info << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    DNode<U>* search(U value) {
        DNode<U>* temp = head;
        while (temp) {
            if (temp->info == value) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void push_front(U value) {
        DNode<U>* newNode = new DNode<U>(value);
        if (!head) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBefore(U before, U value) {
        DNode<U>* newNode = new DNode<U>(value);
        DNode<U>* temp = search(before);
        if (temp) {
            if (temp == head) {
                push_front(value);
            }
            else {
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
        }
    }

    void insertAfter(U after, U value) {
        DNode<U>* newNode = new DNode<U>(value);
        DNode<U>* temp = search(after);
        if (temp) {
            if (!temp->next) {
                push_back(value);
            }
            else {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
        }
    }

    void erase(U value) {
        DNode<U>* temp = search(value);
        if (temp) {
            if (temp == head) {
                head = temp->next;
            }
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }
};

int main() {
    DList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.show(); 

    list.push_front(0);

    list.show(); 

    list.insertBefore(2, 1.5);

    list.show(); 

    list.insertAfter(1, 1.25);

    list.show(); 

    list.erase(1.5);

    list.show(); 

    return 0;
}