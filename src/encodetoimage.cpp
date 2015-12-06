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
		printf("IN x:%d y:%d r:%d g:%d b:%d\n",i,j,image(i,j,0,0),
					 image(i,j,0,1),
					 image(i,j,0,2));
		for(int k=0;k<3;k++){
			oneChannelOfImg=image(i,j,k);
			for(int t=1;t>-1;t--){
				if(it==bitVecToEncode.end())
					break;
				oneChannelOfImg[t]=*it?1:0;
				++it;
			}
			printf("Set x:%d y:%d channel:%d to:%d\n",i,j,k,oneChannelOfImg.to_ulong());
			image(i,j,0,k)=(int)oneChannelOfImg.to_ulong();
			if(it==bitVecToEncode.end())
				break;
		}
		printf("OUT r:%d g:%d b:%d\n",image(i,j,0,0),
					 image(i,j,0,1),
					 image(i,j,0,2));

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
	uploadVectorToImage();
	return image;
}

