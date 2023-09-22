#include <iostream>
#include <fmt/core.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

/**
 * This function opens a file specified by the filename argument,
 * and counts the number of lines in said file
 */
int count_lines(const std::string & filename) {
    std::ifstream in(filename);
    in.unsetf(std::ios::skipws);

    // We are creating an iterator over the input stream and
    // passing it to the count algorithm to count the number
    // of newline characters
    return std::count(
            std::istream_iterator<char>(in),
            std::istream_iterator<char>(),
            '\n'
    );
}

/**
 * Given a list of files, this function returns a list of
 * line counts for each of them
 */
std::vector<int> count_lines_in_files(const std::vector<std::string> & files) {
    std::vector<int> results;

    results.reserve(files.size());
    for ( const auto & file : files )
        results.emplace_back(count_lines(file));

    return results;
}

int main() {
    // Due to the fact that the file exists in the build
    // during execution and is not at the same level
    // as main.cpp CMakeLists.txt
    // use makefile {"main.cpp", "CMakeLists.txt"}
    auto results = count_lines_in_files({"../main.cpp", "../CMakeLists.txt"});

    for (auto result : results)
        fmt::print("{} lines\n", result);

    return 0;
}
