#pragma once

#include <string>
#include <vector>
#include <cstddef>

// for unknown type id = 0
template <typename T>
constexpr size_t typeIdV = 0;   

template <>
constexpr size_t typeIdV<int> = 1;

template <>
constexpr size_t typeIdV<double> = 2;

template <>
constexpr size_t typeIdV<std::string> = 3;

template <typename T>
constexpr size_t typeIdV<std::vector<T>> = 4;

// function
template <typename T>
constexpr size_t typeId()
{
    return typeIdV<T>;
}