#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}

    Node(int n) : data(n), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        Node* temp;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    void InsertAtHead(int data1) {
        Node* newnode = new Node(data1);
        newnode->next = head;
        head = newnode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void InsertAtTail(int ele) {
        Node* newnode = new Node(ele);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void printForward() {
        Node* node = head;
        while (node != nullptr) {
            cout << " " << node->data;
            node = node->next;
        }
        cout << endl;
    }

    void DeleteFromHead() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    void DeleteFromTail() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            tail = current;
        }
    }

    int getMiddle() const {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    void InsertAfter(int val, int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                Node* newnode = new Node(val);
                newnode->next = current->next;
                current->next = newnode;
                if (newnode->next == nullptr) {
                    tail = newnode;
                }
                return;
            }
            current = current->next;
        }
        cout << "Key not found: " << key << endl;
    }

    void InsertBefore(int val, int key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == key) {
            InsertAtHead(val);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == key) {
                Node* newnode = new Node(val);
                newnode->next = current->next;
                current->next = newnode;
                return;
            }
            current = current->next;
        }
        cout << "Key not found: " << key << endl;
    }

    int getMax() const {
        if (IsEmpty()) {
            throw runtime_error("List is empty");
        }
        int max = head->data;
        Node* current = head;
        while (current != nullptr) {
            if (current->data > max) {
                max = current->data;
            }
            current = current->next;
        }
        return max;
    }

    int getMin() const {
        if (IsEmpty()) {
            throw runtime_error("List is empty");
        }
        int min = head->data;
        Node* current = head;
        while (current != nullptr) {
            if (current->data < min) {
                min = current->data;
            }
            current = current->next;
        }
        return min;
    }

    bool Swap(int lindex, int rindex) {
        if (lindex < 0 || rindex < 0 || lindex >= size() || rindex >= size()) {
            return false;
        }
        if (lindex == rindex) {
            return true;
        }
        Node* left = head;
        Node* right = head;
        for (int i = 0; i < lindex; i++) {
            left = left->next;
        }
        for (int i = 0; i < rindex; i++) {
            right = right->next;
        }
        int temp = left->data;
        left->data = right->data;
        right->data = temp;
        return true;
    }
};

int main() {
    LinkedList list;

    list.InsertAtHead(10);
    list.InsertAtHead(20);
    list.InsertAtHead(30);
    list.printForward();

    list.InsertAfter(7, 20);
    list.InsertBefore(25, 10);
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.printForward();

    cout << "Middle element: " << list.getMiddle() << endl;
    cout << "List size: " << list.size() << endl;
    cout << "Is list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    cout << "Max: " << list.getMax() << endl;
    cout << "Min: " << list.getMin() << endl;

    list.Swap(0, 2);
    list.printForward();

    list.DeleteFromHead();
    list.printForward();
    list.DeleteFromTail();
    list.printForward();

    return 0;
}
//q2
#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    T data;
    Node* next;

    
    Node() : data(0), next(nullptr) {}

    
    Node(T n) : data(n), next(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* temp;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    
    void InsertAtHead(T data1) {
        Node<T>* newnode = new Node<T>(data1);
        newnode->next = head;
        head = newnode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    
    void InsertAtTail(T ele) {
        Node<T>* newnode = new Node<T>(ele);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    
    void printForward() {
        Node<T>* node = head;
        while (node != nullptr) {
            cout << " " << node->data;
            node = node->next;
        }
        cout << endl;
    }

    
    void DeleteFromHead() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    
    void DeleteFromTail() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            tail = current;
        }
    }

    T getMiddle() const {
        Node<T>* slow = head;
        Node<T>* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
    int size() const {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    bool IsEmpty() const {
        return head == nullptr;
    }
    void InsertAfter(T val, T key) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                Node<T>* newnode = new Node<T>(val);
                newnode->next = current->next;
                current->next = newnode;
                if (newnode->next == nullptr) {
                    tail = newnode;
                }
                return;
            }
            current = current->next;
        }
        cout << "Key not found: " << key << endl;
    }
    void InsertBefore(T val, T key) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->data == key) {
            InsertAtHead(val);
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            if (current->next->data == key) {
                Node<T>* newnode = new Node<T>(val);
                newnode->next = current->next;
                current->next = newnode;
                return;
            }
            current = current->next;
        }
        cout << "Key not found: " << key << endl;
    }
};

int main() {
    LinkedList<int> list;

    list.InsertAtHead(10);
    list.InsertAtHead(20);
    list.InsertAtHead(30);
    list.printForward();

    list.InsertAfter(7, 20);  
    list.InsertBefore(25, 10); 
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.printForward();

    cout << "Middle element: " << list.getMiddle() << endl;
    cout << "List size: " << list.size() << endl;
    cout << "Is list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    list.DeleteFromHead();
    list.printForward();
    list.DeleteFromTail();
    list.printForward();
    LinkedList<string> strList;
    strList.InsertAtHead("apple");
    strList.InsertAtTail("banana");
    strList.InsertAtTail("cherry");
    strList.printForward();

    return 0;
}
