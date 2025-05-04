#pragma once
#include <string>

namespace DedSec {
class Config {
public:
    static Config& get_instance() {
        static Config instance;
        return instance;
    }

    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

    const std::string& get_symbols() const { return symbols; }
    uint32_t get_symbol_count() const { return symbol_count; }
    uint32_t get_target_width() const { return target_width; }
    double get_font_aspect() const { return font_aspect; }

private:
    Config() {
        symbols = " .,:;+*?%S#@░▒▓█";
        symbol_count = 16;
        target_width = 1000; //больше = лучше качество
        font_aspect = 0.4;
    }

    ~Config() = default;

    std::string symbols;
    uint32_t symbol_count;
    uint32_t target_width;
    double font_aspect;
};
}