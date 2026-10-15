#include "ff.h"
struct AdjustRecord53 {u8 b[53];};
extern "C" void FASTCALL ext_4ae160(u8 *,s32,s32,AdjustRecord53);
static void copyRecord53(u8 *dst,const u8 *src) {for(u32 k=0;k<53;++k) dst[k]=src[k];}
static void FASTCALL adjustHeap53(u8 *first,s32 hole,s32 length,AdjustRecord53 value) {
  s32 top=hole;
  s32 child=hole*2+2;
  while(child<length) {
    if (*(float *)(first+(child-1)*53)>*(float *)(first+child*53)) --child;
    copyRecord53(first+hole*53,first+child*53);
    hole=child;
    child=child*2+2;
  }
  if(child==length) {
    copyRecord53(first+hole*53,first+(child-1)*53);
    hole=child-1;
  }
  ext_4ae160(first,hole,top,value);
}
PCREG(4adc70,adjustHeap53);
