#include "ff.h"
static u32 THISCALL fn658e00(u8* s,u32* out,u32 limit){
 if(!s[0x3f]||*(u32*)(s+0x48)+0x90==0||!*(u32*)(s+0x38))return 0;
 u8* owner=*(u8**)(*(u8**)(s+0x38)+0x54);u8* data=vcall<u8*>(owner,0x24c);u32 count=0,i=0;
 while(i!=*(u32*)(data+0x69)){
  u8* record=data+0x6d+56*i;u8* tab=*(u8**)(G(u8*,0x70039c)+0x9b);u8* node=vcall<u8*>(tab,0x54,*(u32*)record);
  if(!node){--*(u32*)(data+0x69);u8* last=data+0x6d+56*(*(u32*)(data+0x69));for(u32 j=0;j<56;++j)record[j]=last[j];continue;}
  if(!(*(u32*)(node+0x3c)&0x2c00)){out[count]= (u32)node;++count;if((u32)(count==0)==limit)break;}
  ++i;
 }
 return count;
}
PCREG(658e00,fn658e00);
