#include <iostream>
#include "item.hpp"
#include "safe_vector.hpp"

int main() {

    SafeVector<Item<int>> items;

    items.pushBack(Item<int>(3, 100));
    items.pushBack(Item<int>(1, 50));
    items.pushBack(Item<int>(2, 100));
    items.pushBack(Item<int>(4, 25));

    for (size_t idx = 0; idx < items.getSize(); idx++) {
        std::cout << "id = " << items.getIndex(idx).getId()
                  << ", value = " << items.getIndex(idx).getValue()
                  << '\n';
    }

    return EXIT_SUCCESS;
}