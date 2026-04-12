#ifndef SPREADSHEET_DOCUMENT_HPP
#define SPREADSHEET_DOCUMENT_HPP
#include "document.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
class SpreadsheetDocument: public Document {
private:
    std::string _filename;
    std::string _content;
public:
    SpreadsheetDocument(const std::string& filename) : _filename(filename) {}
    
    void open() override;
    void save() override;

    std::string extractContent() override;
    size_t getWordCount() override;
    std::string getFormatName() override;

    ~SpreadsheetDocument() {};
   
};

#endif