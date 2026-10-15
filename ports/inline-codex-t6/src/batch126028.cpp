#include "ff.h"
static s32 colorPart(float f){return _mm_cvttss_si32(_mm_set_ss(f*G(float,0x6bdf00)));}
static u32 clampByte(s32 n){return n<0?0:n>255?255:(u32)n;}
static void STDCALL pack(u32* dest,u32* source,u32 count){
 for(u32 i=0;i<count;++i){float* rgba=(float*)(0x812640+16*i);u32 a=clampByte(colorPart(rgba[0])),b=clampByte(colorPart(rgba[1])),c=clampByte(colorPart(rgba[2])),d=(u32)colorPart(rgba[3]);u32 color=(((d<<8)+a)<<8)+b;color=(color<<8)+c;
 for(int j=0;j<6;++j)dest[j]=source[j];dest[6]=color;dest[7]=source[7];dest[8]=source[8];dest+=9;source+=9;
 }
}
PCREG(61a7d0,pack);
