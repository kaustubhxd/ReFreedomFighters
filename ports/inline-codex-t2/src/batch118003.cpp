#include "ff.h"
extern "C" void* THISCALL ext_5003d0(void*,u32);
extern "C" void THISCALL ext_500360(void*,u32);
extern "C" void THISCALL ext_5002f0(void*,u32);
extern "C" void* STDCALL pack_seven(void* factory,u32 id,u32* values){
 void* out=vcall<void*>(factory,0x18,id);
 if(out){void* data=vcall<void*>(out,0x4c);
  for(u32 i=0;i<6;++i)ext_500360(ext_5003d0(data,i),values[i]);
  ext_5002f0(ext_5003d0(data,6),values[6]);
 }
 return out;
}
PCREG(551340,pack_seven);
extern "C" u8 THISCALL trace_geometry(u8* s,u8* query,u32 a,u32 b,u32 unused,u32 d,u32 e){
 if(*(u32*)(*(u8**)(s+8)+0x3c)&0x400)return 0;
 u32 out[18];out[0]=*(u32*)(query+0x34);out[15]=0;
 u8* sys=G(u8*,0x70039c);
 void* mgr=*(void**)(*(u8**)(sys+0x1aa3)+0x1c);
 if(!vcall<u8>(mgr,0x30,out,a,query,query+0xc,(u32)query[0x6c],b,d,e))return 0;
 sys=G(u8*,0x70039c);
 u32 id=vcall<u32>(*(void**)(sys+0x9b),0x50,out[4]);
 *(u32*)(query+0x34)=out[0];*(u32*)(query+0x44)=id;
 *(u32*)(query+0x3c)=out[16];*(u32*)(query+0x40)=out[17];*(u32*)(query+0x38)=out[15];
 for(u32 i=0;i<3;++i)*(u32*)(query+0x28+4*i)=out[1+i];
 for(u32 i=0;i<9;++i)*(u32*)(query+0x48+4*i)=out[5+i];
 return 1;
}
PCREG(4429d0,trace_geometry);
