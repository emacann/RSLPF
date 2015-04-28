#include "RSLPF.h"

int main(int argc, char* argv[])
{
	RGBPIXEL color;

	color.B = 0;
	color.R = 0;
	color.G = 0;

	// BMPImage* prova = new BMPImage(1024, 768, &color);

	BMPImage* prova = new BMPImage();

	(*prova).fromFile("Samples/in.bmp");

	(*prova).toFile("Samples/out.bmp");

	return(0);
}