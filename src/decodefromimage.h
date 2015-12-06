#ifndef DECODEFROMIMAGE_H
#define DECODEFROMIMAGE_H

#include <string>
#include "CImg.h"
#include <vector>
#include <stdint.h>

using namespace cimg_library;

class DecodeFromImage
{
private:
	std::string textFromImage;
	CImg<unsigned char> image;
	std::vector<bool> bitVecDecoded;
	uint16_t textLenght;
	int x,y,channel;
	void decodeSize();
	void decodeText();
	void bitVecToChar();
public:
	DecodeFromImage();
	void setImage(CImg<unsigned char>);
	std::string getDecodeResult();
};

#endif // DECODEFROMIMAGE_H
