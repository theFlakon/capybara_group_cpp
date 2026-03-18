#ifndef ITEM_HPP
#define ITEM_HPP

template <typename T_> requires requires(T_ a, T_ b) { a < b; }
class Item
{
private:
    T_ _id;
    T_ _value;
public:
    // constructor
    Item() : _id{}, _value{} {};
    Item(T_ id, T_ value) : _id(id), _value(value) {}

    const T_& getId() const { return _id; }
    const T_& getValue() const { return _value; }

    void setValue(T_ value)
    {
        _value = value;
    }
};

#endif