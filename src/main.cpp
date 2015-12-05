#define cimg_display 0
#include <iostream>
#include "options.h"
#include "openfile.h"
#include "CImg.h"
#include "encodetoimage.h"
#include "decodefromimage.h"

using namespace cimg_library;

int main(int argc,char **argv)
{
	Options startupCmdOptions(argc,argv);
	std::string inputFileName=startupCmdOptions.getInputFile();
	OpenFile inputFile(inputFileName,4);
	CImg<unsigned char> image=inputFile.getImage();
	if(startupCmdOptions.isEncode()){
		std::string outputFileName=startupCmdOptions.getOutputFile();
		std::string inputText=startupCmdOptions.getInputText();
		EncodeToImage inputImage;
		inputImage.setImage(image);
		inputImage.setTextToEncode(inputText);
		image=inputImage.getImageWithEncodedText();
		OpenFile outputFile(outputFileName,2);
		outputFile.setImage(image);
		outputFile.uploadToFile();
	}
	else if(startupCmdOptions.isDecode()){
		DecodeFromImage inputImage;
		inputImage.setImage(image);
		std::string ouputText=inputImage.getDecodeResult();
	}
//	CImg<unsigned char> image(argv[1]);
//	cout << "Hello World!" << endl;
	return 0;
}

