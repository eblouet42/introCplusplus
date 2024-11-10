#include <iostream>
#include "BestLinkedListEver.h"


    void LinkedList::copylist(const LinkedList& acopier) {
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
    LinkedList::LinkedList() {head=nullptr,taille=0;}
    LinkedList::~LinkedList() {while (head!=nullptr){Node* NodeASuppr=head;head=head->next;delete NodeASuppr;}}
    LinkedList::LinkedList(const LinkedList& copie){head=nullptr;taille=0;copylist(copie);}

    LinkedList& LinkedList::operator=(const LinkedList& acopier) {this->~LinkedList();copylist(acopier);return *this;}

    void LinkedList::push_front(const MyPair& pair) {head=new Node(pair,head);taille++;}

    void LinkedList::push_back(const MyPair& pair) {
        Node* newNode=new Node(pair,nullptr);
        if (head==nullptr){head=newNode;}
        else{
            Node* current=head;
            while (current->next!=nullptr) {
                current=current->next;
            }
            current->next=newNode;
        }taille++;
    }

    MyPair& LinkedList::front() const {if (head==nullptr){throw std::runtime_error("Y'a que dalle dans la liste");}return head->paireuh;}

    void LinkedList::printList(){
        if (head==nullptr) {throw std::runtime_error("Y'a que dalle dans la liste");}
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