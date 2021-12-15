#include "SectionC.h"

//---Section C Item -----
Item::Item(std::string name, long id, double price, int quantity){
    _id = id;
    setName(name);
    setPrice(price);
    setQuantity(quantity);
}

std::string Item::getName() const{
    return _name;
}
long Item::getId() const{
    return _id;
}
double Item::getPrice() const{
    return _price;
}
int Item::getQuantity() const{
    return _quantity;
}

void Item::setQuantity(int number){
    if (number >= 0){
        _quantity = number;
    }
    else {
        std::cout << "Quantity cannot be below zero\n";
    }
    
}

void Item::setName(std::string name){
    _name = name;
}

void Item::setPrice(double amount){
    if (amount >= 0){
         _price = amount;
    }
    else {
        std::cout << "Price cannot be below zero\n";
    }
}

void Item::setId(long id){
    if (id >= 0){
        _id = id;
    }
    else {
        std::cout << "ID cannot be below zero\n";
    }
}

void printItemInfo(const Item &item){
    std::cout << "Item: " << item.getName()
        << "\n\tID: " << item.getId()
        << "\n\tPrice: " << item.getPrice()
        << "\n\tQuantity: " << item.getQuantity();
}

//-----Section C Store-----

Store::Store(){}

//Adding item to the shop
void Store::addItem(Item item){
    _items.push_back(item);
}

int Store::getTotal(){
    return _items.size();
}

void Store::removeItem(long id, int quantity){
    for (Item item : _items){
        if (item.getId() == id){
            int new_amount = item.getQuantity() - quantity;

            if (new_amount < 0){
                std::cout << "Cannot remove more than the quantity in the store\n";
                break;
            }

            item.setQuantity (new_amount);
            break;
        }
    }
}


void Store::printStoreInfo(){
    std::cout << "The shop's current inventory is:\n";
    for (Item item : _items){
        printItemInfo(item);
        std::cout << "\n";
    }
}

//-----Section C Order-----

 Order::Order(){
    _cost = 0;
 }
void Order::addItem(Item item){
    _cart.push_back(item);
    _cost += item.getPrice();
}
void Order::removeItem(long id, int quantity){//Remove certain amounts from the cart, based on id
    for (Item item : _cart){
        if (item.getId() == id){
            int new_amount = item.getQuantity() - quantity;

            if (new_amount < 0){
                std::cout << "Cannot remove more than the quantity in the cart\n";
                break;
            }
            double new_balence = _cost - quantity * item.getPrice();
            
            _cost = new_balence;
            item.setQuantity (new_amount);
            break;
        }
    }
}
double Order::getTotalPrice(){
    return _cost;
}

void Order::displayOder(){
    std::cout << "The current order has:\n";
    for (Item item : _cart){
        printItemInfo(item);
        std::cout << "\n";
    }
}


