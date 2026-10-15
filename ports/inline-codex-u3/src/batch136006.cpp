#include "ff.h"
extern "C" void FASTCALL ext_4de040(void*,void*,void*);
extern "C" void THISCALL ext_4e09b0(float*);
static u32 THISCALL fn5a5950(u8*s,void*position,void*direction){
 float m[9];ext_4de040(m,direction,(void*)0);for(int i=0;i<3;i++){float t=m[i];m[i]=m[i+3];m[i+3]=t;}ext_4e09b0(m);
 u32 count=*(u32*)s;u8**a=*(u8***)(s+4);u32 i=0;
 while(i<count && !(*(u32*)(*(u8**)(a[i]+8)+0x3c)&0x400u))++i;
 if(i==count){typedef void(*AssertFn)();AssertFn assertfn=G(AssertFn,0x7003b0);if(assertfn)assertfn();return 0;}
 vcall<void>(a[i],0x2c);vcall<void>(a[i],0x70,position);vcall<void>(a[i],0x128,(u32)*(u16*)(s+0xc),0u,0u);
 u8**b=*(u8***)(s+8);vcall<void>(b[i],0x2c);vcall<void>(b[i],0x74,m,position);vcall<void>(b[i],0x128,(u32)*(u16*)(s+0xc),0u,0u);return i+1;
}
PCREG(5a5950,fn5a5950);
