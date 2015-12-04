#include <iostream>

#define cimg_display 0
#include "CImg.h"
#include "options.h"

using namespace std;
using namespace cimg_library;

int main(int argc,char **argv)
{
	Options startupCmdOptions(argc,argv);
	if(startupCmdOptions.isEncode()){

	}
	else if(startupCmdOptions.isDecode()){

	}
//	CImg<unsigned char> image(argv[1]);
//	cout << "Hello World!" << endl;
	return 0;
}

