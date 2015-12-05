
#define cimg_display 0
#include "openfile.h"
#include <unistd.h>
#include <cstdio>
#include <fstream>

int OpenFile::checkFileAccess()
{
	return (access(fileName.c_str(),read<<2|write<<1) != -1);
}

void OpenFile::readMode()
{
	if(mode & 4)
		read = 1;
	if(mode & 2)
		write = 1;
}

void OpenFile::openFileInCImg()
{
	image=CImg<unsigned char>(fileName.c_str());
}

int OpenFile::checkCreation()
{
	std::ofstream testFile(fileName.c_str());
	if(testFile.good()){
		testFile.close();
		return 1;
	}
	else
		return 0;
}

OpenFile::OpenFile(std::string fileNameOuter,int modeOuter):
	fileName(fileNameOuter),mode(modeOuter)
{
	read=0;
	write=0;
	readMode();
	if(checkFileAccess() && read) {
		openFileInCImg();
	} else if(!(checkCreation() && write)){
		printf("Can't open file write=%i read=%i\n",write,read);
	}
}

CImg<unsigned char> OpenFile::getImage()
{
	return image;
}

void OpenFile::setImage(CImg<unsigned char> imageOuter)
{
	image=imageOuter;
}

void OpenFile::uploadToFile()
{
	image.save(fileName.c_str());
}

