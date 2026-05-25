#ifndef TYPES_ROUTER_HPP
#define TYPES_ROUTER_HPP

#include <cstddef>

template <typename T_> class TypesRouter;
template <typename T_> struct TypeImplement;

template <> struct TypeImplement<int>
{
    static constexpr const char* NAME = "int";
    static constexpr std::size_t ID = 1;

    static void process(TypesRouter<int>& obj, int value);
};

template <typename T_> class TypesRouter
{
private:
    std::size_t _typeIdx{};
    const char* _typeName{};
    T_ _value{};

public:
    explicit TypesRouter(T_ value);

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

template <typename T_> TypesRouter<T_>::TypesRouter(T_ value)
{
    setValue(value);
    TypeImplement<T_>::process(*this, value);
}

inline void TypeImplement<int>::process(TypesRouter<int>& obj, int value)
{
    obj.setTypeIdx(ID);
    obj.setTypeName(NAME);
    obj.setValue(value * 10);
}

#endif
