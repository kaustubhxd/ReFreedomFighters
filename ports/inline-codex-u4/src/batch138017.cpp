#include "ff.h"
extern "C" void THISCALL ext_4db500(void*,float*);
static void THISCALL layoutMessage(u8* s,void* input,u8 mode,u32 count){
 if(!input)return;
 void* text=*(void**)(s+0xc62);vcall<void>(text,0xbc,0u);
 *(u32*)(*(u8**)(s+0xc62)+0x93)=0xfffffffau;
 vcall<void>(*(void**)(s+0xc62),0x284,input);
 u8* string=*(u8**)(*(u8**)(s+0xc62)+0x97);u32 newlines=0;
 for(u32 i=0;string[i];++i)if(string[i]==0xa)++newlines;
 vcall<void>(*(void**)(s+0xc76),0xbc,0u);vcall<void>(*(void**)(s+0xc7a),0xbc,0u);
 float pos[3];u32 y;
 if(mode){pos[0]=0;pos[2]=0;y=count*20+170;}
 else{ext_4db500(*(void**)(*(u8**)(s+0xc76)+8),pos);y=newlines*23+38;}
 pos[1]=(float)(s32)y;
 vcall<void>(*(void**)(s+0xc7a),0x70,pos);
}
PCREG(565240,layoutMessage);
