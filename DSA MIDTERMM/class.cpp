#include <iostream>
using namespace std;

// Class definition
class Car
{
  public:
    string brand;
    string model;
    int price;
    int year;

    Car(string b, string m, int p, int y)
    {
        brand = b;
        model = m;
        price = p;
        year = y;
    }

    void displayInfo(){
        cout << "Brand: " << brand << "Model: " << model << "Price: " << price << " Year: " << year << endl;
    }

    int getPrice(int qty){
        return price * qty;
    }
};

int main()
{
    Car toyota("Toyota ", "Corolla ", 24000 , 2010);
    Car honda("Honda ", "Civic ", 32000 , 2019);
    
    toyota.displayInfo();
    honda.displayInfo();

    cout << "Total Price for 3 Toyota cars: " << toyota.getPrice(3) << endl;
    cout << "Total Price for 2 Honda cars: " << honda.getPrice(2) << endl;
    return 0;
}