#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_500360(void*,float);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void* STDCALL fill_script_record(void* table,u32 key,u8* input){
 void* entry=vcall<void*>(table,0x18,key);if(!entry)return 0;
 void* array=vcall<void*>(entry,0x4c);
 for(u32 i=0;i<7;++i){float value=*(float*)(input+4*i);void* dst=ext_5003d0(array,i);ext_500360(dst,value);}
 u32 value=*(u32*)(input+0x1c);void* dst=ext_5003d0(array,7);ext_5002f0(dst,value);
 return entry;
}
PCREG(551240,fill_script_record);
