#include "ff.h"
extern "C" void FASTCALL ext_4e0d40(void*,void*,u32);
extern "C" void THISCALL ext_4db2a0(void*,void*);
extern "C" void FASTCALL ext_4de7e0(void*,void*);
extern "C" void FASTCALL ext_633654(u32);
static void THISCALL update4c95a0(u8* self) {
 u8* eng=G(u8*,0x70039c);
 float f=*(float*)(eng+0x48)*G(float,0x67885c);
 if(self[0x58]) {
  if((s32)(*(u32*)(eng+0x40)-*(u32*)(self+0x5b))>0x800) {
   self[0x58]=0; vcall<void>(self,0x68,0x10,0);
  }
 } else if(self[0x59] && (s32)(*(u32*)(eng+0x40)-*(u32*)(self+0x5b))>0x400) self[0x59]=0;
 u32 vec[3], mat[12];
 ext_4e0d40(vec,self+0x4c,fbits(f));
 void* child=*(void**)(self+0x44);
 ext_4db2a0(*(void**)((u8*)child+8),mat);
 ext_4de7e0(mat,vec);
 vcall<void>(self,0x84,mat);
 vcall<void>(*(void**)(self+0x44),0x6c,mat);
 ext_633654(0);
}
PCREG(4c95a0,update4c95a0);
