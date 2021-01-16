#include "Source.h"
#include "partc.h"
int main() {
    std::vector<Device> a{
        {"Iphone", "Apple", 45.52},
        {"Iphone", "Apple", 233.22},
        {"Galaxy", "Samsung", 323.22},
        {"Galaxy", "Samsung", 444.22},
        {"Galaxy", "Samsung", 3222.22},
        {"Galaxy", "Samsung", 3.22},
        {"Xperia", "LG", 3.22},
        {"motera", "Sony", 3.22}
    };
    std::list<Device> list;
    list = handleElectronics(a);
    for_each(list.begin(), list.end(), [&](const Device& theDev) {
        cout << theDev.model << ":" << theDev.price << endl;
    });
}