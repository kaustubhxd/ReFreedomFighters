#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_500360(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
static void* STDCALL params(void* factory,u32 key,u32* data){
 void* item=vcall<void*>(factory,0x18,key);if(!item)return item;
 void* list=vcall<void*>(item,0x4c);
 for(u32 i=0;i<8;++i){u32 value=data[i];void* entry=ext_5003d0(list,i);if(i==0||i==1||i==2||i==4)ext_500360(entry,value);else ext_5002f0(entry,value);}
 return item;
}
PCREG(500540,params);
