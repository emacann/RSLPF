#include <iostream>
#include <fstream>
#include <cstdint>

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
	uint32_t width;					// Image width.
	uint32_t height;				// Image height;
	uint16_t planes;				// Number of colour planes.
	uint16_t bits;					// Bits per pixel.
	uint32_t compression;			// Compression type.
	uint32_t imageSize;				// Image size in bytes.
	uint32_t xRes;					// X Pixel per meter.
	uint32_t yRes;					// Y Pixel per meter.
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

	void createHeaders(uint32_t width, uint32_t height, uint16_t bits = 24, uint32_t compression = RGB_LOSSLESS);
public:
	BMPImage();
	BMPImage(const uint32_t width, const uint32_t height, const RGBPIXEL* color);

	bool fromFile(const char* fileName);
	bool toFile(const char* fileName);
	
	// TODOs.
	/*
	
	void set(const unsigned int x, const unsigned int y, const RGBcol color); //unsigned int per evitare check inutili
	RGBcol get(const unsigned int x, const unsigned int y);
	void Clear(const RGBcol color);
	void Clear(); //clear black
	void drawLine(const int x0, const int y0, const  int x1, const  int y1, const RGBcol color);  //const int invece di unsigned int per permettere di iniziare le righe anche fuori dall'immagine 
	void negative();
	void contrastEmphasis(const unsigned char min, const unsigned char max);
	void binarize(const unsigned char threshold);
	void toGrayscale();
	void transpose();
	*/
};