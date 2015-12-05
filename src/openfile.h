#ifndef OPENFILE_H
#define OPENFILE_H

#include <string>
#include "CImg.h"

using namespace cimg_library;

class OpenFile
{
private:
	int mode,read,write;
	std::string fileName;
	CImg<unsigned char> image;
	int checkFileAccess();
	void readMode();
	void openFileInCImg();
	int checkCreation();
public:
	OpenFile(std::string,int);
	CImg<unsigned char> getImage();
	void setImage(CImg<unsigned char>);
	void uploadToFile();
};

#endif // OPENFILE_H
