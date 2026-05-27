#pragma once

#include "types_router.hpp"
#include <string>
#include <cctype>

template <>
struct TypeImplement<std::string>{
    static constexpr const char* NAME = "std::string";
    static constexpr std::size_t ID = 3;

    static void process(TypesRouter<std::string>& obj, std::string value)
    {
        for (auto& sym : value)
        {
            sym = std::toupper(static_cast<unsigned char>(sym));
        }
    
        obj.setTypeIdx(ID);
        obj.setTypeName(NAME);
        obj.setValue(value);
    }
};

