#include "ff.h"
static void THISCALL fn52d250(u8* s,u32 headarg,u32 idarg){
 u16 id=(u16)idarg;u8* table=*(u8**)(s+0x98);u8* node=table+21*id;u16 prev=*(u16*)(node+18);
 if(prev){u8* p=table+21*prev;*(u16*)(p+16)=*(u16*)(node+16);u16 next=*(u16*)(node+16);if(next)*(u16*)(table+21*next+18)=*(u16*)(node+18);
  u16 cur=*(u16*)(node+18);
  while(cur){p=table+21*cur;if(*(float*)(node+10)>=*(float*)(p+10)){*(u16*)(node+18)=cur;*(u16*)(node+16)=*(u16*)(p+16);u16 n=*(u16*)(p+16);*(u16*)(table+21*n+18)=id;*(u16*)(p+16)=id;return;}cur=*(u16*)(p+18);}return;
 }
 u16 head=(u16)headarg;u8* p=table+21*head;u8* next=0;
 if(*(u16*)(p+16)){
  do{u16 n=*(u16*)(p+16);next=table+21*n;if(*(float*)(next+10)>=*(float*)(node+10))break;head=n;p=next;}while(*(u16*)(p+16));
 }
 *(u16*)(node+18)=head;*(u16*)(node+16)=*(u16*)(p+16);if(*(u16*)(p+16))*(u16*)(next+18)=id;*(u16*)(p+16)=id;
}
PCREG(52d250,fn52d250);
