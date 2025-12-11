#include "config.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp> // For JSON parsing

using json = nlohmann::json;

bool Config::load(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filepath << std::endl;
        return false;
    }

    try {
        json j;
        file >> j;
        settings = j.get<std::map<std::string, std::string>>();
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config file: " << e.what() << std::endl;
        return false;
    }

    return true;
}

std::string Config::get(const std::string& key, const std::string& default_value) const {
    auto it = settings.find(key);
    return it != settings.end() ? it->second : default_value;
}
