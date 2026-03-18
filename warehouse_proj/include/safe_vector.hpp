#include <cstddef>

template<typename T_>
class SafeVector{
private:
    T_ *_data;
    size_t _capacity;
    size_t _size;

    void grow();

public:
    // constructor
    SafeVector(){
        _data = nullptr;
        _capacity = 0;
        _size = 0;
    }

    // destructor
    ~SafeVector(){
        delete[] _data;
    }

    T_& getIndex(size_t index){
        return _data[index];
    }

    size_t getSize(){
        return _size;
    }

    void pushBack(const T_ &value);

    // when object exists
    SafeVector& moveAssignment(SafeVector<T_> &oldElement);
    // when object doesn't exists
    SafeVector<T_>(SafeVector<T_> &oldElement);   // MoveConstructor
};

template<typename T_>
void SafeVector<T_>::grow(){
    // new capacity
    size_t newCapacity{};

    if (_capacity == 0) newCapacity = 1;
    else newCapacity = _capacity * 2;

    T_* newData = new T_[newCapacity];

    // copy elements
    for (size_t idx = 0; idx < _size; ++idx)
    {
        newData[idx] = _data[idx];
    }

    // delete old arguments
    delete[] _data;
    _data = newData;
    _capacity = newCapacity; 
}

template<typename T_>
void SafeVector<T_>::pushBack(const T_& value){
    // probably grow
    if (_size == _capacity)
    {
        grow();
    }

    _data[_size] = value;
    _size++;
}

template <typename T_>
SafeVector<T_>& SafeVector<T_>::moveAssignment(SafeVector<T_> &oldElement){
    delete[] _data;

    _data = oldElement._data;
    _size = oldElement._size;
    _capacity = oldElement._capacity;

    oldElement._data = nullptr;
    oldElement._size = 0;
    oldElement._capacity = 0;

    return *this;
}

template<typename T_>
SafeVector<T_>::SafeVector(SafeVector<T_> &oldElement){

    _data = oldElement._data;
    _size = oldElement._size;
    _capacity = oldElement._capacity;

    oldElement._data = nullptr;
    oldElement._size = 0;
    oldElement._capacity = 0;
}