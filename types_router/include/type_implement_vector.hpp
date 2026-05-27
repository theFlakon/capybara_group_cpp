#pragma once

#include <numeric>
#include <string>
#include <type_traits>
#include <vector>
#include "types_router.hpp"
#include "type_id.hpp"

template <typename T>
struct TypeImplement<std::vector<T>> {
    static constexpr std::size_t ID = 4;

    static void process(TypesRouter<std::vector<T>>& obj, std::vector<T> value)
    {
        T sum = std::accumulate(value.begin(), value.end(), T{});

        obj.setTypeIdx(ID);
        obj.setTypeName(std::string("std::vector<") + typeName<T>() + ">");
        obj.setValue({sum});
    }
};