#ifndef PDF_DOCUMENT_HPP
#define PDF_DOCUMENT_HPP

#include "document.hpp"
#include <iostream>
#include <string>
#include <cctype>

class PDFDocument: public Document {
private:
    std::string _filename;
    std::string _content;
    
    size_t countWords(const std::string& text) {
        size_t count = 0;
        bool inWord = false;

        for (char c: text) {
            if (std::isalnum(c)) {
                if (!inWord) {
                    inWord = true;
                    count++;
                }
            } else {
                inWord = false;
            }
        }
        return count;
    }
    
public:
    PDFDocument(const std::string& filename) : _filename(filename) {}
    
    void open() override {
        _content = "Test content Test content Test content Test content Test content";
    }
    
    void save() override {
        std::string newFilename = _filename;
        
        size_t dotPos = newFilename.find_last_of('.');
        
        if (dotPos != std::string::npos) {
            newFilename.insert(dotPos, "_pdf"); // For PDFDocument we need to add _pdf
        } else {
            newFilename += "_pdf";
        }
        
        std::cout << "Save document as: " << newFilename << std::endl;
    }
    
    std::string extractContent() override {
        return _content;
    }
    
    size_t getWordCount() override {
        return countWords(_content);
    }
    
    std::string getFormatName() override {
        return "PDF";
    }
};

#endif