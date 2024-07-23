#include <iostream>

class rectangle {
    public:
    typedef int unit;
    void area();
    void set(unit wd, unit ht);

    private:
    unit width;
    unit height;
};

void rectangle::set(unit wd, unit ht) {
    width = wd;
    height = ht;
}

void rectangle::area() {
    std::cout << "Area: " << width * height << std::endl;
}

int main() {
    rectangle obj, *obj2;
    rectangle::unit x, y;

    std::cin >> x;
    std::cin >> y;

    obj.set(x,y);
    obj2 = &obj; // this usage of & is only available in c++

    obj.area();
    obj2->area();

    return 0;
}
