#include "spreadsheet_document.hpp"

void SpreadsheetDocument::open() {
    std::ifstream ss(_filename);
    if (!ss.is_open()) {
        std::cerr << "Failed to open file: " << _filename << std::endl;
        return; 
    }

    std::string line {};
    while (std::getline(ss, line)) {
        std::istringstream lineStream(line);
        std::string word {};
        while (std::getline(lineStream, word, ',')) {
            _content += word + " ";
        }
    }
}

void SpreadsheetDocument::save() {
    std::string newFilename = _filename;
    
    size_t dotPos = newFilename.find_last_of('.');
    
    if (dotPos != std::string::npos) {
        newFilename.insert(dotPos, "_spreadsheet"); // For SpreadsheetDocument we need to add _spreadsheet
    } else {
        newFilename += "_spreadsheet";
    }
    
    std::ofstream outFile(newFilename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to save file: " << newFilename << std::endl;
        return; 
    }
    
    outFile << _content;
    outFile.close();
    
    std::cout << "Save document as: " << newFilename << std::endl;
}

size_t SpreadsheetDocument::getWordCount () {
    std::istringstream ss(_content);
    size_t wordCount = 0;
    std::string word;
    while (ss >> word) {
        wordCount++;
    }
    return wordCount;
}

std::string SpreadsheetDocument::extractContent() {
    return _content;
}

std::string SpreadsheetDocument::getFormatName() {
    return "Spreadsheet";
}
