# 📦 warehouse_proj

A simple C++ project demonstrating template classes, a custom dynamic array, and move semantics.

## 🚀 Features

* **Item<T>** — template class with `id` and `value`
* **SafeVector<T>** — custom dynamic array implementation
* Move constructor and move assignment
* Dynamic memory management (`new[]`, `delete[]`)
* Basic push and access operations

## 🧩 Technologies

* C++20 (requires `requires` / concepts)
* CMake

## ▶️ Build & Run

```bash
mkdir build
cd build
cmake ..
make
./warehouse_proj
```

## 📌 Description

The project implements a simplified version of `std::vector` and demonstrates:

* working with templates
* memory management
* move semantics for efficient data transfer

## 📁 Structure

```
warehouse_proj/
├── app/
│   └── main.cpp
├── include/
│   ├── item.hpp
│   └── safe_vector.hpp
└── CMakeLists.txt
```
