#include "ff.h"
static void STDCALL colors(u8* vertices,u32 n,u32 flags){
 bool blended=flags&0x2000;
 float scale=blended?G(float,0x6bdefc):G(float,0x682eb8);
 for(u32 i=0;i<n;++i){
  u32 color=*(u32*)(vertices+0x18+0x24*i);
  G(float,0x812440+16*i)=(float)((color>>16)&255)*scale;
  G(float,0x812444+16*i)=(float)((color>>8)&255)*scale;
  G(float,0x812448+16*i)=(float)(color&255)*scale;
  float alpha=(float)(color>>24)*scale;
  G(float,0x81264c+16*i)=alpha;
  float complement=blended?G(float,0x680a60)-alpha:0.0f;
  G(float,0x812640+16*i)=complement;
  G(float,0x812644+16*i)=complement;
  G(float,0x812648+16*i)=complement;
 }
}
PCREG(61ab70,colors);
