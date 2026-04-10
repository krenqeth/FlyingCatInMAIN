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
        : name(n), species(s), age(a), weight(w) {}

    virtual void makeSound() const {
        std::cout << name << " Издает звук." << std::endl;
    }

    virtual void printInfo() const {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Вид: " << species << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Вес: " << weight << " кг" << std::endl;
    }

    void eat() const {
        std::cout << name << " Кушает." << std::endl;
    }

    void sleep() const {
        std::cout << name << " Спит." << std::endl;
    }

    virtual ~Animal() {}
};

// 🐱
class Cat : virtual public Animal {
protected:
    std::string color;
    int lives;
    bool isLazy;

public:
    Cat(const std::string& n, int a, double w,
        const std::string& c, int l, bool lazy)
        : Animal(n, "Кошка", a, w),
          color(c), lives(l), isLazy(lazy) {}

    void meow() const {
        std::cout << name << " Мяукает." << std::endl;
    }

    void makeSound() const override {
        meow();
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Цвет: " << color << std::endl;
        std::cout << "Жизни: " << lives << std::endl;
        std::cout << "Ленивая: " << (isLazy ? "Да" : "Нет") << std::endl;
    }
};

// 🐦
class Bird : virtual public Animal {
protected:
    double wingSpan;
    bool canFly;
    std::string habitat;

public:
    Bird(const std::string& n, int a, double w,
         double ws, bool fly, const std::string& h)
        : Animal(n, "Птица", a, w),
          wingSpan(ws), canFly(fly), habitat(h) {}

    void fly() const {
        if (canFly)
            std::cout << name << " Летает." << std::endl;
        else
            std::cout << name << " Не умеет летать." << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " Чирикает." << std::endl;
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Размах крыльев: " << wingSpan << std::endl;
        std::cout << "Может летать: " << (canFly ? "Да" : "Нет") << std::endl;
        std::cout << "Среда обитания: " << habitat << std::endl;
    }
};

// 🐶
class Dog : public Animal {
private:
    std::string breed;
    bool isTrained;
    int energyLevel;

public:
    Dog(const std::string& n, int a, double w,
        const std::string& b, bool t, int e)
        : Animal(n, "Собака", a, w),
          breed(b), isTrained(t), energyLevel(e) {}

    void bark() const {
        std::cout << name << " Лает." << std::endl;
    }

    void makeSound() const override {
        bark();
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Порода: " << breed << std::endl;
        std::cout << "Дрессирован: " << (isTrained ? "Да" : "Нет") << std::endl;
        std::cout << "Энергия: " << energyLevel << std::endl;
    }
};

// 🐱✈️
class FlyingCat : public Cat, public Bird {
private:
    double flightSpeed;
    bool hasWings;
    double maxHeight;

public:
    FlyingCat(const std::string& n, int a, double w,
              const std::string& c, int l, bool lazy,
              double ws, bool fly, const std::string& h,
              double speed, bool wings, double height)
        : Animal(n, "Летающий кот", a, w),
          Cat(n, a, w, c, l, lazy),
          Bird(n, a, w, ws, fly, h),
          flightSpeed(speed),
          hasWings(wings),
          maxHeight(height) {}

    void boostSpeed() const {
        std::cout << name << " ускоряется до " << flightSpeed << " км/ч." << std::endl;
    }

    void flyHigh() const {
        std::cout << name << " взлетает на высоту " << maxHeight << " метров." << std::endl;
    }

    void showWings() const {
        std::cout << name << (hasWings ? " имеет крылья." : " без крыльев.") << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " Мяукает и чирикает одновременно!" << std::endl;
    }

    void printInfo() const override {
        Animal::printInfo();
        std::cout << "Цвет: " << color << std::endl;
        std::cout << "Жизни: " << lives << std::endl;
        std::cout << "Размах крыльев: " << wingSpan << std::endl;
        std::cout << "Скорость полета: " << flightSpeed << " км/ч" << std::endl;
        std::cout << "Макс высота: " << maxHeight << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dog dog("Шарик", 3, 9.0, "Овчарка", true, 8);
    Cat cat("Мурка", 5, 6.5, "Белая", 9, true);
    Bird bird("Кеша", 2, 1.2, 0.4, true, "Лес");
    FlyingCat fc("СуперМурзик", 4, 5.5,
                 "Черный", 9, false,
                 0.8, true, "Горы",
                 60.0, true, 100.0);

    std::cout << "\n=== DOG ===\n";
    dog.printInfo();
    dog.makeSound();
    dog.eat();

    std::cout << "\n=== CAT ===\n";
    cat.printInfo();
    cat.makeSound();
    cat.eat();

    std::cout << "\n=== BIRD ===\n";
    bird.printInfo();
    bird.makeSound();
    bird.fly();

    std::cout << "\n=== FLYING CAT ===\n";
    fc.printInfo();
    fc.makeSound();
    fc.fly();
    fc.meow();
    fc.boostSpeed();
    fc.flyHigh();
    fc.showWings();

    std::cout << "\n=== Animal methods from FlyingCat ===\n";
    fc.eat();
    fc.sleep();

    return 0;
}