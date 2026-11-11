#include "../include/Item.h"
#include "../include/Visitor.h"

Item::Item()
    : name("Unknown"), description("") {}

Item::Item(const string & n, const string & d)
    : name(n), description(d) {}

void Item::accept(Visitor & v) {
    v.visit(*this);
}
