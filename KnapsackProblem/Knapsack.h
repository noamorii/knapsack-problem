//
// Created by Olesya on 14-Jan-22.
//

#ifndef KNAPSACK_PROBLEM_KNAPSACK_H
#define KNAPSACK_PROBLEM_KNAPSACK_H

#include <string>
#include <utility>
#include <vector>
#include <ostream>

class Item {
private:

    std::string name;
    int weight;
    int value;

public:

    Item(std::string name, int weight, int value) : name(std::move(name)), weight(weight), value(value) {}

    int getWeight() const {
        return weight;
    }

    int getValue() const {
        return value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << item.name << " with weight: " << item.weight << " and value: " << item.value;
        return os;
    }
};

class Knapsack {
private:

    std::vector<Item> items{};
    int knapsack_value = 0;
    int knapsack_size;

public:

    explicit Knapsack(int size) : knapsack_size(size) {}

    void collectItems(const std::vector<Item>& allItems);

    void addItem(const Item& item) {
        items.push_back(item);
    }

    int getValue() const {
        return knapsack_value;
    }

    const std::vector<Item> &getItems() const {
        return items;
    }

    friend std::ostream &operator<<(std::ostream &os, const Knapsack &knapsack) {
        os << "Collected items: \n\t";
        for (const Item& item: knapsack.items)
            os  << item << "; \n\t";
        return os << std::endl;
    }
};

#endif //KNAPSACK_PROBLEM_KNAPSACK_H
