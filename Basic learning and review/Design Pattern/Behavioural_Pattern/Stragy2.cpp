#include<iostream>
#include<string>
#include<memory>

class PaymentStrategy{
public:
	virtual void pay(int amount) const = 0;
	virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy {
public:
	void pay(int amount) const override{
		std::cout << "Paid $" << amount << " using Creadit Card. Done!!!" << std::endl;
	}
};

class PaypalPayment : public PaymentStrategy {
public:
	void pay(int amount) const override{
		std::cout << "You got to pay $" << amount << " by Paypal method. Please be sorgfältig" << std::endl;
	}
};

class CashPayment : public PaymentStrategy {
public:
	void pay(int amount) const override { 
		std::cout << "Du bezahlst $" << amount << " in bar!" << std::endl; 
	}
};

class CryptoPayment : public PaymentStrategy {
public:
	void pay(int amount) const override {
		std::cout << "Pad $" << amount << " using Bitcoin" << std::endl;
	}
};

class PaymentContext{
private:
	std::unique_ptr<PaymentStrategy> strategy;
public:
	void setStrategy(std::unique_ptr<PaymentStrategy> newStrategy) {
		strategy = std::move(newStrategy);
	}

	void executePayment(int amount) const {
		if(strategy) {
			strategy->pay(amount);
		} else {
			std::cout << "Payment method is not accepted!" << std::endl;
		}
	}
};

int main(){
	PaymentContext bezahlen;

	bezahlen.setStrategy(std::make_unique<CreditCardPayment>());
	bezahlen.executePayment(1000);

	bezahlen.setStrategy(std::make_unique<CashPayment>());
	bezahlen.executePayment(856);


	bezahlen.setStrategy(std::make_unique<CryptoPayment>());
	bezahlen.executePayment(75000);

	return 0;
}