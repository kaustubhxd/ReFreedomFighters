#include "ff.h"
extern "C" u32 STDCALL ext_61ba1c(u32,u32);
extern "C" void FASTCALL ext_54f2b0(u32,u32);
static u8 THISCALL initialize(u8*me){
 if(ext_61ba1c(0x54ba40,0)){auto lo=vcall<void*>(G(void*,0x700390),0x20,(u32)0x6a38e0,0x154);typedef void(*P)(void*,u32);(*(P*)(*(u8**)lo+0x2c))(lo,0x6a3928);return 0;}
 typedef u32(STDCALL *Create)(u32,void**,u32);u32 error=G(Create,0x676028)(0,(void**)(me+0xa274),0);if(error){ext_54f2b0(error,0x6a393c);return 0;}
 auto iface=*(void**)(me+0xa274);u32 window=vcall<u32>(me,0x94);typedef u32(STDCALL *Coop)(void*,u32,u32);error=(*(Coop*)(*(u8**)iface+0x18))(iface,window,2);if(error){ext_54f2b0(error,0x6a396c);return 0;}
 u32 caps[24];caps[0]=0x60;typedef u32(STDCALL *Caps)(void*,void*);error=(*(Caps*)(*(u8**)iface+0x10))(iface,caps);if(error){ext_54f2b0(error,0x6a3984);return 0;}
 return vcall<u8>(me,0xb0)!=0;
}
PCREG(54aeb0,initialize);
