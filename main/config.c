#include "config.h"
#include <fstream>
#include <sstream>

DeviceConfig::DeviceConfig() {}

bool DeviceConfig::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    config_.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            config_[key] = value;
        }
    }
    return true;
}

bool DeviceConfig::save(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    for (const auto& kv : config_) {
        file << kv.first << "=" << kv.second << "\n";
    }
    return true;
}

void DeviceConfig::set(const std::string& key, const std::string& value) {
    config_[key] = value;
}

std::string DeviceConfig::get(const std::string& key) const {
    auto it = config_.find(key);
    if (it != config_.end()) return it->second;
    return "";
}

bool DeviceConfig::has(const std::string& key) const {
    return config_.find(key) != config_.end();
}

void DeviceConfig::remove(const std::string& key) {
    config_.erase(key);
}

std::map<std::string, std::string> DeviceConfig::getAll() const {
    return config_;
}
