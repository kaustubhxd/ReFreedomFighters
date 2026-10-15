#include "ff.h"
#define U(p,o) (*(u32 *)((u8 *)(p)+(o)))
extern "C" void THISCALL ext_54e1f0(void *,void *,u32,u32 *,u32);
extern "C" void *ext_634d10(void *,u32,u32);
static s32 FASTCALL adpcm54d470(u8 *s,u16 *out,u32 unused,u32 loop,u32 unused2,s32 blocks,s32 total,s32 count) {
 s32 pred=U(s,0),index=U(s,4),block=U(s,8),nibble=U(s,16),done=U(s,24);
 u32 chunk=U(s,12),packed=0;u8 *input=(u8 *)U(s,20);
 auto refill=[&]()->bool {if(!U(s,0x4020)){u8 *st=(u8 *)U(s,0x4024);if(!st)return false;u32 size;ext_54e1f0(st,s+32,U(st,0x47),&size,0);U(s,0x4020)=size;input=s+32;if(!size)return false;}return true;};
outer:
 if(!count)goto finish;
 if(!block) {
  if(!refill())goto finish;
  u32 header=U(input,0);input+=4;U(s,0x4020)-=4;
  index=(header>>16)&255;pred=(s16)header;block=1;*out++=(u16)header;done++;count--;nibble=0;
 }
checkblock:
 if(block>=blocks+1){block=0;goto outer;}
 if(done>=total){if(loop&255){done=0;goto outer;}ext_634d10(out,0,count*2);goto finish;}
 if(nibble>=8)goto nextblock;
nextnibble:
 if(count<1)goto finish;
 if(!nibble){if(!refill())goto finish;chunk=U(input,0);input+=4;U(s,0x4020)-=4;}
 {
  u32 code=(chunk>>((nibble&~1)*4))&255;if(nibble&1)code>>=4;else code&=15;
  s32 step=G(s32,0x6a3c68+index*4);s32 diff=(step>>3)+((code&4)?step:0)+((code&2)?(step>>1):0)+((code&1)?(step>>2):0);
  pred+=(code&8)?-diff:diff;if(pred>32767)pred=32767;if(pred< -32768)pred=-32768;
  if(nibble&1){if(count==1){*out=(u16)packed;count=0;done++;}else{packed|=(u32)pred<<16;out[0]=(u16)packed;out[1]=(u16)(packed>>16);out+=2;count-=2;done+=2;}}
  else packed=(u16)pred;
  u32 magnitude=code&7;if(magnitude<4)index--;else index+=magnitude*2-6;if(index>88)index=88;if(index<0)index=0;
 }
 nibble++;if(nibble<8)goto nextnibble;
nextblock:
 nibble=0;block++;goto checkblock;
finish:
 U(s,0)=pred;U(s,4)=index;U(s,8)=block;U(s,12)=chunk;U(s,16)=nibble;U(s,20)=(u32)input;U(s,24)=done;return count;
}
PCREG(54d470,adpcm54d470);
