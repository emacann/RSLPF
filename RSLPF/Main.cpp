#include "RSLPF.h"

int main(int argc, char* argv[])
{

	RGBPIXEL color;

	color.B = 0;
	color.R = 255;
	color.G = 0;

//	BMPImage* prova = new BMPImage("Samples/in.bmp");

	BMPImage* prova = new BMPImage(1024, 768, color);

	prova->fromFile("Samples/in.bmp");

	prova->toFile("Samples/out.bmp");

	return(0);
}