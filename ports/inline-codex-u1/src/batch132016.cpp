#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
static void bad16(u32 line,const char* msg){
 void* ch=vcall<void*>(G(void*,0x700390),0x20,(const char*)0x69c8e0,line);
 typedef void(*Print)(void*,const char*,const char*);
 (*(Print*)(*(u8**)ch+0x2c))(ch,(const char*)0x69c6b0,msg);
 (*(void(**)())0x7003b0)();
}
static void THISCALL play16(u8* self,u8* request){
 void* input=*(void**)(request+4);
 u8* flag=ext_5003d0(input,2);u8* value=ext_5003d0(input,1);u32 id;
 if(value[4]==3)id=*(u32*)value;
 else if(value[4]==4)id=vcall<u32>(*(void**)value,0x34);
 else {bad16(0x111,(const char*)0x69c9b0);id=0;}
 u8* mode=ext_5003d0(input,0);
 u32 handle=vcall<u32>(*(void**)(self+0x1c),0x6ec,(u32)*mode,id,(u32)(*(u32*)flag!=0));
 u8* sound=vcall<u8*>(*(void**)(G(u8*,0x70039c)+0x9b),0x60,handle);
 float duration=sound?*(float*)(sound+0x70):0.0f;
 u8* output=ext_5003d0(*(void**)(request+8),0);
 if(output[4]!=0 && output[4]!=2)bad16(0x104,(const char*)0x69c938);
 output[4]=2;*(float*)output=duration;
}
PCREG(55bbc0,play16);
