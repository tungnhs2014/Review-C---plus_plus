#include <iostream>
#include <string>

// Component interface (Text)
class Text {
public:
    virtual std::string render() const = 0; // Pure virtual function to render text
    virtual ~Text() {}
};

// ConcreteComponent (PlainText)
class PlainText : public Text {
private:
    std::string content;
public:
    PlainText(const std::string& text) : content(text) {}

    // Render the plain text
    std::string render() const override {
        return content;
    }
};

// Decorator class (base class for text decorators)
class TextDecorator : public Text {
protected:
    const Text& textComponent; // Composition: stores a reference to the wrapped object
public:
    TextDecorator(const Text& text) : textComponent(text) {}

    // Delegate the rendering to the wrapped component
    std::string render() const override {
        return textComponent.render();
    }
};

// ConcreteDecorator (BoldDecorator) adds bold effect
class BoldDecorator : public TextDecorator {
public:
    BoldDecorator(const Text& text) : TextDecorator(text) {}

    // Add bold tags around the text
    std::string render() const override {
        return "<b>" + TextDecorator::render() + "</b>";
    }
};

// ConcreteDecorator (ItalicDecorator) adds italic effect
class ItalicDecorator : public TextDecorator {
public:
    ItalicDecorator(const Text& text) : TextDecorator(text) {}

    // Add italic tags around the text
    std::string render() const override {
        return "<i>" + TextDecorator::render() + "</i>";
    }
};

// ConcreteDecorator (UnderlineDecorator) adds underline effect
class UnderlineDecorator : public TextDecorator {
public:
    UnderlineDecorator(const Text& text) : TextDecorator(text) {}

    // Add underline tags around the text
    std::string render() const override {
        return "<u>" + TextDecorator::render() + "</u>";
    }
};

int main() {
    PlainText text("Hello, World!"); // Base component (plain text)

    // Apply bold formatting
    BoldDecorator boldText(text);
    std::cout << "Bold: " << boldText.render() << std::endl;

    // Apply italic formatting on top of bold
    ItalicDecorator italicBoldText(boldText);
    std::cout << "Bold and Italic: " << italicBoldText.render() << std::endl;

    // Apply underline formatting on top of bold and italic
    UnderlineDecorator underlineItalicBoldText(italicBoldText);
    std::cout << "Bold, Italic, and Underline: " << underlineItalicBoldText.render() << std::endl;

    return 0;
}

/*
    Bold: <b>Hello, World!</b>
    Bold and Italic: <i><b>Hello, World!</b></i>
    Bold, Italic, and Underline: <u><i><b>Hello, World!</b></i></u>

*/