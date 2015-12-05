#ifndef DECODEFROMIMAGE_H
#define DECODEFROMIMAGE_H

#include <string>
#include "CImg.h"

using namespace cimg_library;

class DecodeFromImage
{
private:
	std::string textFromImage;
	CImg<unsigned char> image;
public:
	DecodeFromImage();
	void setImage(CImg<unsigned char>);
	std::string getDecodeResult();
};

#endif // DECODEFROMIMAGE_H
