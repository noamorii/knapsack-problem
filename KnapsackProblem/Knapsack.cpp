//
// Created by Olesya on 14-Jan-22.
//

#include <iostream>
#include <thread>
#include "Knapsack.h"

void Knapsack::collectItems(const std::vector<Item>& all_items) {

    int knapsack_table[all_items.size() + 1][knapsack_size + 1];

    for (int i = 0; i < all_items.size() + 1; ++i) {
        for (int j = 0; j <= knapsack_size; ++j) {
            if ((i == 0) || (j == 0)) {
                knapsack_table[i][j] = 0;
            } else {
                if (all_items[i - 1].getWeight() > j) {
                    knapsack_table[i][j] = knapsack_table[i-1][j];
                } else {
                    int previous_value = knapsack_table[i-1][j];
                    int current_value = all_items[i-1].getValue() + knapsack_table[i - 1][j - all_items[i - 1].getWeight()];
                    knapsack_table[i][j] = std::max(previous_value, current_value);
                }
            }
        }
    }

    int current_item = (int) all_items.size();
    int current_weight = knapsack_size;

    while (current_item > 0 && current_weight > 0) {
        if (knapsack_table[current_item][current_weight] != knapsack_table[(current_item - 1)][current_weight]) {
            addItem(all_items[current_item - 1]);
            current_weight -= all_items[current_item - 1].getWeight();
        }
        current_item--;
    }

    knapsack_value = knapsack_table[all_items.size()][knapsack_size];
}
