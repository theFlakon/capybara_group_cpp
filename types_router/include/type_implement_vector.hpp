#pragma once

#include <numeric>
#include <type_traits>
#include <vector>
#include "types_router.hpp"

template <typename T>
struct TypeImplement<std::vector<T>> {
    static constexpr const char* NAME = "std::vector<T>";
    static constexpr std::size_t ID = 4;

    static void process(TypesRouter<std::vector<T>>& obj, std::vector<T> value)
    {
        obj.setTypeIdx(ID);
        obj.setTypeName(NAME);

        if constexpr (std::is_same_v<T, int>)
        {
            int sum = std::accumulate(value.begin(), value.end(), 0);

            obj.setValue(std::vector<int>{sum});
        }
        else
        {
            obj.setValue(value);
        }
    }
};
