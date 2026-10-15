#include "ff.h"
extern "C" void THISCALL ext_467410(void*,u32,float,u32,u32,u32,u32);
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_500360(void*,float);
static u8 THISCALL fn4860b0(u8*s){
 vcall<void>(*(void**)(s+8),0x144,0x68ce24u);
 ext_467410(*(u8**)(s+0x10)+4,*(u32*)(s+0xc),bitsf(0x3e99999a),0,0,0,0xffffffff);
 u32 kind=vcall<u32>(*(void**)(s+8),0x1e0,0x1007d8u);
 if(kind&255){
  vcall<void>(*(void**)(s+8),0x2d0,1u,0u);
  void *actor=*(void**)(s+8);typedef void(THISCALL *givefn)(void*,u32,u32,u32);
  givefn give=*(givefn*)(*(u8**)actor+0x2f0);
  u8 *sys=G(u8*,0x70039c);u32 item=vcall<u32>(*(void**)(sys+0x9b),0x4c,*(u32*)(s+0xc));
  give(*(void**)(s+8),item,0,1);
 }else{
  u8 *sys=G(u8*,0x70039c);u32 actor=vcall<u32>(*(void**)(sys+0x9b),0x4c,*(u32*)(s+8));
  vcall<void>(*(void**)(s+0x10),8,*(u32*)(s+0xc),actor);
 }
 return 0;
}
PCREG(4860b0,fn4860b0);
static void fn40c320(s32 x0,s32 x1,s32 y0,s32 y1,float*data){
 s32 dy=y1-y0,dx=x1-x0,quot=dy/dx,step=dy<0?quot-1:quot+1;
 s32 absdy=dy<0?-dy:dy,prod=quot*dx;
 s32 rem=absdy-(prod<0?-prod:prod),error=0;
 float *table=(float*)0x6f1f58;
 for(s32 x=x0;x<x1;x++){
  if(x!=x0){error+=rem;if(error>=dx){error-=dx;y0+=step;}else y0+=quot;}
  float value;
  asm volatile("flds %1\n\tfmuls %2\n\tfstps %0":"=m"(value):"m"(table[y0]),"m"(data[x]):"st");
  data[x]=value;
 }
}
PCREG(40c320,fn40c320);
static u32 STDCALL fn551160(void*a,u32 id,u32*values){
 void *o=vcall<void*>(a,0x18,id);if(!o)return 0;
 void *cells=vcall<void*>(o,0x4c);
 for(u32 i=0;i<6;i++)ext_500360(ext_5003d0(cells,i),bitsf(values[i]));
 return (u32)o;
}
PCREG(551160,fn551160);
