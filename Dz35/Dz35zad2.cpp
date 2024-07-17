#include <iostream>
#include <list>
#include <string>

struct Taxi {
    int number;
    std::string brand;
    std::string driver;
    bool onCall;

    Taxi(int number, const std::string& brand, const std::string& driver)
        : number(number), brand(brand), driver(driver), onCall(false) {}
};

std::list<Taxi> onTaxi;

void printAllTaxis() {
    for (const auto& taxi : onTaxi) {
        std::cout << "Taxi " << taxi.number << ": " << taxi.brand << " driven by " << taxi.driver;
        if (taxi.onCall) {
            std::cout << " (on call)";
        }
        else {
            std::cout << " (free)";
        }
        std::cout << std::endl;
    }
}

void addTaxiToFront(int number, const std::string& brand, const std::string& driver) {
    onTaxi.emplace_front(number, brand, driver);
}

void addTaxiBefore(int before, int number, const std::string& brand, const std::string& driver) {
    auto it = onTaxi.begin();
    while (it != onTaxi.end() && it->number != before) {
        ++it;
    }
    if (it != onTaxi.end()) {
        onTaxi.emplace(it, number, brand, driver);
    }
}

void removeTaxi(int number) {
    auto it = onTaxi.begin();
    while (it != onTaxi.end() && it->number != number) {
        ++it;
    }
    if (it != onTaxi.end()) {
        onTaxi.erase(it);
    }
}

void setOnCall(int number) {
    for (auto& taxi : onTaxi) {
        if (taxi.number == number) {
            taxi.onCall = true;
            return;
        }
    }
}

void setFree(int number) {
    for (auto& taxi : onTaxi) {
        if (taxi.number == number) {
            taxi.onCall = false;
            return;
        }
    }
}

void printFreeTaxis() {
    for (const auto& taxi : onTaxi) {
        if (!taxi.onCall) {
            std::cout << "Taxi " << taxi.number << ": " << taxi.brand << " driven by " << taxi.driver << std::endl;
        }
    }
}

void printOnCallTaxis() {
    for (const auto& taxi : onTaxi) {
        if (taxi.onCall) {
            std::cout << "Taxi " << taxi.number << ": " << taxi.brand << " driven by " << taxi.driver << std::endl;
        }
    }
}

int main() {
    addTaxiToFront(1, "Toyota", "John Smith");
    addTaxiToFront(2, "Ford", "Jane Doe");
    addTaxiToFront(3, "Honda", "Bob Johnson");

    printAllTaxis();

    addTaxiBefore(2, 4, "Nissan", "Alice Brown");

    printAllTaxis();

    removeTaxi(2);

    printAllTaxis();

    setOnCall(1);

    printOnCallTaxis();

    setFree(1);

    printFreeTaxis();

    return 0;
}