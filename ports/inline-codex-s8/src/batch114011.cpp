#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" u32 ext_410100(void *);extern "C" u32 ext_410110(void *);extern "C" u32 ext_410120(void *);extern "C" u32 ext_410130(void *);extern "C" u64 ext_410140(void *);extern "C" u32 ext_410220(void *);extern "C" u32 ext_410250(void *);
extern "C" void ext_410420(void *,u32);extern "C" void ext_4103f0(void *,u32);extern "C" void *ext_634d28(void *,void *,u32);
static s32 page4106f0(u8 *s,u8 *page) {
 u8 *hdr=(u8 *)U(page,0),*payload=(u8 *)U(page,8);u32 bytes=U(page,12);
 u32 version=ext_410100(page),continuation=ext_410110(page),continued=ext_410120(page),bad=ext_410130(page);u64 granule=ext_410140(page);u32 serial=ext_410220(page),number=ext_410250(page),n=hdr[26],skip=0;
 u32 consumed=U(s,12);if(consumed){U(s,8)-=consumed;if(U(s,8))ext_634d28((void *)U(s,0),(void *)(U(s,0)+consumed),U(s,8));U(s,12)=0;}
 u32 used=U(s,36);if(used){u32 count=U(s,28);if(count!=used){ext_634d28((void *)U(s,16),(void *)(U(s,16)+used*4),(count-used)*4);ext_634d28((void *)U(s,20),(void *)(U(s,20)+used*8),(U(s,28)-used)*8);}U(s,28)-=used;U(s,32)-=used;U(s,36)=0;}
 if(serial!=U(s,0x150)||(s32)version>0)return -1;
 ext_410420(s,n+1);
 if(number!=U(s,0x154)) {
  u32 start=U(s,32),count=U(s,28);for(u32 i=start;i<count;i++)U(s,8)-=U(U(s,16),i*4)&255;U(s,28)=start;
  if(U(s,0x154)!=0xffffffff){U(U(s,16),start*4)=0x400;U(s,28)++;U(s,32)++;}
  if(continuation){continued=0;while(skip<n){u32 v=hdr[27+skip++];payload+=v;bytes-=v;if(v<255)break;}}
 }
 if(bytes){ext_4103f0(s,bytes);u8 *dst=(u8 *)(U(s,0)+U(s,8));for(u32 i=0;i<bytes;i++)dst[i]=payload[i];U(s,8)+=bytes;}
 s32 last=-1;
 for(u32 i=skip;i<n;i++) {
  u32 v=hdr[27+i],idx=U(s,28);U(U(s,16),idx*4)=v;U(U(s,20),idx*8)=0xffffffff;U(U(s,20),idx*8+4)=0xffffffff;
  if(continued){continued=0;U(U(s,16),idx*4)|=0x100;}
  if(v<255)last=idx;U(s,28)++;if(v<255)U(s,32)=U(s,28);
 }
 if(last!=-1){U(U(s,20),last*8)=(u32)granule;U(U(s,20),last*8+4)=(u32)(granule>>32);}
 if(bad){U(s,0x148)=1;if((s32)U(s,28)>0)U(U(s,16),U(s,28)*4-4)|=0x200;}
 U(s,0x154)=number+1;return 0;
}
PCREG(4106f0,page4106f0);
