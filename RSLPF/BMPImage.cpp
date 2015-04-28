#include "BMPImage.h"

BMPImage::BMPImage() { 
	
	assert(sizeof(RGBPIXEL) == 3);

	this->data = nullptr;
	this->fileHeader = nullptr;
	this->infoHeader = nullptr;
}

BMPImage::BMPImage(const int32_t width, const int32_t height, const RGBPIXEL& color) {

	BMPImage();
	createHeaders(width, height);

	this->data = new RGBPIXEL[width * height];

	for (int64_t i = 0; i < width * height; i++)
		this->data[i] = color;
}

BMPImage::BMPImage(const char* fileName)
{
	BMPImage();
	this->fromFile(fileName);
}

void BMPImage::createHeaders(const char* buffer) {

	this->fileHeader = new BMPFILEHEADER;
	this->infoHeader = new BMPINFOHEADER;

	std::memcpy((void*) &this->fileHeader->type, &buffer[0], 2);
	std::memcpy((void*) &this->fileHeader->size, &buffer[2], 4);
	std::memcpy((void*) &this->fileHeader->reserved1, &buffer[6], 2);
	std::memcpy((void*) &this->fileHeader->reserved2, &buffer[8], 2);
	std::memcpy((void*) &this->fileHeader->offset, &buffer[10], 4);

	std::memcpy((void*) &this->infoHeader->headerSize, &buffer[14], 4);
	std::memcpy((void*) &this->infoHeader->width, &buffer[18], 4);
	std::memcpy((void*) &this->infoHeader->height, &buffer[22], 4);
	std::memcpy((void*) &this->infoHeader->planes, &buffer[26], 2);
	std::memcpy((void*) &this->infoHeader->bits, &buffer[28], 2);
	std::memcpy((void*) &this->infoHeader->compression, &buffer[30], 4);
	std::memcpy((void*) &this->infoHeader->imageSize, &buffer[34], 4);
	std::memcpy((void*) &this->infoHeader->xRes, &buffer[38], 4);
	std::memcpy((void*) &this->infoHeader->yRes, &buffer[42], 4);
	std::memcpy((void*) &this->infoHeader->clrUsed, &buffer[46], 4);
	std::memcpy((void*) &this->infoHeader->clrImportant, &buffer[50], 4);
}

void BMPImage::createHeaders(int32_t width, int32_t height, uint16_t bits, uint32_t compression) {

	this->fileHeader = new BMPFILEHEADER;
	this->infoHeader = new BMPINFOHEADER;

	this->fileHeader->type = BMPTYPE;								// Standard bitmap file.
	this->fileHeader->size = width * height * (bits / 8) + 54;
	this->fileHeader->reserved1 = 0;
	this->fileHeader->reserved2 = 0;
	this->fileHeader->offset = 54;

	this->infoHeader->headerSize = 40;
	this->infoHeader->width = width;
	this->infoHeader->height = height;
	this->infoHeader->planes = 1;
	this->infoHeader->bits = bits;
	this->infoHeader->compression = compression;
	this->infoHeader->imageSize = width * height * (bits / 8);
	this->infoHeader->xRes = 0;
	this->infoHeader->yRes = 0;
	this->infoHeader->clrUsed = 0;
	this->infoHeader->clrImportant = 0;								// All colors are important.
}

void BMPImage::headerToBuffer(char* buffer) {

	std::memcpy(&buffer[0], &this->fileHeader->type, 2);
	std::memcpy(&buffer[2], &this->fileHeader->size, 4);
	std::memcpy(&buffer[6], &this->fileHeader->reserved1, 2);
	std::memcpy(&buffer[8], &this->fileHeader->reserved2, 2);
	std::memcpy(&buffer[10], &this->fileHeader->offset, 4);

	std::memcpy(&buffer[14], &this->infoHeader->headerSize, 4);
	std::memcpy(&buffer[18], &this->infoHeader->width, 4);
	std::memcpy(&buffer[22], &this->infoHeader->height, 4);
	std::memcpy(&buffer[26], &this->infoHeader->planes, 2);
	std::memcpy(&buffer[28], &this->infoHeader->bits, 2);
	std::memcpy(&buffer[30], &this->infoHeader->compression, 4);
	std::memcpy(&buffer[34], &this->infoHeader->imageSize, 4);
	std::memcpy(&buffer[38], &this->infoHeader->xRes, 4);
	std::memcpy(&buffer[42], &this->infoHeader->yRes, 4);
	std::memcpy(&buffer[46], &this->infoHeader->clrUsed, 4);
	std::memcpy(&buffer[50], &this->infoHeader->clrImportant, 4);

}

bool BMPImage::fromFile(const char* fileName)
{
	std::ifstream file;

	file.open(fileName, std::fstream::in | std::fstream::binary);

	if (!file.good()) {
		std::cout << "Impossibile aprire il file per la lettura." << std::endl;
		return(false);
	}

	char* buffer = new char[54];
	file.read(buffer, 54);
	createHeaders(buffer);
	delete[] buffer;
	
	this->data = new RGBPIXEL[this->infoHeader->imageSize];
	file.read((char*) this->data, this->infoHeader->imageSize);

	file.close();

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

	char* buffer = new char[54];
	headerToBuffer(buffer);
	file.write(buffer, 54);
	delete[] buffer;

	file.write((char*) this->data, this->infoHeader->imageSize);

	file.close();
	
	return(true);
}

bool BMPImage::drawRectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const RGBPIXEL& color) {

	if (isValid(x1, y1) && isValid(x2, y2)) {

		// Disegna il rettangolo.


		return(true);
	}

	return(false);
}

bool BMPImage::isValid(int32_t x, int32_t y) {

	if (this->data == nullptr)
		return(false);

	if (x < 0 || x >= this->infoHeader->width || y < 0 || y >= this->infoHeader->height)
		return(false);

	return(true);
}