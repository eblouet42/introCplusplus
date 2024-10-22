#include <iostream>

struct MyPair {
    int a, b;
    auto operator<=>(const MyPair&) const = default;
};

inline std::ostream& operator<<(std::ostream& os,const MyPair& p) {
    os<<"("<<p.a<<","<<p.b<<")";
    return os;
}

struct Node {
    MyPair paireuh;
    Node* next;
};

class LinkedList {
    private:

    Node* head;
    int taille;

    void copylist(LinkedList& acopier) {
        if (acopier.head==nullptr) {
            head=nullptr;
        } else {
            head=new Node(acopier.head->paireuh);
            Node* current=head;
            Node* otherCurrent=acopier.head->next;
            while (otherCurrent!=nullptr) {
                current->next=new Node(otherCurrent->paireuh);
                current=current->next;
                otherCurrent=otherCurrent->next;
            }
        }
        taille=acopier.taille;
    }

public:

    LinkedList() {
        head=nullptr;
        taille=0;
    }

    ~LinkedList() {
        while (head!=nullptr){
            Node* NodeASuppr=head;
            head=head->next;
            delete NodeASuppr;
        }
    }

    LinkedList(LinkedList& copie){
        head=nullptr;
        taille=0;
        copylist(copie);
    }

    LinkedList& operator=(LinkedList& other) {
        if (this != &other) {
            this->~LinkedList();
            copylist(other);
        }
        return *this;
    }

    void push_front(MyPair& pair) {
        Node* newNode=new Node(pair,head);
        head=newNode;
        taille++;
    }

    void push_back(MyPair& pair) {
        Node* newNode=new Node(pair,nullptr);
        if (head==nullptr){
            head=newNode;
        }else{
            Node* current=head;
            while (current->next!=nullptr) {
                current=current->next;
            }
            current->next=newNode;
        }
        taille++;
    }

    MyPair& front() const {
        if (head==nullptr){
            throw std::runtime_error("Y'a que dalle dans la liste");
        }
        return head->paireuh;
    }

    Node* headNode(){return head;}
    int size() {return taille;}

    void printList(){

        if (head==nullptr) {
            throw std::runtime_error("Y'a que dalle dans la liste");
        }
        std::cout<<"[ ";
        Node* current=head;
        while (current!=nullptr) {
            std::cout<<current->paireuh;
            if (current->next!=nullptr) {
                std::cout<<" , ";
            }
            current=current->next;
        }
        std::cout<<" ]\n";
    }
};

int main() {
    LinkedList* list = new LinkedList();
    MyPair p1 = {0, 1};
    MyPair p2 = {42, 666};
    MyPair p3 = {1, 1};
    MyPair p4 = {2, 2};
    list->push_front(p1);
    list->push_front(p1);
    list->push_front(p2);
    list->push_front(p3);
    list->printList();
    list->push_back(p1);
    list->push_back(p4);
    list->printList();
    std::cout<<list->front()<<std::endl;
    return 0;
}