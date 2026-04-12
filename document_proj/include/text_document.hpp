#ifndef TEXT_DOCUMENT_HPP
#define TEXT_DOCUMENT_HPP

#include "document.hpp"
#include <string>
#include <cstddef>
#include <sstream>

class TextDocument : public Document{
private:
    std::string text;
    bool isOpen;

public:
    // constructor
    TextDocument(const std::string &text);

    void open() override;    
    void save() override;
    std::string extractContent() override;
    size_t getWordCount() override;
    std::string getFormatName() override;

    // destructor
    ~TextDocument();
};


#endif // TEXT_DOCUMENT_HPP