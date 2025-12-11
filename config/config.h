#pragma once

#include <string>
#include <map>

class Config {
public:
    /**
     * @brief Loads configuration from a JSON file.
     * @param filepath Path to the configuration file.
     * @return True if the file was loaded successfully, false otherwise.
     */
    bool load(const std::string& filepath);

    /**
     * @brief Retrieves a configuration value by key.
     * @param key The key to look up.
     * @param default_value The default value to return if the key is not found.
     * @return The configuration value or the default value if the key is not found.
     */
    std::string get(const std::string& key, const std::string& default_value = "") const;

private:
    std::map<std::string, std::string> settings;
};