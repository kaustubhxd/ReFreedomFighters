#include "s4_mem.h"
extern "C" void THISCALL f5e93f0(void* self,u32 weapon,u32 purge){
 u32 i=0;
 while(i<s4r(self,0x48)){
  bool erase=(u8)purge?s4r(self,0x4c+8*i)==0:s4r(self,0x4c+8*i)==weapon;
  if(erase){
   u32 n=s4r(self,0x48);
   for(u32 j=i;j<n-1;j++){s4w(self,0x4c+8*j,s4r(self,0x54+8*j));s4w(self,0x50+8*j,s4r(self,0x58+8*j));}
   s4w(self,0x48,n-1);
   if(!(u8)purge)return;
  }
  i++;
 }
}
PCREG(5e93f0,f5e93f0);
extern "C" u32 THISCALL f427150(void*,void* stream,u32 offset,u32 logical){
 typedef s32(*Seek)(void*,u32,u32);typedef u32(*Read)(void*,u32,u32,void*);
 ((Seek)G(u32,0x6763e8))(stream,offset,0);
 Read read=(Read)G(u32,0x6763f8);
 u32 marker;read(&marker,1,4,stream);
 while(marker){
  ((Seek)G(u32,0x6763e8))(stream,offset+12,0);
  u32 start,length,physical;
  read(&start,1,4,stream);read(&length,1,4,stream);read(&physical,1,4,stream);
  if(logical>=start&&logical<start+length)return physical-start+logical;
  offset+=40;
  ((Seek)G(u32,0x6763e8))(stream,offset,0);read(&marker,1,4,stream);
 }
 return 0;
}
PCREG(427150,f427150);
