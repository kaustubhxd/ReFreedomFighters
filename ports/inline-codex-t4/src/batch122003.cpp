#include "ff.h"
extern "C" u8* ext_41e290(u32);
extern "C" void THISCALL ext_4fdb70(u8*);
static u8* THISCALL fn4fbb20(u8* s,u8* arg){
 u8* mgr=*(u8**)(*(u8**)(s+0x44)+0x18);
 vcall<void>(mgr,4,*(u32*)arg);
 u8* n=ext_41e290(21);
 if(!n)return 0;
 u32 id=*(u32*)arg;float value=*(float*)(arg+4);
 n[20]=1;*(u8**)(n+16)=s;*(u32*)n=id;
 u8* last=*(u8**)(s+0x4c);
 *(u8**)(n+8)=last;*(u32*)(n+12)=0;
 if(last)*(u8**)(last+12)=n;else *(u8**)(s+0x48)=n;
 *(u8**)(s+0x4c)=n;
 float old=*(float*)(n+4);
 if(old!=value){*(float*)(n+4)=value;ext_4fdb70(n);}
 return n;
}
PCREG(4fbb20,fn4fbb20);
