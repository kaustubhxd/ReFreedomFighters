#include "ff.h"
static inline u32 &D(u8 *s,u32 o){return *(u32*)(s+o);}
static inline u16 &H(u8 *s,u32 o){return *(u16*)(s+o);}
static void sendbits(u8 *s,u32 code,u32 length){
 u32 valid=D(s,0x16b4);
 if((s32)valid>16-(s32)length){
  H(s,0x16b0)|=(u16)((code&0xffff)<<(valid&31));
  u8 *out=*(u8**)(s+8);
  out[D(s,0x14)++]=(u8)H(s,0x16b0);
  out[D(s,0x14)++]=(u8)(H(s,0x16b0)>>8);
  H(s,0x16b0)=(u16)code>>((16-valid)&31);
  D(s,0x16b4)+=length-16;
 }else{
  H(s,0x16b0)|=(u16)((code&0xffff)<<(valid&31));
  D(s,0x16b4)=valid+length;
 }
}
static inline void sendcode(u8 *s,u32 c){sendbits(s,H(s,0xa74+c*4),H(s,0xa76+c*4));}
static void fn631100(u8 *s,u8 *tree,s32 max_code){
 s32 prev=-1,count=0;
 u32 next=H(tree,2);
 s32 max_count=next?7:138,min_count=next?4:3;
 for(s32 n=0;n<=max_code;n++){
  u32 cur=next;next=H(tree,(n+1)*4+2);++count;
  if(count<max_count && cur==next)continue;
  if(count<min_count){do{sendcode(s,cur);}while(--count);}
  else if(cur){
   if((s32)cur!=prev){sendcode(s,cur);--count;}
   sendcode(s,16);sendbits(s,count-3,2);
  }else if(count<=10){sendcode(s,17);sendbits(s,count-3,3);}
  else {sendcode(s,18);sendbits(s,count-11,7);}
  count=0;prev=cur;
  if(!next){max_count=138;min_count=3;}
  else if(cur==next){max_count=6;min_count=3;}
  else {max_count=7;min_count=4;}
 }
}
PCREG(631100,fn631100);
