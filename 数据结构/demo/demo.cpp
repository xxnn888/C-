//
// Created by 15218 on 2022/9/7.
//
#include <iostream>
#include <string>
#include <utility>

using namespace std;
#define MaxSize 20
typedef int EleType;
typedef struct {
    EleType data[MaxSize];
    int length;
} Set;

void cset(Set &s, const int a[], int n) {
    for (int i = 0; i < n; ++i) {
        s.data[i] = a[i];
        s.length = n;
    }
}

void dispset(Set s) {
    for (int i = 0; i < s.length; ++i) {
        cout << s.data[i];
        cout << endl;
    }
}

bool inset(Set s, int c) {
    for (int i = 0; i < s.length; ++i) {
        if (s.data[i] == c) {
            return true;
        }
    }
    return false;
}


void add(Set s1, Set s2, Set &s3) {
    for (int j = 0; j < s1.length; ++j) {
        s3.data[j] = s1.data[j];
        s3.length = s1.length;
    }
    for (int j = 0; j < s2.length; ++j) {
        if (!inset(s1, s2.data[j])) {
            s3.data[s3.length] = s2.data[j];
            s3.length++;
        }
    }
}

void sub(Set s1, Set s2, Set &s3) {
    s3.length = 0;
    for (int i = 0; i < s1.length; ++i) {
        if (!inset(s2, s1.data[i])) {
            s3.data[s3.length] = s1.data[i];
            s3.length++;
        }
    }
}

void intersection(Set s1, Set s2, Set &s3) {
    s3.length = 0;
    for (int i = 0; i < s1.length; ++i) {
        if (inset(s2, s1.data[i])) {
            s3.data[s3.length] = s1.data[i];
            s3.length++;
        }
    }
}

class person {
public:
    void initperson(string s, int ag, string add) {
        this->address = std::move(add);
        this->age = ag;
        this->name = std::move(s);
    }

    void showperson() {
        cout << this->name << this->age << this->address;
    }

private:
    string name;
    int age{};
    string address;
};

int main() {
    int a[] = {1, 4, 2, 6, 8};
    int b[] = {2, 5, 3, 6};
    Set s1, s2, s3;
    cset(s1, a, 5);
    cset(s2, b, 4);
    cout << "集合1   :" << endl;
    dispset(s1);
    cout << "集合2   :" << endl;
    dispset(s2);

//    person p[10]; //比如我创建的类为person 直接定义10个对象
//    for (int i = 0; i < 10; ++i) {
//        string name;
//        int age;
//        string address;
//        cin >> name >> age >> address;
//        p[i].initperson(name, age, address);
//        p[i].showperson();
//    }

    return 0;

}

