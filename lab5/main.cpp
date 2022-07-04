#include <iostream>

// This is so we can use functions from geometry.h
#include <geometry.h>

using namespace std;

// We will be reading command line parameters
int main(int argc, char* argv[]) {

    if (argc != 7) {
        // We have to have exactly 7 parameters, if we don't we display the "usage" message
        cout << "Usage: ./inside <x> <y> <rx> <ry> <rw> <rh>" << endl;
        cout << "Parameters" << endl;
        cout << "  <x>\t\tx-coordinate of the point of interest" << endl;
        cout << "  <y>\t\ty-coordinate of the point of interest" << endl;
        cout << "  <rx>\t\tx-coordinate of the top-left point of the rectangle" << endl;
        cout << "  <ry>\t\ty-coordinate of the top-left point of the rectangle" << endl;
        cout << "  <rw>\t\twidth of the rectangle" << endl;
        cout << "  <rw>\t\theight of the rectangle" << endl;
        return 1;
    }

    // Float variables to hold the values the user enters are command line parameters
    float x, y, rx, ry, rw, rh;

    // We try to convert the values from argv to floats.
    // That can break if the user entered something that's not convertible to a float
    // For example the string "hello" is not convertible to a float,
    // Whereas the string "3.14159" is.
    try {
        x = stof(argv[1]);
        y = stof(argv[2]);
        rx = stof(argv[3]);
        ry = stof(argv[4]);
        rw = stof(argv[5]);
        rh = stof(argv[6]);
    }
    catch (...) {
        // If there was an error in the "try" code block above, we catch it here
        // Catching the error prevents the program from crashing 
        // In other words, it allows it to continue to run. It will run whatever code
        // we have here in the "catch" block.
        // We simply print print out an error message, and exit with 1. 
        // This is called exiting gracefully. We should always exit gracefully
        // and not as a result of a crash.

        cerr << "Error: Could not parse the parameters provided" << endl;
        
        // cerr looks identical to cout, but it produces its output to the error steam in the terminal
        // cout goes to the output stream.
        // Both streams appear as text on the terminal, but they are separate streams because that
        // makes it possible to watch them separately. For example, we can forward just the error stream to a file,
        // so we can see logs of the errors we encountered. 

        return 1;
    }

    // It we made it to this point in the code (we have not exited with code 1)
    // it means that we have received our inputs correctly and we can safely call the function

    if (pointInRect(x, y, rx, ry, rw, rh)) {
        cout << "INSIDE" << endl;
    }
    else {
        cout << "OUTSIDE" << endl;
    }
    
    return 0;
}