template <typename T_>
requires requires(T_ a, T_ b) { a < b; }
class Item {
private:
    T_ _id;
    T_ _value;
    
public:
    // constructor
    Item(T_ id, T_ value) {
        _id = id;
        _value = value;
    }

    T_ getId() {
        return _id;
    }

    T_ getValue() {
        return _value;
    }

    void setValue(T_ value) {
        _value = value;
    }
};


int main()
{
    Item item{324, 423849};
}