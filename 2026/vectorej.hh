#ifndef vectorej_HH
#define vectorej_HH
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Vector {
private:
    T* storage;
    unsigned int cap;
    unsigned int sz;
public:
    Vector() {
        cap = 5;
        storage = new T[cap];
        sz = 0;
    }
    Vector(unsigned int c) {
        cap = c;
        storage = new T[cap];
        sz = 0;
    }
    ~Vector() {
        delete [] storage;
    }
    unsigned int size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    unsigned int capacity() const {
        return cap;
    }
    
    void push_back(T elem) {
        resize();
        storage[sz] = elem;
        sz++;
    }
    
    void pop_back() {
      assert(!empty());
      sz--;
    }

    void pop_front() {
        assert(!empty());
        for(unsigned int i = 0; i < sz-1; i++) {
            storage[i] = storage[i+1];
        }
        sz--;
    }

    void insert(unsigned int pos, T elem) {
        assert(pos <= sz);
        resize();
        for(unsigned int i = sz; i > pos; i--) {
            storage[i] = storage[i-1];
        }
        storage[pos] = elem;
        sz++;
    }

    void erase(unsigned int from, unsigned int to) {
        assert(from <= to);
        assert(to <= sz);
        unsigned int count = to - from;
        for (unsigned int i = to; i < sz; ++i) {
            storage[i - count] = storage[i];
        }
        sz -= count;
    }
    void clear() {
        sz = 0;
    } 

    bool contains(const T& elem) const {
        return find(elem) != -1;
    }

    int find(const T& elem) const {
        for(unsigned int i = 0; i < sz; i++) {
            if (storage[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    void remove (const T& elem) {
        int pos = find(elem);
        if (pos != -1) {
            erase(pos, pos+1);
        }
    }
    void replace(const T &oldVal, const T &newVal) {
        int pos = find(oldVal);
        if (pos != -1) {
            storage[pos] = newVal;
        }
    }

    void remove_all(const T &elem) {
        int pos = find(elem);
        while (pos != -1) {
            erase(pos, pos+1);
            pos = find(elem);
        }
    }

    void replace_all(const T &oldVal, const T &newVal) {
        int pos = find(oldVal);
        while (pos != -1) {
            storage[pos] = newVal;
            pos = find(oldVal);
        }
    }

    int count(const T &elem) const {
        return indices_of(elem).size();
    }

    Vector<T> indices_of(const T &elem) const {
        Vector<int> indices;
        for(unsigned int i = 0; i < sz; i++) {
            if (storage[i] == elem) {
                indices.push_back(i);
            }
        }
        return indices;
    }

    void swap(unsigned int i, unsigned int j) {
        assert(i < sz && j < sz);
        T temp = storage[i];
        storage[i] = storage[j];
        storage[j] = temp;
    }

    void reverse() {
        for(unsigned int i = 0; i < sz / 2; i++) {
            swap(i, sz - 1 - i);
        }
    }

    void rotate_left(unsigned int k) {
        if (empty()) return;
        k = k % sz;
        T* temp = new T[sz];
        for(unsigned int i = 0; i < sz; i++) {
            temp[i] = storage[(i + k) % sz];
        }
        for(unsigned int i = 0; i < sz; i++) {
            storage[i] = temp[i];
        }
        delete [] temp;
       
    }


    void rotate_right(unsigned int k) {
        if (sz == 0) return;
        k = k % sz;
        if (k == 0) return;
        Vector<T> temp(sz);
        for(unsigned int i = 0; i < sz; i++) {
            temp[i] = storage[(i + sz - k) % sz];
        }
        for(unsigned int i = 0; i < sz; i++) {
            storage[i] = temp[i];
        }
    }

    void sort() {
    if (sz <= 1) return;
    quicksort(0, sz - 1);
}

    void quicksort(int low, int high) {
    if (low >= high) return;

    T pivot = storage[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (storage[j] < pivot) {   
            i++;
            swap(i, j);            
        }
    }

    swap(i + 1, high);

    int pivotIndex = i + 1;

    quicksort(low, pivotIndex - 1);
    quicksort(pivotIndex + 1, high);
}

    void append(const Vector<T> &other){
    for(unsigned int i = 0; i < other.size(); i++) {
        push_back(other[i]);
    }
}

    void slice(unsigned int from, unsigned int to) const {
        assert(from <= to);
        assert(to <= sz);
        Vector<T> result;
        for (unsigned int i = from; i < to; ++i) {
            result.push_back(storage[i]);
        }
        result.print();
    }
    void operator=(const Vector<T> &other) {
        if (this != &other) {
            delete [] storage;
            cap = other.cap;
            sz = other.sz;
            storage = new T[cap];
            for(unsigned int i = 0; i < sz; i++) {
                storage[i] = other.storage[i];
            }
        }
    }
    template <typename Predicate>
     bool any(Predicate p) const {
        for(unsigned int i = 0; i < sz; i++) {
            if (p(storage[i])) {
                return true;
            }
        }
        return false;
    }
    template <typename Predicate>
    bool   all(Predicate p) const {
        for(unsigned int i = 0; i < sz; i++) {
            if (!p(storage[i])) {
                return false;
            }
        }
        return true;
    }

    template <typename Predicate>
    bool none(Predicate p) const {
        for(unsigned int i = 0; i < sz; i++) {
            if (p(storage[i])) {
                return false;
            }
        }
        return true;
    }

    template <typename Predicate>
    bool any_(Predicate p) const {
    return !none(p);
}

    template <typename Predicate>
    bool none_(Predicate p) const {
    return all([&](const T& x) { return !p(x); });
}
    template <typename Predicate>
    Vector<T> filter(Predicate p) const {
        Vector<T> result;
        for(unsigned int i = 0; i < sz; i++) {
            if (p(storage[i])) {
                result.push_back(storage[i]);
            }
        }
        return result;
    }

    template <typename Function>
    Vector<T> map(Function p) const {
        Vector<T> result;
        for(unsigned int i = 0; i < sz; i++) {
            result.push_back(p(storage[i]));
        }
        return result;
    }
    template <typename Function>
    void for_each(Function f) {
        for(unsigned int i = 0; i < sz; i++) {
            f(storage[i]);
        }
    }



    const T& front() const {
        assert(!empty());
        return storage[0];
    }

    T& front() {
        assert(!empty());
        return storage[0];
    }

    const T& back() const {
        assert(!empty());
        return storage[sz-1];
    }
  
    T& back() {
        assert(!empty());
        return storage[sz-1];
    }

    const T& at(unsigned int pos) const {
        assert(pos < sz);
        return storage[pos];
    }

    T& at(unsigned int pos) {
        assert(pos < sz);
        return storage[pos];
    }

    const T& operator[](unsigned int pos) const {
        return storage[pos];
    }

    T& operator[](unsigned int pos) {
        return storage[pos];
    }


    void shrink_to_fit() {
        if (sz == cap) return;
        T* newStorage = new T[sz];
        for(unsigned int i = 0; i < sz; i++) {
            newStorage[i] = storage[i];
        }
        delete [] storage;
        storage = newStorage;
        cap = sz;
    }
    
private:
    void resize() {
        if (sz == cap) {
            unsigned int newCapacity = cap * 1.5;
            T* newStorage = new T[newCapacity];
            for(unsigned int i = 0; i < sz; i++) {
                newStorage[i] = storage[i];
            }
            delete [] storage;
            storage = newStorage;
            cap = newCapacity;
        }
    }
public:
    void print() const {
        cout << "{";
        for(unsigned int i = 0; i < sz; i++) {
            cout << storage[i] << " ";
        }
        cout << "}" << endl;
    }

};
#endif

//compilar
//g++ vectorej.hh -o vectorp
