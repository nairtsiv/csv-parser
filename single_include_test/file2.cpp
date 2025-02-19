#include "my_header.hpp"
#include <set>

using namespace std;

int main(int argc, char** argv) {
    using namespace csv;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [file]" << std::endl;
        exit(1);
    }

    std::string filename = argv[1];
    CSVStat stats(filename);

//    auto col_names = stats.get_col_names();
//    auto min = stats.get_mins(), max = stats.get_maxes(),
//        means = stats.get_mean(), vars = stats.get_variance();
//
//    for (size_t i = 0; i < col_names.size(); i++) {
//        std::cout << col_names[i] << std::endl
//            << "Min: " << min[i] << std::endl
//            << "Max: " << max[i] << std::endl
//            << "Mean: " << means[i] << std::endl
//            << "Var: " << vars[i] << std::endl;
//    }

    set<int> lines {0,1,2,3,57,58,128, 226};

    CSVFormat format;
    format.no_header();
    format.delimiter(',');
    CSVReader reader(filename, format);
    for (auto &line: lines) {
        CSVRow row;
        if (reader.fetch_row(row, line)) {
            std::cout << "Row " << line << ": " << row[0].get() << row[1].get() << std::endl;
        }
    }


    return 0;
}