#include "text_document.hpp"
                                            // this->text = text, this->isOpen = false
TextDocument::TextDocument(const std::string &text) : text(text), isOpen(false){}  

void TextDocument::open(){
    isOpen = true;
}

void TextDocument::save(){
    if (!isOpen) return;    // if doc is closed -> nothing to do, if not -> can save
}

std::string TextDocument::extractContent(){
    if (!isOpen) return "";
    return text;
}

size_t TextDocument::getWordCount(){
    size_t cnt = 0;
    std::stringstream ss(text);
    std::string word;

    while (std::getline(ss, word, ' '))
    {   
        if (!word.empty()) cnt++;
    }

    return cnt;
}

std::string TextDocument::getFormatName(){
    return "TXT";
}

TextDocument::~TextDocument(){}




