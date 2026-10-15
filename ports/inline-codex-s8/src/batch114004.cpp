#include "ff.h"
static u32 rgb638(u32 r,u32 g,u32 b) { return (r<<16)+(g<<8)+b; }
static void THISCALL decode6380e0(void *self,u32 *out,u32 level) {
 u8 *d=vcall<u8 *>(self,0x38,level);
 s32 w=(*(s32 *)(d+4)+3)&~3, h=(*(s32 *)(d+8)+3)&~3;
 u32 *src=*(u32 **)(d+0x10);
 for(s32 y=0;y<h-3;y+=4) for(s32 x=0;x<w-3;x+=4) {
  u32 alpha0=src[0],alpha1=src[1],a=src[2]&65535,b=src[2]>>16,sel=src[3]; src+=4;
  u32 ar=(a>>8)&248,ag=(a>>3)&252,ab=(a&31)<<3;
  u32 br=(b>>8)&248,bg=(b>>3)&252,bb=(b&31)<<3;
  u32 colors[4]={rgb638(ar,ag,ab),rgb638(br,bg,bb),0,0};
  if(a>b) {colors[2]=rgb638((2*ar+br)/3,(2*ag+bg)/3,(2*ab+bb)/3); colors[3]=rgb638((ar+2*br)/3,(ag+2*bg)/3,(ab+2*bb)/3);}
  else colors[2]=rgb638((ar+br)/2,(ag+bg)/2,(ab+bb)/2);
  for(u32 i=0;i<16;i++) out[(y+i/4)*w+x+i%4]=colors[(sel>>(2*i))&3]+(((i<8?alpha0:alpha1)>>((4*i)&31)&15)<<28);
 }
}
PCREG(6380e0,decode6380e0);
