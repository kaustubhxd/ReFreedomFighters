#include "s4_mem.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_55f900(void*,void*,void*,void*);
extern "C" void THISCALL ext_4e09b0(void*);
extern "C" void THISCALL f55ee30(void* self,void* input){
 void* value=ext_5003d0(s4p(input,4),0);
 void* target=vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,s4r(value,0));
 if(target){
  u32 basis[9],pos[3];vcall<void>(target,0x80,basis,pos);
  if((u8)vcall<u32>(target,0x1e0,0x2000e1u))ext_55f900(self,target,basis,pos);
  ext_4e09b0(basis);
  vcall<void>(s4p(self,0x18),0x370,basis,pos);
 }else{
  void* log=vcall<void*>(G(void*,0x700390),0x20,0x6a6148u,0x15du);
  void* record=vcall<void*>(s4p(self,0x18),0x20);
  typedef void(*Print)(void*,u32,u32);((Print)s4r(s4p(log,0),0x30))(log,0x69d10cu,s4r(record,4));
 }
}
PCREG(55ee30,f55ee30);
extern "C" u8 THISCALL f5beeb0(void* self,void* reader){
 u32 ref;vcall<void>(reader,0x40,&ref);
 s4w(self,0,(u32)vcall<void*>(s4p(G(void*,0x70039c),0x9b),0x58,ref));
 u32 value;vcall<void>(reader,0x48,&value);*((u8*)self+4)=(u8)value;
 vcall<void>(reader,0x50,(u8*)self+9);
 vcall<void>(reader,0x68,(u8*)self+5);vcall<void>(reader,0x68,(u8*)self+6);
 vcall<void>(reader,0x48,&value);*((u8*)self+7)=(u8)value;
 vcall<void>(reader,0x48,&value);*((u8*)self+8)=(u8)value;
 vcall<void>(reader,0x6c,(u8*)self+0x29);vcall<void>(reader,0x50,(u8*)self+0x35);
 vcall<void>(reader,0x68,(u8*)self+0x39);vcall<void>(reader,0x18,(u8*)self+0x11,0x18u);
 s4w(self,0xd,0);return 1;
}
PCREG(5beeb0,f5beeb0);
