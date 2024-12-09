#include<iostream>
#include<string>

class Fan;

class LowState;
class HighState;
class OffState;

class FanState {
public:
	virtual void turnUp(Fan& fan) = 0;	// Tăng tốc 
	virtual void turnDown(Fan& fan) = 0; // Giảm tốc 
	virtual void showState() const = 0; // Trạng thái
	virtual ~FanState() = default;
};

class Fan {
private:
	FanState* currentState;
public:
	Fan(FanState* initialState) : currentState(initialState){}

	void setState(FanState* state){
		currentState = state;
	}

	void turnUp() {
		currentState->turnUp(*this);
	}

	void turnDown() {
		currentState->turnDown(*this);
	}

	void showState() const {
		currentState->showState();
	}
};

class OffState : public FanState {
	void turnUp(Fan& fan) override {
		std::cout << "Turn up the Fan and make it cooler! " << std::endl;
		fan.setState(new LowState());
	}
	void turnDown(Fan& fan) override {
		std::cout << "Too cold now, please turn down the fan!" << std::endl;
	}
	void showState() const override{
		std::cout << "Fanstate: bruh burh ......" << std::endl;
	}
};

class LowState : public FanState {
public:
	void turnUp(Fan& fan) override {
		std::cout << "Turn speed higher yia" << std::endl;
		fan.setState(new HighState());
	}
	void turnDown(Fan& fan) override {
		std::cout << "Turn down the fan" << std::endl;
		fan.setState(new OffState());
	}
	void showState() const override {
		std::cout << "Fan is on Low speed." << std::endl;
	}
};

class HighState: public FanState{
public:
	void turnUp(Fan& fan) override {
		std::cout << "Fan is already on  High speed." << std::endl;
	}

	void turnDown(Fan& fan) override {
		std::cout << "Fan is now on Low speed." << std::endl;
	}
	void showState() const override {
		std::cout << "Fan is on High speed" << std::endl;
	}
};

int main() {
	Fan fan(new OffState());
	fan.showState();

	fan.turnUp();
	fan.showState();

	fan.turnDown();
	fan.showState();

	fan.turnDown();
	fan.showState();

	return 0;
}