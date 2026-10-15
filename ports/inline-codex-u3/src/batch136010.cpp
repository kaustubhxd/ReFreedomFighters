#include "ff.h"
extern "C" void* ext_41e290(u32);
static u32 THISCALL fn654800(u8*s,u32 id,u32 count,u32*input,u32 flags){
 u32*header=(u32*)ext_41e290(16);*(u32**)(s+0x11e9)=header;header[1]=count;
 u32 words=count*4u;u64 bytes=(u64)words*4u;header[2]=(u32)ext_41e290(bytes>0xffffffffu?0xffffffffu:(u32)bytes);header[3]=flags;header[0]=id;
 u32*out=(u32*)header[2];for(u32 i=0;i<words;i++)out[i]=input[i]^G(u32,0x67af40);
 return (u32)header;
}
PCREG(654800,fn654800);
