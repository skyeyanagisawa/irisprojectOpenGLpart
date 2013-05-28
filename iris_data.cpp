#include "iris_data.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;    using std::endl;
using std::istream; using std::vector;
using std::ifstream;using std::setprecision;

// Code for functions delcared in iris_data.h
// SepalLength, SepalWidth, PetalLength, PetalWidth, Class

//The way this read is set up it requires the data to be delimited with spaces
// cin >> variable stops at space

void datafileRead(std::string filen, std::vector<Iris_data>& instances, int& nRead, Iris_data& dataMax){
    Iris_data iris;
    const char *c_strfilename = filen.c_str();
    ifstream file (c_strfilename);
    if(file.is_open()){
        nRead = 0;

        dataMax.sepal_length = 0;
        dataMax.sepal_width  = 0;
        dataMax.petal_length = 0;
        dataMax.petal_width  = 0;

        while(file.good()){
            file >> iris.sepal_length >> iris.sepal_width;
            file >> iris.petal_length >> iris.petal_width;
            file >> iris.name;

            if(iris.sepal_length > dataMax.sepal_length)
                dataMax.sepal_length = iris.sepal_length;
            if(iris.sepal_width > dataMax.sepal_width)
                dataMax.sepal_width = iris.sepal_width;
            if(iris.petal_length > dataMax.petal_length)
                dataMax.petal_length = iris.petal_length;
            if(iris.petal_width > dataMax.petal_width)
                dataMax.petal_width = iris.petal_width;

            instances.push_back(iris);
            nRead++;

        }
        file.close();
    } else {
        exit(EXIT_FAILURE);
    }
}

void print_iris(const Iris_data& iris){
    cout << "Class" << iris.name;
    cout << " Sepal Length: " << iris.sepal_length;
    cout << " Sepal Width: " << iris.sepal_width;
    cout << " Sepal Petal Width: " << iris.petal_width;
    cout << " Sepal Petal Length: "<< iris.petal_length;
    cout << " Start Time: " << iris.start_time ;
    cout << " Duration: " << iris.duration << endl;
}

std::vector<Iris_data> normalizeIris(std::vector<Iris_data> vec, Iris_data dataMax){
    vector<Iris_data> ret;
    vector<Iris_data>::iterator it = vec.begin();
    Iris_data temp;

    while(it != vec.end()){
        temp.sepal_length = it->sepal_length / dataMax.sepal_length;
        temp.petal_length = it->petal_length / dataMax.petal_length;
        temp.sepal_width = it->sepal_width / dataMax.sepal_width;
        temp.petal_width = it->petal_width / dataMax.petal_width;
        temp.name = it->name;
        temp.start_time = it->start_time;
        temp.duration = it->duration;
        ret.push_back(temp);
        it++;
    }
    return ret;
}

void generateTime(std::vector<Iris_data>& iris, int nInstancea, SpacingMode mode, double maxDur){
    vector<Iris_data>::iterator it = iris.begin();
    if(mode == SEQUENTIAL){
        int n = 0;
        while(it != iris.end()){
            it->start_time = n * maxDur;
            it->duration = maxDur;
            it++;
            n++;
        }
    }
}
