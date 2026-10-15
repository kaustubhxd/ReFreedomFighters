#include "ff.h"
extern "C" void *THISCALL ext_5003d0(void *,u32);
extern "C" void THISCALL ext_5002f0(void *,u32);
extern "C" void THISCALL ext_500360(void *,u32);
static void *STDCALL fillScriptParameters(void *mgr,u32 id,const u32 *p) {
  void *entry=vcall<void *>(mgr,0x18,id);
  if(!entry) return 0;
  void *params=vcall<void *>(entry,0x4c);
  for(u32 i=0;i<5;++i) ext_5002f0(ext_5003d0(params,i),p[i]);
  for(u32 i=5;i<8;++i) ext_500360(ext_5003d0(params,i),p[i]);
  return entry;
}
PCREG(551c60,fillScriptParameters);
