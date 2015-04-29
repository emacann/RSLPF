#include <iostream>
#include <fstream>
#include <cstdint>
#include <assert.h>

#define BMPTYPE 19778
#define RGB_LOSSLESS 0

typedef struct {
	uint16_t type;					// BMP identifier.
	uint32_t size;					// Total dimension of file.
	uint16_t reserved1;				// Reserved.
	uint16_t reserved2;				// Reserved.
	uint32_t offset;				// Bytes before image data.
} BMPFILEHEADER;

typedef struct {
	uint32_t headerSize;			// Header size in bytes.
	int32_t width;					// Image width.
	int32_t height;					// Image height;
	uint16_t planes;				// Number of colour planes.
	uint16_t bits;					// Bits per pixel.
	uint32_t compression;			// Compression type.
	uint32_t imageSize;				// Image size in bytes.
	int32_t xRes;					// X Pixel per meter.
	int32_t yRes;					// Y Pixel per meter.
	uint32_t clrUsed;				// Number of colours.
	uint32_t clrImportant;			// Important colours.
} BMPINFOHEADER;

typedef struct {
	uint8_t B;
	uint8_t G;
	uint8_t R;
} RGBPIXEL;

class BMPImage {

private:
	BMPFILEHEADER* fileHeader;
	BMPINFOHEADER* infoHeader;
	RGBPIXEL* data;

	void createHeaders(const char* buffer);
	void createHeaders(int32_t width, int32_t height, uint16_t bits = 24, uint32_t compression = RGB_LOSSLESS);
	void headerToBuffer(char* dest);
	void setRow(const int32_t x, const int32_t y, const int32_t length, const RGBPIXEL& color);
	bool isValid(int32_t x, int32_t y);

public:
	BMPImage();
	BMPImage(const int32_t width, const int32_t height, const RGBPIXEL& color);
	BMPImage(const char* fileName);
	~BMPImage();

	bool fromFile(const char* fileName);
	bool toFile(const char* fileName);

	RGBPIXEL getPixel(const int32_t x, const int32_t y);
	bool setPixel(const int32_t x, const int32_t y, const RGBPIXEL& color);

	void Clear(const RGBPIXEL& color);
	void Clear();		//clear black

	bool drawRectangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const RGBPIXEL& color);
	// TODOs.
	/*	
	void drawLine(const int x0, const int y0, const  int x1, const  int y1, const RGBcol color);  //const int invece di unsigned int per permettere di iniziare le righe anche fuori dall'immagine 
	void negative();
	void contrastEmphasis(const unsigned char min, const unsigned char max);
	void binarize(const unsigned char threshold);
	void toGrayscale();
	void transpose();
	*/
};