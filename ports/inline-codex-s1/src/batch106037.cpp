#include "ff.h"
extern "C" u32 THISCALL ext_4e5e60(void*);
extern "C" u32 THISCALL ext_4e5e40(void*);
extern "C" float THISCALL ext_4e5e80(void*);
static void THISCALL copy_event(u8* me,u8** reader){
 if(!*reader)return;
 u8 flag=ext_4e5e60(reader)!=0;me[0x63]=flag;
 u8 type=**reader;
 if(type!=0xff && (type&0x3f)==2)me[0x5e]=0;
 else {me[0x5e]=flag;me[0x63]=ext_4e5e60(reader)!=0;}
 *(float*)(me+0x5a)=ext_4e5e80(reader);
 me[0x60]=ext_4e5e60(reader)!=0;me[0x61]=ext_4e5e60(reader)!=0;
 *(u16*)(me+0x48)=(u16)ext_4e5e40(reader);
 me[0x5f]=ext_4e5e60(reader)!=0;
 type=**reader;
 if(type!=0xff && (type&0x3f)==3){
  me[0x62]=ext_4e5e60(reader)!=0;me[0x64]=ext_4e5e60(reader)!=0;
  *(u32*)(me+0x4e)=ext_4e5e60(reader);*(u32*)(me+0x52)=ext_4e5e60(reader);
 }
}
PCREG(4a4ad0,copy_event);
