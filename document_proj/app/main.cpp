#include "document_processor.hpp"
#include "text_document.hpp"
#include "pdf_document.hpp"
#include "spreadsheet_document.hpp"
#include <vector>
#include <memory>
#include <iostream>

int main() {
    std::vector<std::unique_ptr<Document>> docs;

    docs.push_back(std::make_unique<TextDocument>(
        "Hello world. This is a simple text document."));

    docs.push_back(std::make_unique<TextDocument>(
        "Another text file"));

    docs.push_back(std::make_unique<PDFDocument>("report.pdf"));

    docs.push_back(std::make_unique<PDFDocument>("invoice.pdf"));

    docs.push_back(std::make_unique<SpreadsheetDocument>("data.csv"));

    DocumentProcessor processor;

    processor.processAll(std::move(docs));

    processor.updateAll();

    std::cout << "=== Export Summary ===\n";
    processor.exportAll(std::cout);

    return 0;

}