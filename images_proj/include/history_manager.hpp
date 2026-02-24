#ifndef HISTORY_MANAGER_HPP
#define HISTORY_MANAGER_HPP

#include "image.hpp"

class HistoryManager
{
private:
    std::vector<Filter> _inversedFilters;
    Filter invertFilter(const Filter& filter);
public:
    void addToHistory(const Filter& filter);
    void undoAction(Image& image);
};

#endif