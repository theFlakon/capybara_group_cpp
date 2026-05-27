#pragma once

#include "types_router.hpp"
#include <cmath>
#include <cstddef>

template <>
struct TypeImplement<double>{
    // static for all double has same id
    static constexpr const char* NAME = "double";
    static constexpr size_t ID = 2;

    // static for non-creating pbject
    static void process(TypesRouter<double>& obj, double value)
    {
        obj.setTypeIdx(ID);
        obj.setTypeName(NAME);
        obj.setValue(std::round(value * 10.0) / 10.0);
    }
};




