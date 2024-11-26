#include<iostream>
#include<string>

// define interface for the resource and its proxy
class Resource {
public:
	virtual void performManagement() = 0;
};

class ResourceProxy : public Resource{
public:
	void performManagement() override{
		if(resource == nullptr){
			resource = new Resource();
		}

		resource -> performManagement();
	}
private:
	Resource* resource;
};

int main() {
	ResourceProxy proxy;
	proxy.performManagement();

	return 0;
}
