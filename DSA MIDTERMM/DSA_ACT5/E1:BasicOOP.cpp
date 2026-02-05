#include <iostream>
using namespace std;

class Student 
{
public:
    string name;
    int age;
    string birthyear;
    int year;


void display() {
cout << "Name: " << name << ", Age: " << age << ", Year: " << year << endl;
}
};
int main() {
    Student s1;
        s1.name = "My Name: Bryce Abordo";
        s1.age = 18;
        s1.birthyear = "My Birth Year: ";
        s1.year = 2007;
        s1.display();
    return 0;
}