#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_500360(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
static void* THISCALL populateValues(void* unused,void* factory,u32 id,u32* values){
 void* object=vcall<void*>(factory,0x18,id);
 if(!object)return nullptr;
 void* table=vcall<void*>(object,0x4c);
 for(u32 i=0;i<11;++i){
  u32 value=values[i];void* element=ext_5003d0(table,i);
  if(i<6)ext_500360(element,value);else ext_5002f0(element,value);
 }
 return object;
}
PCREG(500630,populateValues);
