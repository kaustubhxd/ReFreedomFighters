#include "ff.h"
static inline int ci3(u32 key,void*arg){return (*(int (**)(u32,void*))0x676414)(key,arg);}
static void help3(){
 const u32 msg[]={0x679a84,0x679a94,0x679aa8,0x679abc,0x679ad0,0x679ae0,0x679afc,0x679b10,0x679b20,0x6781a4,0x6782bc,0x679b34,0x6781fc,0x678224,0x678308,0x679b44,0x678400,0x679b50,0x679b60,0x679b70,0x679b78,0x679b98};
 for(u32 i=0;i<22;++i){
  u32 line=0x20d+i+(i>=2);
  void*log=vcall<void*>(G(void*,0x700390),0x20,0x6799acu,line);
  ((void(*)(void*,u32))(*(u32*)(*(u8**)log+0x2c)))(log,msg[i]);
 }
}
static u8 THISCALL command3(u8*self,void*name,u32 value){
 if(!ci3(0x679a48,name)||!ci3(0x679a58,name))return 1;
 if(!ci3(0x679a60,name)){
  void*sub=*(void**)(self+0x9b);if(sub)vcall<void>(sub,0x12c,2u,value,0u);
 }else if(!ci3(0x679a6c,name))vcall<void>(self,0x20,0u);
 else if(!ci3(0x679a78,name))vcall<void>(G(void*,0x700394),0x74);
 else if(!ci3(0x679a80,name))help3();
 else if(!ci3(0x679bc0,name))vcall<void>(G(void*,0x70038c),0x84);
 else if(*(void**)(self+0x9b)){
  u8 first[512],second[512];for(u32 i=0;i<512;++i)first[i]=second[i]=0xcc;
  vcall<void>(self,0x68,name,first,second);
  vcall<void>(*(void**)(self+0x9b),0x12c,0u,first,second);
 }
 return 1;
}
PCREG(42c4c0,command3);
