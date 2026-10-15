#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" float THISCALL ext_589c40(void*,u32,u32);
static void error31(u32 line,u32 detail){
 void* sink=vcall<void*>(G(void*,0x700390),0x20,0x69c8e0,line);
 typedef void(*Print)(void*,u32,u32);(*(Print*)(*(u8**)sink+0x2c))(sink,0x69c6b0,detail);
 ((void(*)())G(void*,0x7003b0))();
}
static void STDCALL lookup_scalar(u8* event){
 u8* value=ext_5003d0(*(void**)(event+4),0);u32 key;
 if(value[4]==3)key=*(u32*)value;
 else if(value[4]==4)key=vcall<u32>(*(void**)value,0x34);
 else {error31(0x111,0x69c9b0);key=0;}
 float f=ext_589c40(G(void*,0x7003b8),key,0xffffffff);
 u8* output=ext_5003d0(*(void**)(event+8),0);
 if(output[4]!=0 && output[4]!=2)error31(0x104,0x69c938);
 output[4]=2;*(float*)output=f;
}
PCREG(559dc0,lookup_scalar);
