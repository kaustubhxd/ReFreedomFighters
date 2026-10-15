#include "ff.h"
extern "C" void THISCALL ext_5a5c50(u8*);
extern "C" void THISCALL ext_5a5c60(u8*);
extern "C" void THISCALL ext_5a5c80(u8*,float,float,char*);
extern "C" u32 VECTORCALL ext_633910(float);
static void THISCALL fn5ea870(u8* s,float value){
 u8* display=*(u8**)(s+0x1d0f);
 if(G(float,0x679540)>value){if(display)ext_5a5c50(display);return;}
 if(display)ext_5a5c60(display);
 u8* output=vcall<u8*>(G(u8*,0x70039c),0x190);char buf[32];
 typedef void(*Format)(u8*,char*,u32,u32);
 (*(Format*)(*(u8**)output+0x198))(output,buf,0x6784f4,ext_633910(value));
 display=*(u8**)(s+0x1d0f);if(!display)return;
 float y=*(float*)(s+0x1d1f)*G(float,0x67c1a8);y=y**(float*)(s+0x1d27);
 float x=*(float*)(s+0x1d1b)*G(float,0x67c1a8);x=x**(float*)(s+0x1d23);
 ext_5a5c80(display,x,y,buf);
}
PCREG(5ea870,fn5ea870);
