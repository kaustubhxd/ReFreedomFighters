#include "ff.h"
extern "C" void THISCALL ext_42ffc0(u8**);
extern "C" u32* THISCALL ext_5fb400(void*,u32*,u8*,u8*,u32*);
static s32 cmp(u32 a,u32 ae,u32 b,u32 be){s32 na=ae-a,nb=be-b;typedef s32(*Compare)(u32,u32,u32);s32 v=G(Compare,0x676408)(a,b,na<nb?na:nb);return v?v:(na<nb?-1:na>nb?1:0);}
static u8* THISCALL insert(u8*me,u8*out,u32*key){
 u8*head=*(u8**)me,*parent=head,*node=*(u8**)(head+1);bool left=true;
 while(node){parent=node;left=cmp(key[0],key[1],*(u32*)(node+13),*(u32*)(node+17))<0;node=*(u8**)(node+(left?5:9));}
 u8*prev=parent;
 if(left){if(parent==*(u8**)(head+5))goto create;ext_42ffc0(&prev);}
 if(cmp(*(u32*)(prev+13),*(u32*)(prev+17),key[0],key[1])>=0){*(u8**)out=prev;out[4]=0;return out;}
create:
 u32 local;auto result=ext_5fb400(me,&local,node,parent,key);*(u32*)out=*result;out[4]=1;return out;
}
PCREG(5fc480,insert);
