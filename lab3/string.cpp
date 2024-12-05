#include <iostream>
using namespace std;

int ahmed_strlen(const char str[]);
void ahmed_strcpy(char dest[], const char source[]);

class MyString {
private:
    char* str;
    int length = 0;
    

public:
    friend ostream& operator << (ostream& out, const MyString& st);
    friend istream& operator >> (istream& in, MyString& st);

    // Constructor
    MyString(char* input_string) {
        this->length = ahmed_strlen(input_string);
        this->str = new char[this->length + 1];  
        ahmed_strcpy(this->str, input_string);
    }

    char* getString() {
        return str;
    }

    int getLength() {
        return this->length;
    }

    bool operator== ( const MyString& st2) {
    if (this->length != st2.length) {
        return false;
    }
    for (int i = 0; i < this->length; i++) {
        if (this->str[i] != st2.str[i]) {
            return false;
        }
    }
    return true;
    }

    bool operator> ( const MyString& st2) {
        if (this->length > st2.length) {
        return true;
       }
       return false;
    }

    bool operator< ( const MyString& st2) {
        if (this->length < st2.length) {
        return true;
       }
       return false;
    }

    MyString operator+ (const MyString& st2) {
        int newLength = this->length + st2.length;
        char* newStr = new char[newLength + 1];
        for (int i = 0; i < this->length; i++) {
            newStr[i] = this->str[i];
        }
        for (int i = 0; i < st2.length; i++) {
            newStr[this->length + i] = st2.str[i];
        }
        newStr[newLength] = '\0';
        MyString newString = newStr;
        return newString;
    }

 
};

int ahmed_strlen(const char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void ahmed_strcpy(char dest[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {  
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}



ostream& operator << (ostream& out, const MyString& st) {
    for (int i = 0; i < st.length; i++) {
        out << st.str[i];
    }
    return out;
}

istream& operator >> (istream& in, MyString& st) {
    char temp[100];
    in >> temp;
    delete[] st.str;
    int length = 0;
    while (temp[length] != '\0') {
        length++;
    }
    st.str = new char[length + 1];
    st.length = length;
    for (int i = 0; i < length; i++) {
        st.str[i] = temp[i];
    }
    st.str[length] = '\0';
    return in;
}

int main() {
    MyString name = "ahm";
    MyString anotherName = "Ahmed";
    cout << name << endl;  
    if (name > anotherName) {
        cout << "name is longer than anotherName" << endl;
    } else {
        cout << "name is shorter" << endl;
    }

    cout << name + anotherName << endl;
    return 0;
}