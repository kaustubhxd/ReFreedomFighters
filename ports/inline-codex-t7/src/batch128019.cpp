#include "ff.h"
extern "C" void* ext_634d22(void*,const void*,u32);
static inline u32 w21(u8*p,u32 o){return *(u32*)(p+o);}
static u32 endian21(u32 value){u8*t=*(u8**)(G(u8*,0x70039c)+0x9b);if(t && w21(t,0x62e7)==3)return __builtin_bswap32(value);return value;}
static u32 len21(u8*p){u32 n=0;while(p[n])++n;return n;}
static u8* THISCALL pack21(u8*self,u8*out){
 *(u32*)out=endian21(w21(self,4));*(u32*)(out+4)=endian21(w21(self,28));
 u32 hi=vcall<u32>(self,0x1c)<<16,lo=vcall<u32>(self,0x20);*(u32*)(out+8)=endian21(hi|lo);
 u32 v=vcall<u32>(self,0x34);*(u32*)(out+12)=endian21(v);
 v=vcall<u32>(self,0x48);*(u32*)(out+16)=endian21(v);
 v=vcall<u32>(self,0x30);*(u32*)(out+20)=endian21(v);
 v=vcall<u32>(self,0x28);*(u32*)(out+24)=endian21(v);
 out+=28;
 if(*(u8**)(self+24)){u8*s=*(u8**)(self+24);ext_634d22(out,s,len21(s));out+=len21(*(u8**)(self+24));}
 *out++=0;
 u32 i=0;
 if(vcall<u32>(self,0x34))do{
  u8*rec=vcall<u8*>(self,0x38,i);*(u32*)out=endian21(w21(rec,0));out+=4;
  ext_634d22(out,*(u8**)(rec+16),w21(rec,0));out+=w21(rec,0);++i;
 }while(i<vcall<u32>(self,0x34));
 return out;
}
PCREG(6397c0,pack21);
