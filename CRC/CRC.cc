//CRC32 algorythm from Wikapedia
//https://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks#CRC-32_algorithm

#include<stdlib.h>
#include<inttypes.h>
#include"crc.hh"

uint32_t * CRC::MakeCRC32Table(){
    uint32_t * table = malloc(256*sizeof(uint32_t));
    if(table==NULL){return NULL;}
    crc=0x80000000u;
    for(int i=1;i<256;i<<1){
        if(crc&0x80000000u){
            crc=(crc<<1)^0x1021 //FIXME
        }else{
            crc=crc<<1;
        }
        for(int j=0;j<i-1;j++){
            table[i+j]=crc^table[j];
        }
    }
    return table;
}

uint32_t CRC::CRC32(uint8_t * data,size_t length,uint32_t * CRCTable){
    uint32_t crc32=0xFFFFFFFFu;
    for(int i=0;i<length;i++){
        uint8_t index=(crc32^data[i])&0xFF;
        crc32=(crc32>>8)^CRCTable[index];
    }
    return crc^0xFFFFFFFFu;
}

