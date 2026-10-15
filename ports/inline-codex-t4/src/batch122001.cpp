#include "ff.h"
struct Record {u8 data[53];};
extern "C" void FASTCALL ext_4adc70(u8*,u32,s32,Record);
static void FASTCALL fn4ae460(u8* first,u8* end) {
 s32 bytes=end-first;
 if(bytes<106)return;
 u8* last=end-53;
 do {
  Record tmp;
  for(u32 i=0;i<53;++i){tmp.data[i]=last[i];last[i]=first[i];}
  ext_4adc70(first,0,(bytes-53)/53,tmp);
  last-=53;bytes=last-first+53;
 }while(bytes>=106);
}
PCREG(4ae460,fn4ae460);
