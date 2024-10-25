#include<iostream>
#include<string>
#include<unordered_map>

class Document {
public:
	virtual Document* clone() const = 0;
	virtual void print() const = 0;
};

class Resume : public Document{
public:
	Document* clone() const override{
		return new Resume(*this);
	}
	void print() const override {
		std::cout << "Printing a resume Document" << std::endl;
	}
};

class Report : public Document{
public:
	Document* clone() const override {
		return new Report(*this);
	}
	void print() const override {
		std::cout << "Printing a report ...." << std::endl;
	}
};

class DocumentPrototypeFactory{
private:
	std::unordered_map<std::string, Document*> prototypes;
public:
	DocumentPrototypeFactory(){
		prototypes["resume"] = new Resume();
		prototypes["report"] = new Report();
	}

	Document* createDocument(const std::string &type) const {
		auto it = prototypes.find(type);
		if(it != prototypes.end())
			return it -> second -> clone();
		return nullptr;
	}
};

int main(){
	DocumentPrototypeFactory factory;
	Document* resume = factory.createDocument("resume");
	if(resume) {
		resume -> print();
		delete resume;
	}

	Document* report = factory.createDocument("report");
	if(report) {
		report -> print();
		delete report;
	}

	return 0;
}