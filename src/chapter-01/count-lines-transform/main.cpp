#include <iostream>
#include <fmt/core.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <cstdio>
#include <direct.h>

/**
 * This function opens a file specified by the filename argument,
 * and counts the number of lines in said file
 */
int count_lines(const std::string & filename) {
    std::ifstream in(filename);

    // We are creating an iterator over the input stream and
    // passing it to the count algorithm to count the number
    // of newline characters
    return std::count(
            std::istream_iterator<char>(in >> std::noskipws),
            std::istream_iterator<char>(),
            '\n');
}

/**
 * Given a list of files, this function returns a list of
 * line counts for each of them
 */
/**
 * Given a list of files, this function returns a list of
 * line counts for each of them
 */
std::vector<int>
count_lines_in_files(const std::vector<std::string> & files) {
    // Since we know the size of the resulting vector, we can
    // preallocate the needed number of elements
    std::vector<int> results(files.size());

    // Instead of using the raw for loop like in the count-lines-stdcount
    // example, we are using the std::transform algorithm to
    // convert the list of file names into a list of line counts
    std::transform(files.cbegin(), files.cend(),
                   results.begin(),
                   count_lines);

    return results;
}

int main() {
    // Due to the fact that the file exists in the build
    // during execution and is not at the same level
    // as main.cpp CMakeLists.txt
    auto results = count_lines_in_files({ "../main.cpp", "../CMakeLists.txt" });

    for ( auto result : results )
        fmt::print("{} lines\n", result);

    return 0;
}
