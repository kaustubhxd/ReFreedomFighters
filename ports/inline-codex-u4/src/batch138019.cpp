#include "ff.h"
extern "C" void FASTCALL ext_43e8e0(void*,void*,void*);
extern "C" void FASTCALL ext_43e920(void*,void*,void*);
extern "C" void THISCALL ext_4e0d00(void*,float);
extern "C" void THISCALL ext_4dc600(void*,void*);
extern "C" void THISCALL ext_4dce50(void*,float);
extern "C" void THISCALL ext_4dd060(void*,void*);
static void THISCALL updateBounds(u8* s){
 u8* body=*(u8**)(s+8);u32 id=*(u32*)(body+0x6c);if(!id)return;
 float info[14];
 void* table=*(void**)(*(u8**)(G(u8*,0x70039c)+0x1aa3)+0x18);
 vcall<void>(table,0x84,id,info);
 float width=(float)crt::cos((double)info[9]);width=width*info[7];
 float tangent=(float)crt::tan((double)info[9]);width=width*tangent;
 float negative=bitsf(fbits(width)^G(u32,0x67af40));
 float low[3]={width,width,info[7]},high[3]={negative,negative,0},center[3];
 ext_43e8e0(center,low,high);ext_4e0d00(center,0.5f);
 ext_4dc600(body,center);ext_43e920(center,low,center);
 float yy=center[1]*center[1];float xx=center[0]*center[0];float square=xx+yy;square=square+center[2]*center[2];
 float radius=(float)crt::sqrt((double)square);radius=radius+G(float,0x678858);
 ext_4dce50(body,radius);ext_4dd060(body,center);
}
PCREG(448430,updateBounds);
