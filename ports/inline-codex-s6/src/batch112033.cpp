#include "ff.h"
extern "C" u32 THISCALL ext_45d380(void*,u32,u32);
static u32 THISCALL command(u8*me,u32 code,u32 arg){
 u16 id=code;
 if(id==*(u16*)(me+0x1fd)){auto state=*(u8**)(me+0x5c);if(*(u32*)(state+0x4b)||me[0x133])vcall<void>(me,0x2c4);}
 else if(id==*(u16*)(me+0x209)||id==*(u16*)(me+0x20b)){
 bool add=id==*(u16*)(me+0x209);if(me[0x11e])vcall<void>(me,add?0x2dc:0x2e0,arg,*(u32*)(me+0x11f));
 auto table=*(void**)(G(u8*,0x70039c)+0x9b);u32 value=vcall<u32>(table,0x58,arg);u32 n=*(u32*)(me+0xda),i=0;auto a=(u32*)(me+0xde);while(i<n&&a[i]!=value)++i;
 if(add){if(i==n){a[n]=value;++*(u32*)(me+0xda);}}
 else if(i!=n){a[i]=a[n-1];--*(u32*)(me+0xda);}
 }
 return ext_45d380(me,code,arg);
}
PCREG(5122f0,command);
