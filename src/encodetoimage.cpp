#define cimg_display 0
#include "encodetoimage.h"

EncodeToImage::EncodeToImage()
{

}

void EncodeToImage::setImage(CImg<unsigned char> imageOuter)
{
	image=imageOuter;
}

void EncodeToImage::setTextToEncode(std::string textOuter)
{
	textToEncode=textOuter;
}

CImg<unsigned char> EncodeToImage::getImageWithEncodedText()
{
	return image;
}

