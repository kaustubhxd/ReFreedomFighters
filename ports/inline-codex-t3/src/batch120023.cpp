#include "ff.h"
extern "C" u32 THISCALL ext_5cf110(void *);
extern "C" void THISCALL ext_5d2630(void *,u32);
extern "C" u32 THISCALL ext_5d2860(void *,u32);
extern "C" void THISCALL ext_4e0d80(float *,float);
static u8 THISCALL checkPointerTarget(u8 *self) {
 u8 freeptr=self[0xd32];
 if(freeptr) *(u32 *)(self+0xb50)=*(u32 *)(*(u8 **)(*(u8 **)(self+0x44)+0x54)+12);
 self[0xd33]=0;
 if(*(u32 *)(self+0xad5)==9 || freeptr) {
  if((u8)ext_5cf110(self)) {ext_5d2630(self,*(u32 *)(self+0xd2e));return 1;}
 }
 if(self[0xd33])return 0;
 *(u32 *)(self+0xb8f)=0x3f800000;self[0xbc7]=0;
 __builtin_memcpy(self+0xb5b,self+0xcad,12);
 long double height=vcall<long double>(*(void **)(self+0xb54),0xac);
 ext_4e0d80((float *)(self+0xa72),(float)(height+*(float *)(self+0xdfd)));
 __builtin_memcpy(self+0xb67,self+0xa72,12);
 void *phys=*(void **)(*(u8 **)(G(u8 *,0x70039c)+0x9b)+0xadc);
 if(!vcall<u8>(phys,0x2e0,self+0xb5b,0u,0x10u,0xffffffffu,0u,1u))return 0;
 u32 r=ext_5d2860(self,*(u32 *)(self+0xb9f));
 if(r!=(*(u32 *)(self+0xad5)==9?1u:2u))return 0;
 ext_5d2630(self,*(u32 *)(self+0xb9f));return 1;
}
PCREG(5d11c0,checkPointerTarget);
