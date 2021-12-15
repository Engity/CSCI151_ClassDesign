#include "SectionA.h"
#include "SectionB.h"
#include "SectionC.h"
#include <string>
#include <iostream>

using namespace std;
int main(){
    cout << "-----Section A testing-----\n";
    URL s ("https://www.cplusplus.com/forum/general/137127/");
    printUrl(s);

    cout << "\n-----Section B testing-----\n";    
    cout <<"\n - Test right format\n\n";
    Image image("Right Format","PNG","11/11/2021", 5000, "Author", 45, 50, 8, "1/30", 3000, false);
    printImageInfo(image);
    
    cout << "\n - Test wrong format\n\n";
    Image wrongFormatImage("Wrong Format","SNG","31/12/2021", -5000, "Author", -45, -50, -8, "11/30", -3000, false);
    
    cout << "\n";
    printImageInfo(wrongFormatImage);

    cout << "\n-----Section C testing-----\n";
    //A bunch of items
    Item book("Book", 0, 1, 12);
    Item pencil("Colored Pencils", 1, 2, 15);
    Item paper("Coloring Paper", 2, 3, 12);
    Item markers("Markers", 3, 4, 50);
    Item crayons("Crayons", 4, 5, 3);
    Item staples("Staples", 5, 6, 7);

    //Adding items to shop
    Store shop;
    shop.addItem(book);
    shop.addItem(pencil);
    shop.addItem(paper);
    shop.addItem(markers);
    shop.addItem(staples);

    //Checking shop
    shop.printStoreInfo();
    cout << endl;

    //Make some orders
    //setting, which and how many items to order
    book.setQuantity(6);
    pencil.setQuantity(7);
    markers.setQuantity(4);

    Order order;
    order.addItem(book);
    order.addItem(pencil);
    order.addItem(markers);
    //Display current order
    order.displayOder();
    //Testing removing items from current order
    order.removeItem(0,2);

    //display cost;
    cout << "The total amount in cart is $"<< order.getTotalPrice() << endl;
    //Display current order
    cout << endl;
    order.displayOder();
    system("pause");
    return 0;
}