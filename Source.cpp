#include <iostream>
#include <string>
#include <Windows.h>

class Animal {
protected:
    std::string name;
    std::string species;
    int age;
    double weight;

public:
    Animal(const std::string& n, const std::string& s, int a, double w)
        : name(n), species(s), age(a), weight(w) {
    }

    virtual void makeSound() const {
        std::cout << name << " Издает звук." << std::endl;
    }

    virtual void printInfo() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Вид: " << species << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Вес: " << weight << " кг" << std::endl;
    }

    virtual ~Animal() {}
};


class Cat : virtual public Animal {
protected:
    std::string color;
    int lives;
    bool isLazy;

public:
    Cat(const std::string& n, int a, double w,
        const std::string& c, int l, bool lazy)
        : Animal(n, "Кошка", a, w),
        color(c), lives(l), isLazy(lazy) {
    }

    void meow() const {
        std::cout << name << " Мяукает." << std::endl;
    }

    void makeSound() const override {
        meow();
    }
};

class Bird : virtual public Animal {
protected:
    double wingSpan;
    bool canFly;
    std::string habitat;

public:
    Bird(const std::string& n, int a, double w,
        double ws, bool fly, const std::string& h)
        : Animal(n, "Птица", a, w),
        wingSpan(ws), canFly(fly), habitat(h) {
    }

    void fly() const {
        if (canFly)
            std::cout << name << " Летает." << std::endl;
        else
            std::cout << name << " Не умеет летать." << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " Чирикает." << std::endl;
    }
};


class FlyingCat : public Cat, public Bird {
private:
    int flightspeed;
    bool hasWings;
    double maxHeight;

public:
    FlyingCat(const std::string& n, int a, double w,
        const std::string& c, int l, bool lazy,
        double ws, bool fly, const std::string& h,
        double speed , bool wings, double height)
        : Animal(n, "Летающий кот", a, w), 
        Cat(n, a, w, c, l, lazy),
        Bird(n, a, w, ws, fly, h),
        flightspeed(speed), hasWings(wings), maxHeight(height) {
    }

    void boostSpeed() const {
        std::cout << name << " Ускоряется до " << flightspeed << "км/ч." << std::endl;
    }

    void flyHigh() const {
        std::cout << name << " Взлетает на высоту " << maxHeight << " метров." << std::endl;
    }

    void showWings() const {
        std::cout << name << (hasWings ? " Имеет крылья." : " Без крыльев.") << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " Мяукает и чирикает одновременно!" << std::endl;
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Цвет: " << color << std::endl;
        std::cout << "Жизни: " << lives << std::endl;
        std::cout << "Размах крыльев: " << wingSpan << std::endl;
        std::cout << "Скорость полёта: " << flightspeed << std::endl;
        std::cout << "Макс высота: " << maxHeight << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FlyingCat fc(
        "КрылатыйТиша",
        4,
        5.5,
        "Черный", 
        9,
        false,
        0.8, 
        true,
        "Горы",
        80, 
        true,
        100.0);

    fc.printInfo();
    std::cout << std::endl;

    fc.makeSound();
    fc.fly();
    fc.boostSpeed();
    fc.flyHigh();
    fc.showWings();

    return 0;
}