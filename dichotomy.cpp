
#include <bits/ios_base.h>
#include <bits/ranges_base.h>

struct intpair{
    int a;
    int b;
    auto operator<=>(const intpair &p) const=default;
};

struct dichoindex {
    intpair* begin;
    intpair* end;
    };

intpair* dichotomy(dichoindex range, intpair element) {
    intpair* middle=range.begin+(range.end-range.begin)/2;
    if ( *middle==element){return middle;}
    if (range.end==range.begin){return nullptr;}
    dichoindex new_range;
    if (*middle>element) {
        new_range={range.begin,middle};
    } else{ new_range={middle+1,range.end};
    }return dichotomy(new_range,element);
}

int main{
}