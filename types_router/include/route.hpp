#pragma once

#include "types_router.hpp"

#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
struct IsVector : std::false_type {};

template <typename T>
struct IsVector<std::vector<T>> : std::true_type {};

template <typename T>
void route(const T& value)
{
    TypesRouter<T> obj(value);

    if constexpr (std::is_same_v<T, int>)
    {
        std::cout << "[" << obj.getTypeName() << "] "
                  << "ID: " << obj.getTypeIdx()
                  << " | Size: " << sizeof(T)
                  << " | Processed: x10 = " << obj.getValue()
                  << '\n';
    }
    else if constexpr (std::is_same_v<T, double>)
    {
        std::cout << "[" << obj.getTypeName() << "] "
                  << "ID: " << obj.getTypeIdx()
                  << " | Size: " << sizeof(T)
                  << " | Processed: rounded = " << obj.getValue()
                  << '\n';
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        std::cout << "[" << obj.getTypeName() << "] "
                  << "ID: " << obj.getTypeIdx()
                  << " | Size: " << sizeof(T)
                  << " | Processed: upper = " << obj.getValue()
                  << '\n';
    }
    else if constexpr (IsVector<T>::value)
    {
        std::cout << "[" << obj.getTypeName() << "] "
                << "ID: " << obj.getTypeIdx()
                << " | Size: " << sizeof(T);

        if constexpr (std::is_same_v<typename T::value_type, int>)
        {
            const auto result = obj.getValue();

            std::cout << " | Processed: Sum = " << result[0];
        }
        else
        {
            std::cout << " | Processed: vector size = " << obj.getValue().size();
        }

        std::cout << '\n';
    }
}