#include "harry_fs.h"
#include <cstdio>
#include <vector>
#include <array>
#include <cstring>


namespace harry::fs {
    void test1() {
        printf("this is test1\n");

    }
    // elegant
    bool has_file(stdfs::path file_path) {
        bool is_right = stdfs::exists(file_path);
        if (is_right) {
            printf("file exists: %s\n", file_path.c_str());
        } else {
            printf("file Not exists: %s\n", file_path.c_str());
        }
        return is_right;
    }
    // !!! TO-DO
    // file must exists, or jump to create_file API
    int read_file(stdfs::path file_path) {
        if (has_file(file_path)) {
            FILE* fp = fopen(file_path.c_str(), "r");
            std::vector<char> buf(100);
            // if feof == 0, not reach the end of line
            size_t count = 0;
            size_t line = 1;
            auto not_reach_end_of_line = [&fp]() -> bool { 
                return feof(fp) == 0; 
            };
            while (not_reach_end_of_line() and line <= 2000) {
                count++;
                buf.resize(100 * count);
                printf("## already read/resize %zu times.\n", count);
                fread(&(buf[0]), sizeof buf[0], buf.size(), fp);
                if (not_reach_end_of_line()) {
                    for(char n : buf) {
                        if (n == '\n') {
                            printf("line [%zu] ", line++);
                        }
                        printf("%c", n);
                    }
                }
            }
            fclose(fp);
            return 0;
        } else
            return -1;
    }
    // not exists create, exists destory
    int write_file(stdfs::path file_path) {
        if (has_file(file_path)) {
            FILE* file_ptr = fopen(file_path.c_str(), "w+");
            const char email_addr[] = "cherrise28@outlook.com";
            const char email_passwd[] = "sz142857";
            // c_str to be written, element size, count, file_ptr
            fwrite(email_addr, sizeof email_addr[0], strnlen(email_addr, sizeof email_addr), file_ptr);
            fwrite(email_addr, sizeof email_addr[0], strnlen(email_addr, sizeof email_addr), file_ptr);

            // printf("sizeof email_addr[0]: %zu\n", sizeof email_addr[0]);
            // printf("strnlen(email_addr, sizeof email_addr): %zu\n", strnlen(email_addr, sizeof email_addr));

            fclose(file_ptr);
        }
        return -1;
    }

    // ######## public

    bool has_file(const char* file_path) {
        return has_file(stdfs::path(file_path));
    }
    int read_file(const char* file_path) {
        return read_file(stdfs::path(file_path));
    }
    int write_file(const char* file_path) {
        return write_file(stdfs::path(file_path));
    }



}