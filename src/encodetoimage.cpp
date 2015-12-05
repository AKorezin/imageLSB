#define cimg_display 0
#include "encodetoimage.h"
#include <bitset>


int EncodeToImage::countLenght()
{
	textLenght=textToEncode.length();
}

void EncodeToImage::encodeText()
{
	for(int i=0;i<textLenght;i++)
		for (int bi=7;bi>=0;bi--)
			bitVecToEncode.push_back(textToEncode[i]&(1<<bi)? 1 : 0);
}

void EncodeToImage::encodeSize()
{
	countLenght();
	for (int bi=15;bi>=0;bi--)
		bitVecToEncode.push_back(textLenght&(1<<bi)? 1 : 0);
}

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
	encodeSize();
	encodeText();
	int i;
	std::vector<bool>::iterator it;
	for (it=bitVecToEncode.begin(),i=0; it!=bitVecToEncode.end(); ++it,i++)
	{
		printf("%d",*it?1:0);
		if(i%8==7){
			printf(" ");
		}
	}
	printf("\n");
	return image;
}

