#include <iostream>
#include <boost/program_options.hpp>

#include "lib.h"

int main() {
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message");
    std::cout << desc << std::endl;
}
