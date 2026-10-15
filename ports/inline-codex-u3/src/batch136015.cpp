#include "ff.h"
extern "C" void THISCALL ext_41dd90(u32);
extern "C" void* ext_634d10(void*,u32,u32);
extern "C" u32 THISCALL ext_41d500(void*);
extern "C" void ext_41e010(u32,...);
static void THISCALL fn41d540(u32 thread){
 u32 line=0;ext_41dd90(thread);u8 info[0x23c];ext_634d10(info,0,0x23c);*(u32*)info=0x23c;
 typedef u32(STDCALL*Api3)(u32,u32,void*);typedef u32(STDCALL*Api4)(u32,u32,void*,void*);typedef u32(STDCALL*Api0)();typedef u32(STDCALL*Api1)(u32);typedef void(*Format)(char*,u32,u32,u32,u32);
 u32 ok=G(Api3,0x6fcd64)(G(u32,0x6fcd80),thread,info);u32 ctx[5]={0x14,0,0,0,0};char text[64];
 const char*module=ok?(const char*)info+0x1c:(const char*)0x677058;
 if(G(Api4,0x6fcd5c)(G(u32,0x6fcd80),thread,&line,ctx)){
  u32 base=ext_41d500((void*)ctx[3])+1;G(Format,0x6761e4)(text,0x677064,base,ctx[2],line);
 }else{G(Api0,0x67609c)();text[0]=0;}
 if(G(Api4,0x6fcd6c)(G(u32,0x6fcd80),thread,&line,G(void*,0x6e4084)))ext_41e010(0x677078,module,thread,G(u32,0x6e4084)+0x14,text);
 else {G(Api0,0x67609c)();ext_41e010(0x67708c,module,thread,text);}
 --G(u32,0x6fcd7c);if(!G(u32,0x6fcd7c))G(Api1,0x6fcd54)(G(Api0,0x6760ac)());
}
PCREG(41d540,fn41d540);
