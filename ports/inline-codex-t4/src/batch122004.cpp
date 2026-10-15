#include "ff.h"
static u8* THISCALL fn469870(u8* s){
 float step=G(float,0x67a284);
 *(u32*)s=0x686874;
 u32 initial[]={4,8,0x10,0x14,0x18,0x38,0x3c};
 for(u32 off: initial)*(u32*)(s+off)=0;
 *(u32*)(s+0xc)=0x3dcccccd;
 u8* sys=G(u8*,0x70039c);u8* tab=*(u8**)(sys+0x9b);
 float a=*(float*)(tab+0xae0)*step;a=a*G(float,0x67862c);
 *(u32*)(s+0x10)=*(u32*)(sys+0x40)-(u32)_mm_cvttss_si32(_mm_set_ss(a));
 sys=G(u8*,0x70039c);tab=*(u8**)(sys+0x9b);
 *(float*)(tab+0xae0)=*(float*)(tab+0xae0)+step;
 sys=G(u8*,0x70039c);tab=*(u8**)(sys+0x9b);
 if(*(float*)(tab+0xae0)>=G(float,0x678858))*(u32*)(tab+0xae0)=0;
 u32 final[]={0x1c,0x24,0x28,0x30,0x34};
 for(u32 off: final)*(u32*)(s+off)=0;
 sys=G(u8*,0x70039c);vcall<void>(*(u8**)(sys+0x9b),0x30,s);
 return s;
}
PCREG(469870,fn469870);
