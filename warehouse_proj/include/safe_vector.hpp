#include <cstddef>

template<typename T>
class SafeVector{
private:
    T *data;
    size_t capacity;
    size_t size;

    void grow();

public:
    // constructor
    SafeVector(){
        data = nullptr;
        capacity = 0;
        size = 0;
    }

    // destructor
    ~SafeVector(){
        delete[] data;
    }

    T& get_Index(size_t index){
        return data[index];
    }

    size_t getSize(){
        return size;
    }

    void push_back(const T &value);

    // when object exists
    SafeVector& MoveAssignment(SafeVector<T> &oldElement);
    // when object doesn't exists
    SafeVector<T>(SafeVector<T> &oldElement);   // MoveConstructor
};

template<typename T>
void SafeVector<T>::grow(){
    // new capacity
    size_t newCapacity{};

    if (capacity == 0) newCapacity = 1;
    else newCapacity = capacity * 2;

    T* newData = new T[newCapacity];

    // copy elements
    for (size_t idx = 0; idx < size; ++idx)
    {
        newData[idx] = data[idx];
    }

    // delete old arguments
    delete[] data;
    data = newData;
    capacity = newCapacity; 
}

template<typename T>
void SafeVector<T>::push_back(const T& value){
    // probably grow
    if (size == capacity)
    {
        grow();
    }

    data[size] = value;
    size++;
}

template <typename T>
SafeVector<T>& SafeVector<T>::MoveAssignment(SafeVector<T> &oldElement){
    delete[] data;

    data = oldElement.data;
    size = oldElement.size;
    capacity = oldElement.capacity;

    oldElement.data = nullptr;
    oldElement.size = 0;
    oldElement.capacity = 0;

    return *this;
}

template<typename T>
SafeVector<T>::SafeVector(SafeVector<T> &oldElement){

    data = oldElement.data;
    size = oldElement.size;
    capacity = oldElement.capacity;

    oldElement.data = nullptr;
    oldElement.size = 0;
    oldElement.capacity = 0;
}