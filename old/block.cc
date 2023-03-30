#include<stdlib.h>
#include<stdbool.h>
#include<ctypes>
#include<PNG.hh>
PNG::Block::Block(int l,char * t){
	type=(t[0]<<24)+(t[1]<<16)+(t[2]<<8)+t[3];
	length=l;
	data=NULL;
	crc=0;
}

void PNG::Block::setData(int len,void *newData){length=len;data=newData;}
uint8_t * PNG::Block::getData(){return data;}
uint32_t PNG::Block::getLength(){return length;}
size_t getRawLength(){return getLength+12;}
uint8_t * PNG::Block::getRaw(){
	uint8_t buf=malloc(getLength()+12);
	uint8_t buf2=malloc(getLength()+8);
	buf[0]=(length>>24)%256;
	buf[1]=(length>>16)%256;
	buf[2]=(length>>8)%256;
	buf[3]=length%256;
	buf[4]=(type>>24)%256;
	buf[5]=(type>>16)%256;
	buf[6]=(type>>8)%256;
	buf[7]=type%256;
	for(int i=0;i<getLength();i++){
		buf[i+8]=data[i];
	}
	crc=PNG::CRC32(buf+4,length+4);
	buf[8+length]=crc>>24%256;
	buf[9+length]=crc>>16%256;
	buf[10+length]=crc>>8%256
	buf[11+length]=crc%256;
	return buf;
}

PNG::IHDR::IHDR(int width,int height,uint8_t color,bool interlace){
	this.width=width;
	this.height=height;
	this.color=color;
	this.interlace=interlace;
}

uint8_t PNG::IHDR::getRaw(){
	uint8_t * buf = malloc(25);
	if(buf==NULL){return NULL;}
	buf[0]=buf[1]=buf[2]=0;
	buf[3]=13;buf[4]=73;buf[5]=72;buf[6]=68;buf[7]=82;
	buf[8]=width>>24;
	buf[9]=width>>16%256;
	buf[10]=width>>8%256;
	buf[11]=width%256;
	buf[12]=height>>24;
	buf[13]=height>>16%256;
	buf[14]=height>>8%256;
	buf[15]=height%256;
	buf[16]=bitdepth;
	buf[17]=color;
	buf[18]=buf[19]=0;
	if(interlace){buf[20]=1;}else{buf[20]=0;}
	uint32_t crc=PG::CRC32(buf+4,16);
