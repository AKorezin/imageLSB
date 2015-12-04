#include <iostream>

#define cimg_display 0
#include "CImg.h"

using namespace std;
using namespace cimg_library;

int main(int argc,char **argv)
{

	CImg<unsigned char> image(argv[1]);
	cout << "Hello World!" << endl;
	return 0;
}

