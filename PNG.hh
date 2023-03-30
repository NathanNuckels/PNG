#ifndef LIBPNG2_H
#define LIBPNG2_H
struct IHDR{
	uint32_t width;
	uint32_t height;
	uint8_t depth;
	uint8_t color;
	uint8_t interlace;
}

struct PLTE_ENTRY{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
}

struct IDAT{
}


int checkIHDR(struct IHDR hdr);
int checkPLTE(struct PLTE_ENTRY * plte,size_t length);
uint8_t * getIEND();

#endif
