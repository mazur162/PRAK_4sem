#include <stdexcept>

template <typename T>
class Array {
public:
    Array(size_t);
    Array(Array&);
    Array& operator= (Array&);
    ~Array();
    size_t length() const;
    T& operator[] (size_t) const;
private:
    T *arr;
    size_t len;
};

template <typename T>
Array<T>::Array(size_t size) : arr(nullptr), len(size) {
    arr = new T[size];
}

template <typename T>
Array<T>::Array(Array &a) : arr(a.arr), len(a.len) {
    a.arr = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator= (Array &b) {
    if (&b == this) {
        return *this;
    }
    delete[] arr;
    arr = b.arr;
    len = b.len;

    b.arr = nullptr;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
size_t Array<T>::length() const {
    if (arr == nullptr) {
        return 0;
    } else {
        return len;
    }
}

template <typename T>
T& Array<T>::operator[] (size_t i) const {
    if (i >= len) {
        throw (std::out_of_range("Error: Array index out of range"));
    } else if (arr == nullptr) {
        throw (std::out_of_range("Error: Object doesn't own this array"));
    } else {
        return arr[i];
    }
}
