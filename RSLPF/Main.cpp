#include "RSLPF.h"

int main(int argc, char* argv[])
{

	RGBPIXEL color;

	color.B = 0;
	color.R = 255;
	color.G = 0;

	BMPImage* prova = new BMPImage("out.bmp");

//	BMPImage* prova = new BMPImage();

//	prova->fromFile("Samples/in.bmp");

	prova->toFile("asd.bmp");

	return(0);
}