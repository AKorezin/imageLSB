#include "decodefromimage.h"
#include <bitset>

void DecodeFromImage::decodeSize()
{
	std::bitset<8> oneChannelOfImg;
	textLenght=0;
	for(int size=2; (size<=16) && (y<image.height());size+=2){
		oneChannelOfImg=image(x,y,channel);
		textLenght|=(oneChannelOfImg[1]<<16-size+1);
		textLenght|=(oneChannelOfImg[0]<<16-size);
		channel++;
		if(channel==3) {
			x++;
			channel=0;
		}
		if(x==image.width()){
			y++;
			x=0;
		}
	}
	textLenght*=8;
}

void DecodeFromImage::decodeText()
{
	std::bitset<8> oneChannelOfImg;
	for(int i=0;i<textLenght  && (y<image.height());i+=2){
		oneChannelOfImg=image(x,y,channel);
		bitVecDecoded.push_back(oneChannelOfImg[1]);
		bitVecDecoded.push_back(oneChannelOfImg[0]);
		channel++;
		if(channel==3) {
			x++;
			channel=0;
		}
		if(x==image.width()){
			y++;
			x=0;
		}
	}
}

void DecodeFromImage::bitVecToChar()
{
	char c;
	std::vector<bool>::iterator it;
	int i;
	for(it=bitVecDecoded.begin(),c=0,i=0;it<bitVecDecoded.end();it++,i++){
		c|=(*it?1:0);
		if(i%8==7){
			textFromImage.push_back(c);
			c=0;
		}
		c=c<<1;
	}
}

DecodeFromImage::DecodeFromImage()
{
	x=0;
	y=0;
	channel=0;
}

void DecodeFromImage::setImage(CImg<unsigned char> imageOuter)
{
	image=imageOuter;
}

std::string DecodeFromImage::getDecodeResult()
{
	decodeSize();
	decodeText();
	bitVecToChar();
	return textFromImage;
}

