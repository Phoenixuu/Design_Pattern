#include<iostream>
#include<string>

// Step 1: Define the abstract hanler class and its concrete implementations
class SupportHandler {
protected:
	SupportHandler* nextHandler:

public:
	SupportHandler() : nextHandler(nullptr){}
	void setNextHandler(SupportHandler* handler) {
		nextHandler = handler;
	}

	virtual void handlerRequest(const std::string& request) = 0;
};

class TechnicalSupportHandler : public SupportHandler {
public:
	void handleRequest(const std::string& request) override {
		if(request == "technical") {
			//Handle technical support request
		} else if (nextHandler != nullptr) {
			nextHandler -> handleRequest(request);
		}
	}
};

class BillingHandler : public SupportHandler {
public:
	void handleRequest(const std::string& request) override {
		if(request == "billing"){
			//Handle billing inquiry
		} else if {
			nextHandler -> handleRequest(request);
		}
	}
}

class GeneralInquiryHandle : public SupportHandler {
public: void handleRequest(const std::string& request) override {
	void handleRequest(const std::string& request) override {
		if(request == "general"){
			//Handle general inquiry
		}
		else if {
			nextHandler -> handleRequest(request);
		}
	}
};

int main(){
	SupportHandler* technicalSupportHandler = new TechnicalSupportHandler();
	SupportHandler* billinghandler = new BillingHandler();
	SupportHandler* generalInquiryHandle = new GeneralInquiryHandle();
	
	technicalSupportHandler -> setNextHandler(billinghandler);
	billinghandler -> setNextHandler(generalInquiryHandle);

	technicalSupportHandler ->handleRequest("technical");
	technicalSupportHandler -> handleRequest("billing");
	technicalSupportHandler -> handleRequest("general");

	delete technicalSupportHandler;
	delete billinghandler;
	delete generalInquiryHandle;

	return 0;
}