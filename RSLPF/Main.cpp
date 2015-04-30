#include "RSLPF.h"

int main(int argc, char* argv[])
{
	BMPImage* prova = new BMPImage("Samples/in.bmp");

	RGBPIXEL color = prova->getPixel(-1, 15);

	delete prova; // Non sono sicuro del funzionamento di questo comando.

	prova = new BMPImage(1024, 768, color);


	Sequence<float> seq;
	seq << 32.0f << 3.5;
	for (int i = 0; i < seq.getLength(); i++)
	{
		std::cout << seq[i] << " | ";
	}
//	prova->fromFile("Samples/in.bmp");

	prova->toFile("Samples/out.bmp");

	return(0);
}