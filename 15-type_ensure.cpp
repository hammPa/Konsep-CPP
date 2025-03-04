#include <iostream>
#include <memory>
#include <string>

// Base class untuk type erasure
class BaseLet {
public:
    virtual ~BaseLet() = default;
    virtual void print() const = 0;
};

// Template class untuk menyimpan berbagai tipe data
template <typename T>
class HolderLet : public BaseLet {
private:
    T value;
public:
    explicit HolderLet(T val) : value(std::move(val)) {}

    void print() const override {
        std::cout << value << "\n";
    }
};

// Class let dengan type erasure
class let {
private:
    std::shared_ptr<BaseLet> data;
public:
    // Constructor template untuk mendukung berbagai tipe
    template <typename T>
    let(T val) : data(std::make_shared<HolderLet<T>>(std::move(val))) {}

    // Method untuk menampilkan nilai
    void print() const {
        if (data) data->print();
    }

    // Method untuk mengubah data
    template <typename T>
    void set(T val) {
        data = std::make_shared<HolderLet<T>>(std::move(val));
    }
};

struct tes {
    int data;
    tes(int val) : data(val) {}
    friend std::ostream& operator<<(std::ostream& os, const tes& obj) {
        os << obj.data;
        return os;
    }
};

int main() {
    let a = 10;        // Menyimpan integer
    a.print();         // Output: 10
    
    let b = "oilah";   // Menyimpan string
    b.print();         // Output: oilah
    
    a = "ahihihi";  // Mengubah menjadi string
    a.print();         // Output: ahihihi
    
    // Menyimpan struct
    tes t = 42;
    let c = t;
    c.print();         // Output: 42

    return 0;
}
