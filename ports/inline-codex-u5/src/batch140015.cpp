#include "ff.h"
extern "C" void THISCALL ext_4db500(void*,void*);
extern "C" u8 THISCALL clamp_edit_width(u8* me){
 if(!*(void**)(me+0x5ca))return 0;
 char* text=(char*)(me+0x1c9);s32 len=0;while(text[len])++len;
 s32 width=0;if(len)width=vcall<s32>(*(void**)(me+0x5ce),0x290,len);
 s32 max=*(s32*)(me+0x184);
 while(width>max && max>0 && len!=0){
  text[--len]=0;width=vcall<s32>(*(void**)(me+0x5ce),0x290,len);
  vcall<void>(*(void**)(me+0x5ca),0x248,0xff0000u);
  max=*(s32*)(me+0x184);
 }
 vcall<void>(*(void**)(me+0x5ce),0x284,text);
 float pos[3];ext_4db500(*(void**)(*(u8**)(me+0x5ce)+8),pos);
 pos[0]=(float)width+pos[0];vcall<void>(*(void**)(me+0x5ca),0x70,pos);
 return 1;
}
PCREG(56fb10,clamp_edit_width);
