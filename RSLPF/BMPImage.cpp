#include "BMPImage.h"

BMPImage::BMPImage() { this->data = nullptr; this->fileHeader = nullptr; this->infoHeader = nullptr; }

BMPImage::BMPImage(const uint32_t width, const uint32_t height, const RGBPIXEL* color) {

	createHeaders(width, height);

	this->data = new RGBPIXEL[width * height];

	for (uint32_t i = 0; i < width * height; i++)
		data[i] = *color;
}

void BMPImage::createHeaders(int32_t width, int32_t height, uint16_t bits, uint32_t compression) {
	
	static BMPFILEHEADER fileHeader;
	static BMPINFOHEADER infoHeader;

	fileHeader.type = BMPTYPE;								// Standard bitmap file.
	fileHeader.size = width * height / (bits / 3) + 54;
	fileHeader.reserved1 = 0;
	fileHeader.reserved2 = 0;
	fileHeader.offset = 54;

	infoHeader.headerSize = 40;
	infoHeader.width = width;
	infoHeader.height = height;
	infoHeader.planes = 1;
	infoHeader.bits = bits;
	infoHeader.compression = compression;
	infoHeader.imageSize = width * height / (bits / 3);
	infoHeader.xRes = 0;
	infoHeader.yRes = 0;
	infoHeader.clrUsed = 0;
	infoHeader.clrImportant = 0;							// All colors are important.

	this->fileHeader = &fileHeader;
	this->infoHeader = &infoHeader;
}

bool BMPImage::fromFile(const char* fileName)
{
	std::ifstream file;

	file.open(fileName, std::fstream::in | std::fstream::binary);

	if (!file.good()) {
		std::cout << "Impossibile aprire il file per la lettura." << std::endl;
		return(false);
	}

	file.seekg(0, file.end);
	uint32_t length = (uint32_t) file.tellg();
	file.seekg(0, file.beg);

	char* buffer = new char[length];

	file.read(buffer, length);

	this->fileHeader = (BMPFILEHEADER*) &buffer[0];
	this->infoHeader = (BMPINFOHEADER*) &buffer[14];
	this->data = (RGBPIXEL*) &buffer[40];

	file.close();

	(*fileHeader).size = length;

	return(true);
}

bool BMPImage::toFile(const char* fileName)
{
	std::ofstream file;

	file.open(fileName, std::fstream::out | std::fstream::binary);

	if (!file.good()) {
		std::cout << "Impossibile aprire il file per la scrittura." << std::endl;
		return(false);
	}

	file.write((char*) this->fileHeader, 14);
	file.write((char*) this->infoHeader, 40);
	file.write((char*) this->data, (*infoHeader).imageSize);

	file.close();

	return(true);
}
