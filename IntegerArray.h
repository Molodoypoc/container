#include <exception>

class bad_range : public std::exception {
public:
    const char* what() const throw() {
        return "Out of range";
    }
};

class bad_length : public std::exception {
public:
    const char* what() const throw() {
        return "Length is invalid";
    }
};

class IntegerArray {
public:
    IntegerArray(size_t length);
    IntegerArray(const IntegerArray& other);
    ~IntegerArray();
    int getSize() const;
    int& getElement(size_t index);
    const int& getElement(size_t index) const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    void insert(size_t index, int value);
    void resize(size_t new_size);
    void remove(size_t index);
    void inserts(int value);
    void inserte(int value);

    IntegerArray& operator=(const IntegerArray& right);

private:
    int* array;
    int size;
};

// IntegerArray a1
// const IntegerArray a = a1 = IntegerArray(5);
// IntegerArray b = a;
// b.getElement(10);
// b[10]

// new
// []
// ()
// ++
// ++
// --
// --
// +
// -
// *
// *
// /
// ==
// !=
// >
// <
// >=
// <=