#ifndef TYPES_ROUTER_HPP
#define TYPES_ROUTER_HPP

#include <cstddef>

// Forward declarations of the class and struct templates
template <typename T_> class TypesRouter;
template <typename T_> struct TypeImplement;

// Explicit template specialization of TypeImplement for the 'int' type
template <> struct TypeImplement<int>
{
    // Compilet ime constants representing metadata for 'int'
    static constexpr const char* NAME = "int";
    static constexpr std::size_t ID = 1;

    // Static function to handle type-specific logic for 'int'
    static void process(TypesRouter<int>& obj, int value);
};

// Generic class template that stores type metadata and a value
template <typename T_> class TypesRouter
{
private:
    std::size_t _typeIdx{};
    const char* _typeName{};
    T_ _value{};

public:
    // Constructor that accepts an initial value
    explicit TypesRouter(T_ value);

    // Setters
    void setTypeIdx(std::size_t typeIdx)
    {
        _typeIdx = typeIdx;
    }

    void setTypeName(const char* typeName)
    {
        _typeName = typeName;
    }

    void setValue(T_ value)
    {
        _value = value;
    }
};

// Definition of the constructor for the generic TypesRouter template
template <typename T_> TypesRouter<T_>::TypesRouter(T_ value)
{
    setValue(value);  // Initialize the internal value

    // Delegate metadata assignment and value processing to the TypeImplement
    // struct.
    TypeImplement<T_>::process(*this, value);
}

// Definition of the process function for the 'int' specialization
// Inline key word is mandatory here
inline void TypeImplement<int>::process(TypesRouter<int>& obj, int value)
{
    obj.setTypeIdx(ID);
    obj.setTypeName(NAME);
    obj.setValue(value * 10);
}

#endif
