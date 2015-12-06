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

void EncodeToImage::uploadVectorToImage()
{
	std::bitset<8> oneChannelOfImg;
	std::vector<bool>::iterator it=bitVecToEncode.begin();
	cimg_forXY(image,i,j) {
		if(it==bitVecToEncode.end())
			break;
		for(int k=0;k<3;k++){
			oneChannelOfImg=image(i,j,k);
			for(int t=1;t>-1;t--){
				if(it==bitVecToEncode.end())
					break;
				oneChannelOfImg[t]=*it?1:0;
				++it;
			}
			image(i,j,0,k)=(int)oneChannelOfImg.to_ulong();
			if(it==bitVecToEncode.end())
				break;
		}
	}
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
	uploadVectorToImage();
	return image;
}

