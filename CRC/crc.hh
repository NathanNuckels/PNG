#ifndef CRC_HH
#define CRC_HH
//DEPENDS: CRC/CRC.cc
namespace CRC{
    uint32_t * MakeCRC32Table();
    uint32_t * CRC32(uint8 * data,size_t length,uint_32 * table);
}
#endif
