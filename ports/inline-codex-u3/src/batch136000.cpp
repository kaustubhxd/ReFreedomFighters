#include "ff.h"
extern "C" float THISCALL ext_44c840(float*);
extern "C" void THISCALL ext_525640(void*,float*,float*);
extern "C" void THISCALL ext_525380(void*,float*,float*);
extern "C" void THISCALL ext_523330(void*,float*);
extern "C" void THISCALL ext_4e09b0(float*);
extern "C" void FASTCALL ext_443ef0(float*,float*,float*,float);
static void THISCALL fn517d50(u8* s,u32 flag){
 if(s[0x133]){
  vcall<void>(s,0x80,s+0x6c,s+0x60);
  for(int i=0;i<3;i++) *(u32*)(s+0x15df + 4*i)=*(u32*)(s+0x6c + 4*i);
  *(u32*)(s+0x15e3)=0;
  ext_44c840((float*)(s+0x15df));
  ext_525640(s+0x2d8,(float*)(s+0x60),(float*)(s+0x15df));
  ext_525380(s+0x2d8,(float*)(s+0x6c),(float*)(s+0x60));
 }else if(s[0x1614]){
  u8* p=*(u8**)(s+0x5c);
  float pos[3]={*(float*)(p+8),*(float*)(p+0xc)+G(float,0x67cd40),*(float*)(p+0x10)};
  float dir[3]; ext_523330(p,dir); dir[1]=0;
  ext_44c840(dir);
  float dst[3];
  if((u8)flag){ext_443ef0(dst,pos,dir,bitsf(fbits(*(float*)(s+0x378))^0x80000000u)); *(u32*)(s+0x1650)=0;}
  else {ext_4e09b0(dir);ext_443ef0(dst,pos,dir,*(float*)(s+0x37c));*(u32*)(s+0x1650)=1;}
  ext_525640(s+0x2d8,dst,dir);
  for(int i=0;i<3;i++){*(float*)(s+0x15df + 4*i)=dir[i];*(float*)(s+0x15d3 + 4*i)=pos[i];}
  ext_525380(s+0x2d8,(float*)(s+0x6c),(float*)(s+0x60));
 }
}
PCREG(517d50,fn517d50);
