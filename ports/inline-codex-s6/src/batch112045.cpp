#include "ff.h"
static void THISCALL notify(u8*me,u32 id){
 auto list=me+0x4c;u32 it[3];vcall<void>(list,0x4c,it);u32 value=vcall<u32>(list,0x5c,it);bool found=false;while(it[0]){if(value==id){found=true;break;}value=vcall<u32>(list,0x5c,it);}
 if(found){if(!me[0x1ba]&&me[0x1b9])return;me[0x1b9]=1;}else{if(!me[0x1b9])return;me[0x1b9]=0;}
 auto table=*(u8**)(G(u8*,0x70039c)+0x9b);u32 object=vcall<u32>(table,0x58,id);table=*(u8**)(G(u8*,0x70039c)+0x9b);if(object==*(u32*)(table+0xadc)){vcall<void>(me,0x8c,1);return;}
 if(*(u32*)(me+0x1cf)!=1||*(u32*)(me+0x1cb)){if(found)vcall<void>(me,0x84,(u32)*(u16*)(me+0x1a8));else vcall<void>(me,0x94,(u32)*(u16*)(me+0x1aa),0);}
 vcall<void>(me,0x8c,0);
}
PCREG(4bef70,notify);
