#include<vector>
#include<iostream>

class Product{
	public:
		virtual double getPrice() const = 0;
};

class SingleProduct : public Product{
public:
	SingleProduct(double price) : price(price){}

	double getPrice() const override {
		return price;
	}

private:
	double price;
};

class CompositeProduct : public Product {
public: 
	void addProduct(Product* product) {
		products.push_back(product);
	}
	void removeProduct(product* product) {

	}

	double getPrice const override{
		double totalPrice = 0.0;

		for (const auto& product : products){
			totalPrice += product -> getPrice();
		}
		return totalPrice;
	}
private:
	std::vector<Product*> products
};

int main(){
	// Create single product
	Product* Iphone = new SingleProduct(1000.0);
	Product* AppleWatch = new SingleProduct(500.0);
	Product* Macbook = new SingleProduct(1500);

	// Caculate the total price
	CompositeProduct* Buyer = new CompositeProduct();
	Buyer->addProduct(Iphone);
	Buyer->addProduct(Macbook);
	Buyer->addProduct(AppleWatch);

	// Caculate the total price
	double totalPrice = Buyer -> getPrice();
	std::cout << "totalPrice: $" << totalPrice << std::endl;

	//Clean up
	delete Iphone;
	delete AppleWatch;
	delete Macbook;

	return 0;
}