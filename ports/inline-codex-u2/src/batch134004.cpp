#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void* THISCALL ext_5002f0(void*,u32);
extern "C" void* THISCALL ext_500360(void*,float);
static void* STDCALL fn551a70(void* table,u32 id,u8* values){
 void* entity=vcall<void*>(table,0x18,id);if(!entity)return entity;
 void* args=vcall<void*>(entity,0x4c);
 for(u32 i=0;i<4;++i){u32 x=G(u32,values+i*4);void* slot=ext_5003d0(args,i);ext_5002f0(slot,x);}
 for(u32 i=4;i<12;++i){float x=G(float,values+i*4);void* slot=ext_5003d0(args,i);ext_500360(slot,x);}
 return entity;
}
PCREG(551a70,fn551a70);
