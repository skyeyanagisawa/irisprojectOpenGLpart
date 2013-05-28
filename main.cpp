/* 
    TODO: Add in the graphics
    TODO: Generate time values for each point
    TODO: Generate audio 
*/

#include <ios>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include <stdlib.h>

/*
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
*/

//#include "portaudio.h"
#include "iris_data.h"
//#include "audio_engine.h"
#include "graphLoop.h"

using std::cin;         using std::setprecision;
using std::cout;        using std::sort;
using std::domain_error;using std::streamsize;
using std::endl;        using std::string;
using std::max;         using std::vector;

void test_data_read(vector<Iris_data> data);

int main(int argc, char* argv[]){

	float onevalue = 1.0;
    string filename;
    if(argc == 1 || argc > 2){
        cout << "Usage: " << "./main " << "filename.extention" << endl;
        cout << "Note! Only works with space delimited text files at the moment" << endl;
        cout << "Enter Filename: " ;
        cin >> filename;
    } else {
       filename = argv[1]; 
    }

    //Audio_PlayBack_Data PlaybackData = {0};
    //float *playbackBuffer;
    SpacingMode timeMode = SEQUENTIAL;

    vector<Iris_data> iris; //Data structure for our data (similar to arraylist)
    vector<Iris_data> normIris; //Our data post normalization.
    Iris_data max;          //Holds the largest value for each member of Iris_data

    int nInstances;         //The number of instances read

    /*
       reads in file, counts instances, gives the "max" of each attribute back as
       a single instance with those maximum values
    */

    datafileRead(filename, iris, nInstances, max);
    //cout << "read "<< nInstances << " instances." << endl;

    //generateTime(iris, nInstances, timeMode, MAX_TONEDUR);

    //Normalize the data
    normIris = normalizeIris(iris, max);

    //Initialize the audio mix buffer
    //init_buffer(nInstances, PlaybackData); 

    //TODO: Generate Audio Buffer

    //cout << "Generating audio, this could take a while" << endl;
    //fillBuffer(normIris);

    //playbackBuffer = buffer_to_float();
    //PlaybackData.mix = playbackBuffer;
    //PlaybackData.mixEnd= playbackBuffer + PlaybackData.samples;

    //Open audio stream
    //init_audioStream(&PlaybackData);

    //TODO: Open graphics stream

	graphLoop(argc, argv, normIris);

   // glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(400, 400);
	
	//Create the window
//	glutCreateWindow("Transformations and Timers - videotutorialsrock.com");
	//initRendering();
	
	//Set handler functions
//	glutDisplayFunc(drawScene);
//	glutKeyboardFunc(handleKeypress);
//	glutReshapeFunc(handleResize);
	
//	glutTimerFunc(25, update, 0); //Add a timer
	
//	glutMainLoop();

    //terminate_audio();
    //free(playbackBuffer);
	test_data_read(iris);
    return 1;
}

//Prints out every single instace to make sure we didn't just read garbage
//Just a print statement for now
void test_data_read(vector<Iris_data> data){
    for(vector<Iris_data>::iterator i = data.begin();
            i != data.end(); i++){
        print_iris((*i));
    }
}
