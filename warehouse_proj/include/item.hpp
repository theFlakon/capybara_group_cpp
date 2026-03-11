template <typename T>
requires requires(T a, T b) { a < b; }
class Item {
private:
    T _id;
    T _value;
    
public:
    Item(T id, T value) {
        _id = id;
        _value = value;
    }

    T getId() {
        return _id;
    }

    T getValue() {
        return _value;
    }

    void setValue(T value) {
        _value = value;
    }
};


int main()
{
    Item item{324, 423849};
}