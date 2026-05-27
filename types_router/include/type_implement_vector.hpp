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
        T sum = std::accumulate(value.begin(), value.end(), T{});

        obj.setTypeIdx(ID);
        obj.setTypeName(NAME);
        obj.setValue({sum});
    }
};