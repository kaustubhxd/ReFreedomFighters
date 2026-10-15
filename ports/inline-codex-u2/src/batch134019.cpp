#include "ff.h"
extern "C" void THISCALL ext_5d5fc0(u8*);
static u32 THISCALL fn5d5d40(u8* s,u32 id,const float* input){
 if((u16)id!=G(u16,s+0x5c))return 0;
 float value=(G(float,s+0x58)*G(float,0x6a6888))*input[0];G(s32,s+0x50)=_mm_cvttss_si32(_mm_set_ss(value));ext_5d5fc0(s);
 if(G(u32,s+0x50)){
  u8* sys=G(u8*,0x70039c);s32 w=G(s32,sys+0x6f),h=G(s32,sys+0x73);
  float x=(float(w)*input[1])*G(float,s+0x48);x=float(w/2)*input[5]+x;
  float y=(float(h)*input[2])*G(float,s+0x48);y=float(h/2)*input[6]+y;
  float pos[3]={x,y,0};vcall<void>(G(void*,s+0x44),0x70,pos);
 }
 return 0;
}
PCREG(5d5d40,fn5d5d40);
