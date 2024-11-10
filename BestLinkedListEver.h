#ifndef BESTLINKEDLISTEVER_H
#define BESTLINKEDLISTEVER_H


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
    void copylist(const LinkedList& acopier);
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& copie);
    LinkedList& operator=(const LinkedList& acopier);
    void push_front(const MyPair& pair);
    void push_back(const MyPair& pair);
    MyPair& front() const;
    Node* headNode(){return head;}
    int size() {return taille;}
    void printList();
    std::pair<Node*,bool> remove(MyPair& pair);
};


#endif //BESTLINKEDLISTEVER_H
