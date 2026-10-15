#include "ff.h"
struct Rec53 {u8 b[53];};
extern "C" void FASTCALL ext_4adf60(u8 *,u8 *,u32,u32);
extern "C" void FASTCALL ext_4adc70(u8 *,u32,s32,Rec53);
extern "C" void FASTCALL ext_4ae460(u8 *,u8 *);
static void FASTCALL heapSelectSort53(u8 *first,u8 *middle,u8 *last,u32 unused) {
  ext_4adf60(first,middle,0,0);
  u8 *cursor=middle;
  for (;cursor<last;cursor+=53) {
    if (*(float *)first>*(float *)cursor) {
      Rec53 value;
      for(u32 k=0;k<53;++k) {value.b[k]=cursor[k];cursor[k]=first[k];}
      ext_4adc70(first,0,(s32)(middle-first)/53,value);
    }
  }
  ext_4ae460(first,middle);
}
PCREG(4ae0b0,heapSelectSort53);
