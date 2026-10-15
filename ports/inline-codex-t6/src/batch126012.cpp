#include "ff.h"
extern "C" void THISCALL ext_59a5b0(void*,u32,u32,u32);
extern "C" void THISCALL ext_566820(void*);
extern "C" void THISCALL ext_566a10(void*);
extern "C" void THISCALL ext_4f1520(void*,u32,void*);
static u32 THISCALL command(u8* me,u32 cmd,u32* data){
 u16 key=(u16)cmd;
 if(key==G(u16,me+0x184)){void* text=G(void*,G(u32,G(u32,0x70039c)+0x9b)+0xae4);u32 first=data[0],second=data[1],third=data[2];u32 message=vcall<u32>(text,0,0x6a6de4,third);ext_59a5b0(G(void*,me+0xa17),message,second,first);return 1;}
 if(key==G(u16,me+0x186)){if((G(u8,me+0xa0a)||G(u8,me+0xa0b))&&!G(u8,me+0xa0d)){ext_566820(me);G(u8,me+0xa0d)=1;G(float,me+0x1e6)=(float)G(s32,G(u32,0x70039c)+0x40)*G(float,0x6785e4);}return 0;}
 if(key==G(u16,me+0x188))G(u8,me+0xa08)=1;
 else if(key==G(u16,me+0x18a))G(u8,me+0xa08)=0;
 else if(key==G(u16,me+0x196))ext_566a10(me);
 else ext_4f1520(me,cmd,data);
 return 0;
}
PCREG(565f20,command);
