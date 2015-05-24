#include "RSLPF.h"
#include "BMPImage.h"

int main(int argc, char* argv[])
{
	BMPImage* prova = new BMPImage("Samples/in.bmp");

/*	Sequence<float> seq;
	seq << 32.0f << 3.5;
	for (int i = 0; i < seq.getLength(); i++)
	{
		std::cout << seq[i] << " | ";
	}
*/
	prova->fromFile("Samples/pls.bmp");

	prova->negative();

	prova->toFile("Samples/out.bmp");

	return(0);
}