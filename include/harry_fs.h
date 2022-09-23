#pragma once
#include <filesystem>
#include <system_error>
#include <string_view>
#include <cstdio>

namespace harry::fs {
    namespace stdfs = std::filesystem;
    using std::string_view;

    bool has_file(const char* path);
    int read_file(const char* file_path);
    int write_file(const char* file_path);
}