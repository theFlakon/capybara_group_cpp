#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>

class Document{
public:
    virtual void open() = 0;    // to redifinit in class-heir
    virtual void save() = 0;
    virtual std::string extractContent() = 0;
    virtual size_t getWordCount() = 0;
    virtual std::string getFormatName() = 0;
    virtual ~Document() {};
};  





#endif // DOCUMENT_HPP