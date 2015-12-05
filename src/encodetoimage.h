#ifndef ENCODETOIMAGE_H
#define ENCODETOIMAGE_H

#include <string>
#include "CImg.h"
#include <vector>
#include <stdint.h>

using namespace cimg_library;

class EncodeToImage
{
	CImg<unsigned char> image;
	std::string textToEncode;
	std::vector<bool> bitVecToEncode;
	uint16_t textLenght;
	int countLenght();
	void encodeText();
	void encodeSize();
public:
	EncodeToImage();
	void setImage(CImg<unsigned char>);
	void setTextToEncode(std::string);
	CImg<unsigned char> getImageWithEncodedText();
};

#endif // ENCODETOIMAGE_H
