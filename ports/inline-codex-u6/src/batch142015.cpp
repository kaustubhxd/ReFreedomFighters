#include "ff.h"
static u32 THISCALL insert(u8* me,u32 value,float key,u32 mode){
 u8* node=*(u8**)(me+0x28);u32 result;
 auto k=[&](u8* p){return *(float*)(p+*(u32*)(me+0x18)*4-12);};
 if(node){
  while(node && k(node)>key)node=vcall<u8*>(me,0x90,node);
  if(mode==1){while(node && k(node)>=key)node=vcall<u8*>(me,0x90,node);}
  if(!node){result=vcall<u32>(me,0x84,value);goto done;}
 }else{
  u8* tail=*(u8**)(me+0x1c);if(tail)node=tail+(2-*(u32*)(me+0x18))*4;
 }
 while(node && key>k(node))node=vcall<u8*>(me,0x94,node);
 if(mode==2){while(node && key>=k(node))node=vcall<u8*>(me,0x94,node);}
 if(!node)result=vcall<u32>(me,0x88,value);else result=vcall<u32>(me,0x8c,node,value);
 done:*(float*)(result+*(u32*)(me+0x18)*4-16)=key;*(u32*)(me+0x28)=result-4;return result;
}
PCREG(4cd730,insert);
