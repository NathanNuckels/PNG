//ADENDUM: Calculating the CRC thingy

unsigned long crc_table[256];
int crc_table_computed=0;

void make_crc_table(void){
    unsigned long c;
    int k;
    int n;
    for(n=0;n<256;n++){
        c = (unsigned long) n;
        for(k=0;k<8;k++){
            if(c%2){
                c = 0xEDB88320L ^ (c>>1); //c>>1 = c/2
            }else{
                c=c>>1; //c>>1 = c/2;
            }
        }
        crc_table[n]=c;
    }
    crc_table_computed=1;
}
unsigned long update_crc(unsigned long crc,unsigned char *buf,int len){
    unsigned long c=crc;
    int n;
    if(!crc_table_computed){make_crc_table();}
    for(n=0;n<len;n++){
        c=crc_table[(cuf[n])&0xff]^(c>>8);
    }
    return c;
}
unsigned long crc(unsigned char* buf,int len){
    return update_crc(0xFFFFFFFFL,buf,len)^0xFFFFFFFFL;
}

//My own personal system
