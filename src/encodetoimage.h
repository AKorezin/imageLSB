#ifndef ENCODETOIMAGE_H
#define ENCODETOIMAGE_H

#include <string>
#include "CImg.h"

using namespace cimg_library;

class EncodeToImage
{
	CImg<unsigned char> image;
	std::string textToEncode;
public:
	EncodeToImage();
	void setImage(CImg<unsigned char>);
	void setTextToEncode(std::string);
	CImg<unsigned char> getImageWithEncodedText();
};

#endif // ENCODETOIMAGE_H
