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

template <typename T>
constexpr size_t typeId()
{
    return typeIdV<T>;
}

// type name
template <typename T>
constexpr const char* typeName() { return "unknown"; }

template <> 
constexpr const char* typeName<int>() { return "int"; }
template <> 
constexpr const char* typeName<double>() { return "double"; }
template <> 
constexpr const char* typeName<std::string>() { return "std::string"; }