#include "polymorphisme.h"

template <typename Container>
void printContainer(const Container& c) {
    std::cout<<"Elements du vector: ";
    for (auto iterator=c.begin(); iterator!=c.end();++iterator){std::cout<<*iterator<<" ";}
    std::cout << std::endl;
}

template <typename Key, typename Value>
void printMap(const std::map<Key,Value>& m) {
    std::cout << "Element de la map:\n";
    for (auto truc=m.begin();truc!=m.end(); ++truc){std::cout << truc->first << ": " << truc->second << std::endl;}
}

template <typename Container>
int Count_n(const Container& c) {
    return std::count(c.begin(), c.end(), 0);
}

template <typename Container>
int Count_odd(const Container& c) {
    return std::count_if(v.begin(), v.end(), [](int i){return i%2==1;});
}

template <typename Container, class InputIt>
InputIt trouver_n()

