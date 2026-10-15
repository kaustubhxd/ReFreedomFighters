#include "ff.h"
static void THISCALL fn4491c0(u8* s,void* driver,u32 a,u32 b,u32 c){
 u32 flags=G(u32,s+0x14);if(!(flags&1))return;
 u32 mode=G(u32,s+0x1c);u32 bit=(flags>>3)&1;
 if(mode==1||mode==2){
  vcall<void>(driver,0x94,b,c,a,bit);
  vcall<void>(driver,0x9c,b,c,G(float,s+0x38),G(float,s+0x30));
  vcall<void>(driver,0x98,b,c,G(float,s+0x34),G(float,s+0x2c));
 }else if(mode==0){
  vcall<void>(driver,0xa8,b,c,a,bit);
  float vec[3];for(int i=0;i<3;++i)vec[i]=G(float,s+0x30);
  vcall<void>(driver,0xb0,b,c,vec);
  for(int i=0;i<3;++i)vec[i]=G(float,s+0x2c);
  vcall<void>(driver,0xac,b,c,vec);
 }
}
PCREG(4491c0,fn4491c0);
