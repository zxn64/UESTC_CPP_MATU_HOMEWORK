#include <iostream>

using namespace std;

template<typename T>
class node {
private:
    T value_;
    node<T> *prev_;
    node<T> *next_;
public:
    node() {
        value_ = T();
        prev_ = NULL;
        next_ = NULL;
    }

    void set_value(T value) {
        value_ = value;
    }

    T get_value() {
        return value_;
    }

    node<T> *get_prev() {
        return prev_;
    }

    node<T> *get_next() {
        return next_;
    }

    void append(node<T> *next) {
        next_ = next;
        next->prev_ = this;
    }
};

void test1() {
    node<int> *ptr;
    node<int> node1, node2, node3;
    node1.set_value(1);
    node2.set_value(2);
    node3.set_value(3);
    node1.append(&node2);
    node2.append(&node3);
    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL) break;
    }
}

void test2() {
    node<float> *ptr;
    node<float> node1, node2, node3;
    node1.set_value(1.1);
    node2.set_value(2.2);
    node3.set_value(3.3);
    node1.append(&node2);
    node2.append(&node3);
    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL) break;
    }
}

void test3() {
    node<char> *ptr;
    node<char> node1, node2, node3;
    node1.set_value('a');
    node2.set_value('b');
    node3.set_value('c');
    node1.append(&node2);
    node2.append(&node3);
    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL) break;
    }
}

int main() {
    int type;
    cin >> type;
    switch (type) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
    }
    return 0;
}
