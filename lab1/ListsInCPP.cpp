#include <iostream>
#include <string>

struct Node {
    std::string name;
    int age;
    double height;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    
    void addToFront(const std::string& name, int age, double height);
    void addToEnd(const std::string& name, int age, double height);
    void addAfter(const std::string& target, const std::string& name, int age, double height);
    void addBefore(const std::string& target, const std::string& name, int age, double height);
    void removeByName(const std::string& name);
    void display() const;

private:
    Node* head;
};

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::addToFront(const std::string& name, int age, double height) {
    Node* newNode = new Node{name, age, height, head};
    head = newNode;
}

void LinkedList::addToEnd(const std::string& name, int age, double height) {
    Node* newNode = new Node{name, age, height, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::addAfter(const std::string& target, const std::string& name, int age, double height) {
    Node* temp = head;
    while (temp && temp->name != target) {
        temp = temp->next;
    }
    if (temp) {
        Node* newNode = new Node{name, age, height, temp->next};
        temp->next = newNode;
    }
}

void LinkedList::addBefore(const std::string& target, const std::string& name, int age, double height) {
    if (!head) return;
    if (head->name == target) {
        addToFront(name, age, height);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->name != target) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* newNode = new Node{name, age, height, temp->next};
        temp->next = newNode;
    }
}

void LinkedList::removeByName(const std::string& name) {
    if (!head) return;
    if (head->name == name) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->name != name) {
        temp = temp->next;
    }
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void LinkedList::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << "Name: " << temp->name << ", Age: " << temp->age << ", Height: " << temp->height << '\n';
        temp = temp->next;
    }
}

int main() {
    LinkedList list;
    
    list.addToEnd("Alice", 25, 5.6);
    list.addToFront("Bob", 30, 5.9);
    list.addAfter("Alice", "Charlie", 28, 5.8);
    list.addBefore("Alice", "David", 35, 5.7);
    
    std::cout << "List after additions:\n";
    list.display();
    
    list.removeByName("Charlie");
    std::cout << "\nList after removing Charlie:\n";
    list.display();
    
    return 0;
}
