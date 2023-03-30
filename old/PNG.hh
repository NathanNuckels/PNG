#ifndef PNGHH
#define PNGHH
namespace PNG{
	class Block{
	protected:
		uint32_t length;
		uint32_t type;
		uint8_t * data;
		uint32_t crc;
	public:
		Block(int length,char * type);
		void setData(int len,void * newdata);
		uint8_t * getData();
		uint32_t getLength();
		size_t getRawLength();
		uint8_t * getRaw();
	}
	
	class IHDR{
	protected:
		uint32_t width;
		uint32_t height;
		uint8_t color;
		uint8_t interlace;
	public:
		IHDR(int width,int height,uint8_t color,bool interlace);	
}
#endif
