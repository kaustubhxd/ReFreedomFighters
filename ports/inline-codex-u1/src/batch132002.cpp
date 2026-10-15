#include "ff.h"
extern "C" u8 THISCALL ext_5b1000(void*,void*);
static void THISCALL selection(u8* self,u8* out,u32* indices){
 s32 idx=*(s32*)(self+0x598);
 if(idx!=-1 && ext_5b1000(self,*(void**)(self+8+4*idx))){
  char key[15];for(int k=0;k<15;++k)key[k]=G(char,0x6b11f4+k);
  *(u32*)key=**(u32**)(self+8+4*idx);
  s32 count=*(s32*)(self+0x5b8);
  for(s32 i=0;i<count;++i){
   const char* p=*(char**)(self+8+4*i);int k=0;while(key[k]==p[k] && key[k])++k;
   if(key[k]==p[k]){*(u32*)(out+4)=*(u32*)(self+0x1d8+4*i);*(u32*)(out+0x24)=1;indices[0]=i;return;}
  }
  *(u32*)(out+0x24)=0;return;
 }
 u32 n=0;for(int i=0;i<8;++i){s32 x=*(s32*)(self+0x598+4*i);if(x==-1)break;*(u32*)(out+4+4*n)=*(u32*)(self+0x1d8+4*x);indices[i]=x;++n;}
 *(u32*)(out+0x24)=n;
}
PCREG(5b0cc0,selection);
