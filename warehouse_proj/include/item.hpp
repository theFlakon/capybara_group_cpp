template <typename T>
requires requires(T a, T b) { a < b; }
class Item {
public:
    T id;
    T value;
};