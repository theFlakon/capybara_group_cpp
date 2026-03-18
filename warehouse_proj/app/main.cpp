#include <iostream>
#include "item.hpp"
#include "safe_vector.hpp"

int main() {

    SafeVector<Item<int>> items;

    items.push_back(Item<int>(3, 100));
    items.push_back(Item<int>(1, 50));
    items.push_back(Item<int>(2, 100));
    items.push_back(Item<int>(4, 25));

    for (size_t idx = 0; idx < items.getSize(); idx++) {
        std::cout << "id = " << items.get_Index(idx).getId()
                  << ", value = " << items.get_Index(idx).getValue()
                  << '\n';
    }

    return EXIT_SUCCESS;
}