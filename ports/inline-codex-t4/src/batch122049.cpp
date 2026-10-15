#include "ff.h"
extern "C" u8* THISCALL ext_5003d0(u8*,u32);
extern "C" void THISCALL ext_5002f0(u8*,u32);
extern "C" void THISCALL ext_5057e0(u8*,u32,u32);
static void check49(u8* value){if(value[4]!=0&&value[4]!=2){u8* log=vcall<u8*>(G(u8*,0x700390),0x20,(u32)0x69c8e0,(u32)0x104);typedef void(*Log)(u8*,u32,u32);(*(Log*)(*(u8**)log+0x2c))(log,0x69c6b0,0x69c938);typedef void(*Assert)();(*(Assert*)0x7003b0)();}}
static void THISCALL fn504960(u8* s,u8* args){
 s32 id=*(s32*)ext_5003d0(*(u8**)(args+4),0);
 if(id<=0){ext_5057e0(s,0x69ce50,(u32)id);ext_5002f0(ext_5003d0(*(u8**)(args+8),0),0);return;}
 u8* p=*(u8**)(*(u8**)(G(u8*,0x70039c)+0x9b)+0x44)+id;
 u8* a=ext_5003d0(*(u8**)(args+4),2);check49(a);float y=*(float*)a;
 a=ext_5003d0(*(u8**)(args+4),1);check49(a);float x=*(float*)a;
 u32 result=vcall<u32>(s,0x60,p,(float)*(s32*)(p+0x60),(float)*(s32*)(p+0x64),x,y);
 ext_5002f0(ext_5003d0(*(u8**)(args+8),0),result);
}
PCREG(504960,fn504960);
