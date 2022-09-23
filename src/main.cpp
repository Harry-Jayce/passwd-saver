#include <iostream>
// #include <format>
#include "harry_fs.h"

int main()
{
    std::cout << "hello world\n";
    // harry::fs::test1();

    printf("## harry_fs test:\n");
    // harry::fs::has_file("/home/harry/repo/try-modern-cmake/examples/testground/hello.txt");
    auto hello = "./testground/hello.txt";
    // harry::fs::read_file(hello);

    auto file_to_be_written = "./testground/keep-data/databox";
    harry::fs::write_file(file_to_be_written);



}
