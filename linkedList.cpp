#include <iostream>
#include <sstream>
#include <stdlib.h>

struct MyPair {
    int a, b;
    auto operator<=>(const MyPair&) const = default;
};

inline std::ostream& operator<<(std::ostream& os, const MyPair& p){
    os << "("<< p.a << "," << p.b <<")";
    return os;
}

struct LinkedList {
    MyPair paireuh;
    LinkedList* next;
};

LinkedList* insert(LinkedList* list, MyPair& pair) {return new LinkedList{pair, list};}

void printList(LinkedList* list) {
    std::cout<<"[";
    while(list!=nullptr){
        std::cout<<list->paireuh;
        if (list->next!=nullptr){std::cout<<", ";}
        list=list->next;
    }
    std::cout<<"]";
}

LinkedList* insertBack(LinkedList* list, MyPair& pair) {
    LinkedList* node=new LinkedList{pair, nullptr};
    if(list==nullptr) {
        return node;
    }
    LinkedList* current= list;
    while(current->next!=nullptr) {
        current=current->next;
    }
    current->next=node;
    return list;
}

int main(){
    LinkedList* list=nullptr;
    MyPair p1={0,1};
    MyPair p2={42,666};
    MyPair p3={1,1};
    list=insert(list,p1);
    list=insert(list,p2);
    list=insert(list,p3);
    printList(list);
    insertBack(list,p1);
    printList(list);
    return 0;
}

const LinkedList* remove (LinkedList* list,MyPair& pair) {
    if(list==nullptr) {
        return nullptr;
    }
    if(list->paireuh==pair) {
        LinkedList* yaplus=list->next;
        delete list;
        return yaplus;
    }
    LinkedList* current=list;
    while(current->next!=nullptr) {
        if(current->next->paireuh==pair) {
            LinkedList* disparu=current->next;
            current->next=current->next->next;
            delete disparu;
            return list;
        }
        current=current->next;
    }
    return list;
}
