//
// Created by Olesya on 14-Jan-22.
//

#include <iostream>
#include <gtest/gtest.h>
#include <fstream>
#include <json/json.h>
#include "Knapsack.h"
#include <gmock/gmock.h>
#include <chrono>

void config_problem(const std::string& fileName);
void run(const std::string& input);
void printLogo();
void readData();

template <typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

int main(int argc, char* argv[]) {

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (std::string(argv[i]) == "--help") {

                printLogo();

            } else if (std::string(argv[i]) == "--run") {

                std::cout << "Program has 2 prepared configuration files:\n"
                             "\t[1] Basic configuration file, 3 items, knapsack with capacity in size 4;\n"
                             "\t[2] Slightly more advanced configuration, more objects and knapsack size;\n"
                             "\tPlease, input configuration number or filename if you want to use your own json configuration.\n";
                std::string input; std::cin >> input;

                auto start = std::chrono::high_resolution_clock::now();

                run(input);

                auto end = std::chrono::high_resolution_clock::now();
                std::cout << "\n======================Needed time==========================\n";
                std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";

            } else if (std::string(argv[i]) == "--solve") {

                auto start = std::chrono::high_resolution_clock::now();
                readData();
                auto end = std::chrono::high_resolution_clock::now();
                std::cout << "\n======================Needed time==========================\n";
                std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";

            } else if (std::string(argv[i]) == "--tests") {

                auto start = std::chrono::high_resolution_clock::now();

                testing::InitGoogleTest(&argc, argv);
                RUN_ALL_TESTS();

                auto end = std::chrono::high_resolution_clock::now();
                std::cout << "\n======================Needed time==========================\n";
                std::cout << "Needed " << to_ms(end - start).count() << " ms to finish.\n";

            } else {
                std::cout << "Unexpected token";
            }
        }
    } return 0;
}



void run(const std::string& input) {

    std::string filename;

    if (std::isdigit(input.c_str()[0])) {
        filename = "conf";
        filename.push_back(input.c_str()[0]);
        filename += ".json";
    } else {
        filename = input;
    }

    std::ifstream file;
    file.open("../../" + filename);

    if (file) {
        config_problem(filename);
    } else {
        std::cout << "File doesn't exist";
    }
}

void printLogo() {
    std::ifstream file("../../help.txt");
    std::string msg;
    while (std::getline(file, msg)) {
        std::cout << msg << std::endl;
    }
    file.close();
}

void solve(const std::vector<Item>& items, int knapsack_size) {

    Knapsack ks(knapsack_size);
    ks.collectItems(items);

    std::cout << "=====================Solved problem========================\n";
    std::cout << ks;
    std::cout << "==================Total knapsack cost======================\n";
    std::cout << "Final cost: " + std::to_string(ks.getValue()) + ";\n";
}

void readData() {

    std::vector<Item> all_items{};

    std::cout << "Please enter number of items: \n";
    int items_num; std::cin >> items_num;
    for (int j = 0; j < items_num; ++j) {
        std::cout << "Adding new item... \n"
                     "Enter item name, weight and value with spaces:\n";
        std::string name; int weight, value;
        std::cin >> name >> weight >> value;
        all_items.emplace_back(name, weight, value);
    }
    std::cout << "Adding items is completed.\n"
                 "Now enter the backpack size: \n";
    int knapsack_size; std::cin >> knapsack_size;

    solve(all_items, knapsack_size);
}

void config_problem(const std::string& fileName) {

    std::ifstream file;
    file.open("../../" + fileName);
    Json::Value root;
    Json::Reader reader;

    reader.parse(file, root);

    int knapsack_size = root["knapsack_size"].asInt();

    std::vector<Item> items{};

    items.reserve(root["items"].size());

    for (int i = 0; i < root["items"].size(); ++i) {
        items.emplace_back(
                root["items"][i]["name"].asString(),
                    root["items"][i]["weight"].asInt(),
                       root["items"][i]["value"].asInt()
        );
    }

    solve(items, knapsack_size);
}
