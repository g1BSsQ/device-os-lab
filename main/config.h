#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

class DeviceConfig {
public:
    DeviceConfig();
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    bool has(const std::string& key) const;
    void remove(const std::string& key);
    std::map<std::string, std::string> getAll() const;
private:
    std::map<std::string, std::string> config_;
};

#endif // CONFIG_H
