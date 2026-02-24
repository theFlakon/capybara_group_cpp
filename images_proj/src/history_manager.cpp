#include "history_manager.hpp"
#include "image.hpp"

Filter HistoryManager::invertFilter(const Filter& filter) {
    if (filter.size() != 3 || filter[0].size() != 3 ||
        filter[1].size() != 3 || filter[2].size() != 3)
        throw std::invalid_argument("Filter must be 3x3");

    double det = filter[0][0] * (filter[1][1]*filter[2][2] - filter[1][2]*filter[2][1])
            - filter[0][1] * (filter[1][0]*filter[2][2] - filter[1][2]*filter[2][0])
            + filter[0][2] * (filter[1][0]*filter[2][1] - filter[1][1]*filter[2][0]);

    if (std::abs(det) < 1e-12)
        throw std::runtime_error("Wrong filter");

    Filter inv(3, std::vector<double>(3));

    inv[0][0] =  (filter[1][1]*filter[2][2] - filter[1][2]*filter[2][1]) / det;
    inv[0][1] = -(filter[0][1]*filter[2][2] - filter[0][2]*filter[2][1]) / det;
    inv[0][2] =  (filter[0][1]*filter[1][2] - filter[0][2]*filter[1][1]) / det;

    inv[1][0] = -(filter[1][0]*filter[2][2] - filter[1][2]*filter[2][0]) / det;
    inv[1][1] =  (filter[0][0]*filter[2][2] - filter[0][2]*filter[2][0]) / det;
    inv[1][2] = -(filter[0][0]*filter[1][2] - filter[0][2]*filter[1][0]) / det;

    inv[2][0] =  (filter[1][0]*filter[2][1] - filter[1][1]*filter[2][0]) / det;
    inv[2][1] = -(filter[0][0]*filter[2][1] - filter[0][1]*filter[2][0]) / det;
    inv[2][2] =  (filter[0][0]*filter[1][1] - filter[0][1]*filter[1][0]) / det;

    return inv; 
}

void HistoryManager::addToHistory(const Filter& filter) {
    Filter invertedFilter = invertFilter(filter);
    _inversedFilters.push_back(invertedFilter);
}

void HistoryManager::undoAction(Image& image) {
    Filter lastFilter = _inversedFilters.back();
    image.applyFilter(lastFilter);
    _inversedFilters.pop_back();
}