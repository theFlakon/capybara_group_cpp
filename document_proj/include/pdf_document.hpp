#ifndef PDF_DOCUMENT_HPP
#define PDF_DOCUMENT_HPP

#include "document.hpp"
#include <string>
#include <cstddef>
#include <iostream>

class PDFDocument: public Document {
private:
    std::string path;
    std::string text;
    bool isOpen;

public:
    PDFDocument(const std::string &path);

    void open() override;    
    void save() override;
    std::string extractContent() override;
    size_t getWordCount() override;
    std::string getFormatName() override;
    ~PDFDocument();
};

#endif