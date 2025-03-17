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

    void addToFront(std::string name, int age, double height);
    void addToEnd(std::string name, int age, double height);
    void addAfter(std::string target, std::string name, int age, double height);
    void addBefore(std::string target, std::string name, int age, double height);
    void removeByName(std::string name);
    void display();

private:
    Node* head;
};

LinkedList::~LinkedList() {
    for (Node* temp; head; head = temp) {
        temp = head->next;
        delete head;
    }
}

void LinkedList::addToFront(std::string name, int age, double height) {
    head = new Node{name, age, height, head};
}

void LinkedList::addToEnd(std::string name, int age, double height) {
    Node** temp = &head;
    while (*temp) temp = &((*temp)->next);
    *temp = new Node{name, age, height, nullptr};
}

void LinkedList::addAfter(std::string target, std::string name, int age, double height) {
    for (Node* temp = head; temp; temp = temp->next) {
        if (temp->name == target) {
            temp->next = new Node{name, age, height, temp->next};
            return;
        }
    }
}

void LinkedList::addBefore(std::string target, std::string name, int age, double height) {
    Node** temp = &head;
    while (*temp && (*temp)->name != target) temp = &((*temp)->next);
    *temp = new Node{name, age, height, *temp};
}

void LinkedList::removeByName(std::string name) {
    Node** temp = &head;
    while (*temp && (*temp)->name != name) temp = &((*temp)->next);
    if (*temp) {
        Node* toDelete = *temp;
        *temp = (*temp)->next;
        delete toDelete;
    }
}

void LinkedList::display() {
    for (Node* temp = head; temp; temp = temp->next)
        std::cout << "Name: " << temp->name << ", Age: " << temp->age << ", Height: " << temp->height << '\n';
}

int main() {
    LinkedList list;

    list.addToEnd("Alice", 25, 180);
    list.addToFront("Bob", 30, 167);
    list.addAfter("Alice", "Charlie", 28, 198);
    list.addBefore("Alice", "David", 35, 170);

    std::cout << "List after additions:\n";
    list.display();

    list.removeByName("Charlie");
    std::cout << "\nList after removing Charlie:\n";
    list.display();

    return 0;
}
