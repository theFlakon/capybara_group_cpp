#include "pdf_document.hpp"
#include <cctype>

PDFDocument::PDFDocument(const std::string &path): path(path), isOpen(false) {}

void PDFDocument::open() {
    text = "Test content Test content Test content Test content";
    isOpen = true;
}

void PDFDocument::save() {
    std::string newFilename = path;
    
    size_t dotPos = newFilename.find_last_of('.');
    if (dotPos != std::string::npos) {
        newFilename.insert(dotPos, "_pdf");
    } else {
        newFilename += "_pdf";
    }
    
    std::cout << "Save PDF as: " << newFilename << std::endl;
}

std::string PDFDocument::extractContent() {
    if (isOpen) {
        return text;
    }

    return "";
}

size_t PDFDocument::getWordCount() {
    if (!isOpen) return 0;
    
    size_t count = 0;
    bool inWord = false;
    for (char c: text) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
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

std::string PDFDocument::getFormatName() {
    return "PDF";
}

PDFDocument::~PDFDocument() {

}