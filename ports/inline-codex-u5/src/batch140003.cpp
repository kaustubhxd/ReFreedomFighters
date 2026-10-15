#include "ff.h"
extern "C" void THISCALL ext_58a320(u8*);
extern "C" float FASTCALL ext_4e0830(void*,void*);
extern "C" u8 THISCALL ext_59e050(void*,u32);
extern "C" void THISCALL choose_nearest(u8* me,void* actor,u32 unused,u32* output,u8* flag){
 float rot[9],origin[3];
 vcall<void>(actor,0x80,rot,origin);ext_58a320(me);
 u32* it=(u32*)(me+0x3c);u32* best=it+*(u32*)(me+0x38);
 float distance=G(float,0x67cd44);u32 priority=0;
 while(it!=(u32*)(me+0x3c)+*(u32*)(me+0x38)){
  float m[9],p[3];void* target=**(void***)it;
  vcall<void>(target,0x80,m,p);
  float d=ext_4e0830(p,origin);
  u32 id=vcall<u32>(*(void**)(G(u8*,0x70039c)+0x9b),0x4c,target);
  u32 rank=ext_59e050(actor,id);
  if(rank>priority || (rank==priority && distance>d)){best=it;distance=d;priority=rank;}
  ++it;
 }
 if(best!=(u32*)(me+0x3c)+*(u32*)(me+0x38)){*output=*best;*flag=priority!=0;}
 else{*output=0;*flag=0;}
}
PCREG(589a10,choose_nearest);
