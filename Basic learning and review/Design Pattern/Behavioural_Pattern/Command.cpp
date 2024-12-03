#include<iostream>
#include<string>

//Step 1: Define the Command interface and its implementation
class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class OpenFileCommand : public Command {
public:
	OpenFileCommand() {}
	void execute() override {
	}
	void undo() override {
	}
};

class SaveFileCommand : public Command {
public:
	SaveFileCommand(){}
	void execute() override {}
	void undo() override{}
};

class CopyTextCommand : public Command {
	CopyTextCommand(){}
	void execute() override{}
	void undo() override{}
};

class PasteTextCommand : public Command {
	PasteTextCommand(){}
	void execute(){}
	void undo(){}
};

// Step 2: Implement the Invoker class and the Client code 
class Invoker {
private:
	std::vector<Command*> commands;
public:
	void executeCommand(Command* command){
		command -> execute();
		commands.push_back(command);
	}

	void unodLastCommand(){
		if(!commands.empty()){
			Command* lastCommand = commands.back();
			lastCommand->undo();
			commands.pop_back();
		}
	}
};

int main(){
	Invoker invoker;

	//Create commands
	Command* openFileCommand = new OpenFileCommand(/*..*/);
	Command* saveFileCommand = new SaveFileCommand(/*..*/);
	Command* copyFileCommand = new CopyFileCommand(/*..*/);
	Command* pasteFileCommand = new PasteFileCommand(/*..*/);

	//Execute commands
	invoker.executeCommand(openFileCommand);
	invoker.executeCommand(saveFileCommand);
	invoker.executeCommand(copyFileCommand);
	invoker.executeCommand(pasteFileCommand);

	invoker.unodLastCommand();

	//Clean up
	delete openFileCommand;
	delete saveFileCommand;
	delete copyFileCommand;
	delete pasteFileCommand;

	return 0;
}