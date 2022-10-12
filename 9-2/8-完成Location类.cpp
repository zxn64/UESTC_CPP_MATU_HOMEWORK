#include "Location.h"
//别问我为啥内存泄漏，问就是sb码图非让我返回引用

Location &Location::operator+(Location &offset) {
    return *(new Location(x + offset.x, y + offset.y));
}

Location &Location::operator-(Location &offset) {
    return *(new Location(x - offset.x, y - offset.y));
}