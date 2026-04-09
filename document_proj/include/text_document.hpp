#ifndef TEXT_DOCUMENT_HPP
#define TEXT_DOCUMENT_HPP

#include "document.hpp"
#include <string>
#include <cstddef>

class TextDocument : public Document{
private:
    std::string path;
    std::string text;
    bool isOpen;

public:
    // comstructor
    TextDocument(const std::string &path);

    void open() override;    
    void save() override;
    std::string extractContent() override;
    size_t getWordCount() override;
    std::string getFormatName() override;
    ~TextDocument();
};


#endif // TEXT_DOCUMENT_HPP