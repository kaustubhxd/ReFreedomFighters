#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(u8*,u32);
static void report50(u32 line,u32 text){
 u8* log=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x69c8e0,line);typedef void(*Log)(u8*,u32,u32);(*(Log*)(*(u8**)log+0x2c))(log,0x69c6b0,text);typedef void(*Assert)();(*(Assert*)0x7003b0)();
}
static void THISCALL fn50a670(u8*,u8* args){
 u8* in=ext_5003d0(*(u8**)(args+4),0);u32 key=0;
 if(in[4]==3)key=*(u32*)in;else if(in[4]==4)key=vcall<u32>(*(u8**)in,0x34);else report50(0x111,0x69c9b0);
 u8* tab=*(u8**)(G(u8*,0x70039c)+0x9b);u8* query=vcall<u8*>(tab,0x134);float value=0;vcall<void>(query,0x84,key,&value);
 u8* out=ext_5003d0(*(u8**)(args+8),0);
 if(out[4]!=0&&out[4]!=2){report50(0xd5,0x69c938);return;}
 *(float*)out=value;out[4]=2;
}
PCREG(50a670,fn50a670);
