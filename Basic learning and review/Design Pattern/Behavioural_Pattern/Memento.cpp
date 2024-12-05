#include <iostream>
#include <string>

class Memento {
    std::string text;
public:
    Memento() : text("") {} // Constructor mặc định
    Memento(const std::string& t) : text(t) {}

    std::string getText() const {
        return text;
    }
};

class TextEditor {
    std::string text;
public:
    void setText(const std::string& t) {
        text = t;
    }

    std::string getText() const {
        return text;
    }

    Memento createMemento() const {
        return Memento(text);
    }

    void restore(const Memento& memento) {
        text = memento.getText();
    }
};

class Caretaker {
    Memento memento;
public:
    Caretaker() : memento(Memento("")) {} // Khởi tạo mặc định

    void saveMemento(const TextEditor& textEditor) {
        memento = textEditor.createMemento();
    }

    void restoreText(TextEditor& textEditor) {
        textEditor.restore(memento);
    }
};

int main() {
    TextEditor textEditor;
    Caretaker caretaker;

    textEditor.setText("Hello ");
    std::cout << "Current Text: " << textEditor.getText() << std::endl;

    caretaker.saveMemento(textEditor);

    textEditor.setText("Hello, World! ");
    std::cout << "Current Text: " << textEditor.getText() << std::endl;

    caretaker.restoreText(textEditor);
    std::cout << "Restored Text: " << textEditor.getText() << std::endl;

    return 0;
}
