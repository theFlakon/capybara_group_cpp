#include <iostream>
#include "image.hpp"
#include "history_manager.hpp"
#include "file_parser.hpp"

int main() {
    try {
        Image image{};
        FileParser fileParser;

        std::string path = "image.png";
        fileParser.parse(path, image);
        
        Filter halfFilter = {
            {0.5, 0.5, 0.5},
            {0.5, 0.5, 0.5},
            {0.5, 0.5, 0.5}
        };

        HistoryManager history;
        history.addToHistory(halfFilter);
        image.applyFilter(halfFilter);
        fileParser.writePixelsToFile(path, image);

        //history.undoAction(image);
        //std::cout << "Undo applied\n";

        std::cout << "Program completed successfully\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}