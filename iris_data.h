#ifndef GUARD_iris_data
#define GUARD_iris_data

#include <iostream>
#include <string>
#include <vector>




/* Defines the struct for the iris data to be read in */

struct Iris_data{
    std::string name;
    double start_time;      //Start time in seconds (0.0 would be right when the stream opens
    double duration;        //How long that tone lasts for
                            //NOTE: ALL TONES LAST ONE SECOND, BUT SOME GO QUIET SOONER THAN OTHERS
    double sepal_length;
    double sepal_width;
    double petal_length;
    double petal_width;
};

enum SpacingMode { SEQUENTIAL, OVERLAID, R_OVERLAID };

/* Declaration for the read method. */
std::vector<Iris_data> normalizeIris(std::vector<Iris_data>, Iris_data);
void datafileRead(std::string filen, std::vector<Iris_data>& instances, int& nRead, Iris_data& max);
Iris_data maxIris(std::vector<Iris_data>);
void print_iris(const Iris_data&);
void generateTime(std::vector<Iris_data>&, int, SpacingMode, double maxDur);
#endif
