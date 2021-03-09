/*
===============================================================
>Submission 1.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>snowman-a  
>Snowman Structur :

 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

ARGS STRUCTUR : HNLRXYTB
================================================================
*/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;

struct ReporterCounter: public ConsoleReporter {
    ReporterCounter(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            std::cout << 100 << std::endl;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl << 0  << std::endl;
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter);

int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
}
