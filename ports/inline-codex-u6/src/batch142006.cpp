#include "ff.h"
extern "C" void THISCALL ext_43b2d0(void*);
extern "C" u8 THISCALL ext_438380(void*);
static u8 THISCALL check(u8* me){
 u8 flags=me[0x32];if(flags&4)return 0;
 u8* sys=G(u8*,0x70039c);
 if(me[0x3d]){
  if(!vcall<u8>(*(void**)(sys+0x9b),0x178)){
   sys=G(u8*,0x70039c);
   if(*(float*)(sys+0x9c7)==G(float,0x6785d0) || !sys[0x1b3e])return 0;
  }
 }else{
  if(sys[0x1b3e] && !(flags&8))return 0;
  if(vcall<u8>(*(void**)(sys+0x9b),0x178))return 0;
 }
 if((me[0x46]&1) || !me[0x10])return 0;
 ext_43b2d0(me);u32 type=*(u32*)(me+0x35);
 switch(type){
 case 8:if(!(me[0x33]&0x40))return 0;return ext_438380(me)?1:0;
 case 2:if(me[0x32]<0x80)return 0;return ext_438380(me)?1:0;
 case 4:if(!(me[0x33]&1))return 0;return ext_438380(me)?1:0;
 case 3:if(!(me[0x33]&2))return 0;return ext_438380(me);
 case 5:if(!(me[0x33]&4))return 0;return ext_438380(me);
 case 7:if(!(me[0x33]&8))return 0;return ext_438380(me);
 case 6:if(!(me[0x33]&0x20))return 0;return ext_438380(me);
 case 1:if(!(me[0x33]&0x10))return 0;return ext_438380(me);
 }
 if(!vcall<u32>(*(void**)(me+0x15),0x14))return ext_438380(me);
 u32 prior=*(u32*)(me+0x35);u8 result=ext_438380(me);
 return (me[0x32]>>4)&result&(prior!=7)&(prior!=1);
}
PCREG(437d60,check);
