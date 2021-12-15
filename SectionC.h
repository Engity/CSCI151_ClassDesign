#include <string>
#include <iostream>
#include <vector>

class Item{
	public:
	    Item(std::string name, long id, double price, int quantity);
	
	    std::string getName() const;
	    long getId() const;
	    double getPrice() const;
	    int getQuantity() const;
	    
        void setQuantity(int number);
        void setName(std::string name);
        void setPrice(double amount);
        void setId(long id);
       
	
	private:
        //Default values
        long _id = 0;
        double _price = 0;
        int _quantity = 0;

        std::string _name;
};

void printItemInfo(const Item&);

class Store{
	public:
	        Store();
                int getTotal() const;
                void printStoreInfo();
                void addItem(Item);
                void removeItem(long id, int quantity);//Remove certain amounts from the shop, based on id
	private:
                std::vector <Item> _items;
};

class Order{
	public:
                Order();
                void addItem(Item item);
                void removeItem(long id, int quantity);//Remove certain amounts from the cart, based on id
                double getTotalPrice() const;
                void displayOder();
	private:
                double _cost;
                std::vector <Item> _cart;
};
