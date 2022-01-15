//
// Created by Olesya on 14-Jan-22.
//

#include <gtest/gtest.h>
#include "../Knapsack.h"

using testing::Eq;

TEST(knapsack_tests, test_normal_values) {

    int ks_size = 4;
    Knapsack knapsack(ks_size);

    Item item1("necklace", 4,4000);
    Item item2("ring", 1,2500);
    Item item3("pendent", 3,2000);

    knapsack.collectItems(std::vector<Item>{item1, item2, item3});

    int result = knapsack.getValue();
    int expected = 4500;

    ASSERT_EQ(result, expected);
}

TEST(knapsack_tests, test_big_values) {

    int ks_size = 1000;
    Knapsack knapsack(ks_size);

    knapsack.collectItems(std::vector<Item> {
        Item("1", 600,4000),
        Item("2", 700,2500),
        Item("3", 2,6340),
        Item("4", 52,1030),
        Item("5", 112,150),
        Item("6", 412,606),
        Item("7", 82,3000),
        Item("8", 2,2800),
        Item("9", 8,2540),
        Item("10", 302,2500)
    });

    int result = knapsack.getValue();
    int expected = 21180;

    ASSERT_EQ(result, expected);
}

TEST(knapsack_tests, knapsack_not_full) {

    int ks_size = 10;
    Knapsack knapsack(ks_size);

    Item item1("necklace", 1,1000);
    Item item2("ring", 1,1000);
    Item item3("pendent", 1,1000);

    knapsack.collectItems(std::vector<Item>{item1, item2, item3});

    int result = (int) knapsack.getItems().size();
    int expected = 3;

    ASSERT_EQ(result, expected);
}

TEST(knapsack_tests, too_big_items_for_knapsack) {

    int ks_size = 1;
    Knapsack knapsack(ks_size);

    Item item1("necklace", 2,1000);
    Item item2("ring", 5,1000);
    Item item3("pendent", 7,1000);

    knapsack.collectItems(std::vector<Item>{item1, item2, item3});

    int result = (int) knapsack.getItems().size();
    int expected = 0;

    ASSERT_EQ(result, expected);
}

TEST(knapsack_tests, no_items_knapsack) {

    int ks_size = 1;
    Knapsack knapsack(ks_size);

    knapsack.collectItems(std::vector<Item>{});

    int result = (int) knapsack.getItems().size();
    int value = (int) knapsack.getValue();

    int expected = 0;

    ASSERT_EQ(result, expected);
    ASSERT_EQ(value, expected);
}

TEST(knapsack_tests, no_size_knapsack) {

    int ks_size = 0;
    Knapsack knapsack(ks_size);

    knapsack.collectItems(std::vector<Item> {
        Item("necklace", 2,1000),
        Item("ring", 5,1000),
        Item("pendent", 7,1000)
    });

    int result = (int) knapsack.getItems().size();
    int value = (int) knapsack.getValue();

    int expected = 0;

    ASSERT_EQ(result, expected);
    ASSERT_EQ(value, expected);
}