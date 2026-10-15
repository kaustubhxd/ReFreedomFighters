#include "ff.h"
extern "C" void FASTCALL ext_441940(u8 *,u8 *);
// Emit two triangles for every face with no neighbour or a neighbour lacking bit 0x80.
static u32 THISCALL fn4522d0(u8 *self,u8 *out,u8 *cell){
 static const u32 indices[6]={6,4,10,8,14,12};
 static const u32 corners[6][6]={
  {0x1c,0x4c,0x28,0x4c,0x58,0x28},
  {0x64,0x40,0x34,0x64,0x70,0x40},
  {0x1c,0x40,0x4c,0x40,0x70,0x4c},
  {0x28,0x58,0x64,0x64,0x34,0x28},
  {0x1c,0x28,0x40,0x28,0x34,0x40},
  {0x64,0x58,0x4c,0x4c,0x70,0x64}};
 u8 *dst=out;
 u32 count=0;
 for(u32 face=0;face<6;face++){
  u32 id=*(u16*)(cell+indices[face]);
  if(id && ((*(u8**)(self+0x3c))[(id-1)*0x7c+2]&0x80))continue;
  for(u32 v=0;v<6;v++)for(u32 k=0;k<3;k++){
   *(u32*)(dst+v*12+k*4)=*(u32*)(cell+corners[face][v]+k*4);
  }
  dst+=0x48;count+=2;
 }
 for(u32 i=0;i<count*3;i++)ext_441940(out+i*12,cell+0x10);
 return count;
}
PCREG(4522d0,fn4522d0);
