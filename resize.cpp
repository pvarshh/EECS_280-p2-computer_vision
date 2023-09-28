#include <iostream>
#include <string>
#include <climits>
#include <fstream>
#include "processing.hpp"
#include "Image.hpp"
#include "Matrix.hpp"

using namespace std;


int main(int argc, char *argv[]) {
    if (argc > 5 || argc < 4) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }

    string inName = argv[1];
    string outName = argv[2];
    int width = atoi(argv[3]);
    int height = INT_MIN;
    if (argc == 5) {
        height = atoi(argv[4]);
    }

    Image *img = new Image();
    ifstream fin(inName);
    ofstream fout(outName);

    if ( !fin.is_open() ) {
        cout << "Unable to open " << inName << endl;
        return 1;
    }

    if ( !fout.is_open() ) {
        cout << "Unable to open " << outName << endl;
        return 1;
    }

    Image_init(img, fin);

    if (width < 0 || width > Image_width(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    
    if (height > INT_MIN) {
        if (height < 0 || height > Image_height(img)) {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                 << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        }
        seam_carve(img, width, height);
    }
    else {
        seam_carve_width(img, width);
    }

    Image_print(img, fout);

    delete img;
    fin.close();
    fout.close();
    
    return 0;

}