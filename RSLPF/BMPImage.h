#ifndef __BMPIMAGE_H__
#define __BMPIMAGE_H__

#include "STDHeader.h"

#include <iostream>
#include <fstream>
#include <cassert>

#define BMPTYPE 19778
#define RGB_LOSSLESS 0

typedef struct {
	uint16	type;				// BMP identifier.
	uint32	size;				// Total dimension of file.
	uint16	reserved1;			// Reserved.
	uint16	reserved2;			// Reserved.
	uint32	offset;				// Bytes before image data.
} BMPFILEHEADER;

typedef struct {
	uint32	headerSize;			// Header size in bytes.
	int32	width;				// Image width.
	int32	height;				// Image height;
	uint16	planes;				// Number of colour planes.
	uint16	bits;				// Bits per pixel.
	uint32	compression;		// Compression type.
	uint32	imageSize;			// Image size in bytes.
	int32	xRes;				// X Pixel per meter.
	int32	yRes;				// Y Pixel per meter.
	uint32	clrUsed;			// Number of colours.
	uint32	clrImportant;		// Important colours.
} BMPINFOHEADER;

typedef struct {
	uint8	B;
	uint8	R;
	uint8	G;
} RGBPIXEL;

class BMPImage {

private:
	BMPFILEHEADER*	fileHeader;
	BMPINFOHEADER*	infoHeader;
	RGBPIXEL*		data;

	void createHeaders(const char* buffer);
	void createHeaders(int32 width, int32 height, uint16 bits = 24, uint32 compression = RGB_LOSSLESS);
	void headerToBuffer(char* dest);
	void setRow(const int32 x, const int32 y, const int32 length, const RGBPIXEL& color);
	bool isValid(int32 x, int32 y);

public:
	BMPImage();
	BMPImage(const int32 width, const int32 height, const RGBPIXEL& color);
	BMPImage(const char* fileName);
	~BMPImage();

	bool fromFile(const char* fileName);
	bool toFile(const char* fileName);

	RGBPIXEL getPixel(const int32 x, const int32 y);
	bool setPixel(const int32 x, const int32 y, const RGBPIXEL& color);

	void Clear(const RGBPIXEL& color);
	void Clear();		//clear black

	bool drawRectangle(int32 x1, int32 y1, int32 x2, int32 y2, const RGBPIXEL& color);

	void negative();
	void binarize(const uint8 threshold = 127);
	// TODOs.
	/*	
	void drawLine(const int x0, const int y0, const  int x1, const  int y1, const RGBcol color);  //const int invece di unsigned int per permettere di iniziare le righe anche fuori dall'immagine 
	
	void contrastEmphasis(const unsigned char min, const unsigned char max);
	void binarize(const unsigned char threshold);
	void toGrayscale();
	void transpose();
	*/
};

#endif // __BMPIMAGE_H__