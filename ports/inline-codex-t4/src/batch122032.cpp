#include "ff.h"
extern "C" u32 THISCALL ext_4e1590(u8*);
static void THISCALL fn4e12f0(u8* s,float* out,u32 count){
 do{u8* p=*(u8**)(s+8);u32 type=p[0]==255?255:p[0]&63;
  if(type==1)*out=(float)*(double*)(p+1);
  else if(type==2)*(u32*)out=*(u32*)(p+1);
  else if(type==3)*out=(float)(double)*(u32*)(p+1);
  else{u8* logger=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x697114,(u32)0x229);
   p=*(u8**)(s+8);type=p[0]==255?255:p[0]&63;typedef void(*Log)(u8*,u32,u32);(*(Log*)(*(u8**)logger+0x2c))(logger,0x697160,type);
   typedef void(*Assert)();(*(Assert*)0x7003b0)();
  }
  *(u8**)(s+8)+=ext_4e1590(s)+1;
  if(count==1)break;--count;++out;
 }while(true);
}
PCREG(4e12f0,fn4e12f0);
