#define cimg_display 0
#include "decodefromimage.h"

DecodeFromImage::DecodeFromImage()
{

}

void DecodeFromImage::setImage(CImg<unsigned char> imageOuter)
{
	image=imageOuter;
}

std::string DecodeFromImage::getDecodeResult()
{
	return textFromImage;
}
