#include <iostream>
using namespace std;

class MyList {
private:
    int *arr;
    unsigned int capacity;
    unsigned int length;

    void resize(unsigned int new_capacity);

public:
    MyList();
    MyList(unsigned int cap);
    MyList(const MyList &other);
    ~MyList();

    unsigned int getLength() const;
    void push(int value);
    void pop();
    int get(unsigned int index) const;

    MyList &operator=(const MyList &other);
    MyList operator+(const MyList &other) const;
    bool operator==(const MyList &other) const;
};

MyList::MyList() : capacity(16), length(0) {
    arr = new int[capacity];
}

MyList::MyList(unsigned int cap) : capacity(cap), length(0) {
    arr = new int[capacity];
}

MyList::MyList(const MyList &list) : capacity(list.capacity), length(list.length) {
    arr = new int[capacity];
    for (unsigned int i = 0; i < length; ++i) {
        arr[i] = list.arr[i];
    }
}

MyList::~MyList() {
    delete[] arr;
}

unsigned int MyList::getLength() const {
    return length;
}

void MyList::push(int value) {
    if (length == capacity) {
        resize(capacity * 2);
    }
    arr[length++] = value;
}

void MyList::pop() {
    if (length > 0) {
        --length;
    } else {
        cout << "Error: List is empty!" << endl;
    }
}

int MyList::get(unsigned int index) const {
    if (index < length) {
        return arr[index];
    } else {
        cout << "Error: Index out of bounds!" << endl;
        return -1;
    }
}

MyList &MyList::operator=(const MyList &list) {
    if (this != &list) {
        delete[] arr;
        capacity = list.capacity;
        length = list.length;
        arr = new int[capacity];
        for (unsigned int i = 0; i < length; ++i) {
            arr[i] = list.arr[i];
        }
    }
    return *this;
}

MyList MyList::operator+(const MyList &list) const {
    MyList result(length + list.length);
    for (unsigned int i = 0; i < length; ++i) {
        result.push(arr[i]);
    }
    for (unsigned int i = 0; i < list.length; ++i) {
        result.push(list.arr[i]);
    }
    return result;
}

bool MyList::operator==(const MyList &list) const {
    if (length != list.length) {
        return false;
    }
    for (unsigned int i = 0; i < length; ++i) {
        if (arr[i] != list.arr[i]) {
            return false;
        }
    }
    return true;
}

void MyList::resize(unsigned int new_capacity) {
    int *new_arr = new int[new_capacity];
    for (unsigned int i = 0; i < length; ++i) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    capacity = new_capacity;
}


int main() {
    MyList list1;
    list1.push(10);
    list1.push(20);
    list1.push(30);

    MyList list2;
    list2.push(40);
    list2.push(50);

    cout << "List 1 Length: " << list1.getLength() << endl;
    cout << "List 2 Length: " << list2.getLength() << endl;

    MyList list3 = list1 + list2;
    cout << "List 3 Length (after concatenation): " << list3.getLength() << endl;

    cout << "List 3 content:" << endl;
    for (unsigned int i = 0; i < list3.getLength(); ++i) {
        cout << list3.get(i) << endl;
    }

    if (list1 == list2) {
        cout << "List 1 and List 2 are equal" << endl;
    } else {
        cout << "List 1 and List 2 are not equal" << endl;
    }

    list1.pop();
    cout << "List 1 Length after pop: " << list1.getLength() << endl;

    return 0;
}