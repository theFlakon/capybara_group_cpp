template <typename T_> requires requires(T_ a, T_ b)
{
    a < b;
}
class Item
{
private:
    T_ _id;
    T_ _value;

public:
    // constructor
<<<<<<< HEAD
    Item(T_ id, T_ value)
    {
=======
    Item() : _id(), _value() {}
    Item(T_ id, T_ value) {
>>>>>>> ea815a2fe4f937990eb5586c69040936dd2ac41a
        _id = id;
        _value = value;
    }

    T_ getId()
    {
        return _id;
    }

    T_ getValue()
    {
        return _value;
    }

    void setValue(T_ value)
    {
        _value = value;
    }
};
