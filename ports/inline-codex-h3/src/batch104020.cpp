#include "ff.h"
extern "C" u32 THISCALL ext_4e5e60(void*);
extern "C" u16 THISCALL ext_4e5e40(void*);
extern "C" float THISCALL ext_4e5e80(void*);
static void THISCALL copy_widget_state(u8* self,u8* arg) {
  if(!G(u32,arg)) return;
  u32 type=G(u8,(u8*)G(u32,arg));
  u8 value=(u8)(ext_4e5e60(arg)!=0);
  G(u8,self+0x63)=value;
  if((type&0xff)!=0xff && (type&0x3f)==2) G(u8,self+0x5e)=0;
  else {
    G(u8,self+0x5e)=value;
    G(u8,self+0x63)=(u8)(ext_4e5e60(arg)!=0);
  }
  G(float,self+0x5a)=ext_4e5e80(arg);
  G(u8,self+0x60)=(u8)(ext_4e5e60(arg)!=0);
  G(u8,self+0x61)=(u8)(ext_4e5e60(arg)!=0);
  G(u16,self+0x48)=ext_4e5e40(arg);
  G(u8,self+0x5f)=(u8)(ext_4e5e60(arg)!=0);
  if((type&0xff)!=0xff && (type&0x3f)==3) {
    G(u8,self+0x62)=(u8)(ext_4e5e60(arg)!=0);
    G(u8,self+0x64)=(u8)(ext_4e5e60(arg)!=0);
    G(u32,self+0x4e)=ext_4e5e60(arg);
    G(u32,self+0x52)=ext_4e5e60(arg);
  }
}
PCREG(4a4ad0,copy_widget_state);
