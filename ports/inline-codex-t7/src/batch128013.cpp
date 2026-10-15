#include "ff.h"

extern "C" void ext_62f1e0(u8 *s);                              // fill_window
extern "C" u32 ext_62f430(u8 *s, u32 cur);                      // longest_match
extern "C" void ext_62fe10(u8 *s, u8 *buf, u32 len, u32 last);  // _tr_flush_block
extern "C" void *ext_634d22(void *d, const void *src, u32 n);   // memcpy

static inline u32 &W(u8 *p, u32 off) { return *(u32 *)(p + off); }
static inline u16 &H(u8 *p, u32 off) { return *(u16 *)(p + off); }

static inline void flushBlock(u8 *s, u32 last) {
  s32 bs = (s32)W(s, 0x54);
  u8 *buf = bs >= 0 ? (u8 *)W(s, 0x30) + bs : 0;
  ext_62fe10(s, buf, W(s, 0x64) - W(s, 0x54), last);
  W(s, 0x54) = W(s, 0x64);
  u8 *strm = *(u8 **)s;
  u8 *st = *(u8 **)(strm + 0x1c);
  u32 n = W(st, 0x14);
  if (n > W(strm, 0x10)) n = W(strm, 0x10);
  if (n) {
    ext_634d22(*(void **)(strm + 0xc), *(void **)(st + 0x10), n);
    W(strm, 0xc) += n;
    W(*(u8 **)(strm + 0x1c), 0x10) += n;
    W(strm, 0x14) += n;
    W(strm, 0x10) -= n;
    W(*(u8 **)(strm + 0x1c), 0x14) -= n;
    st = *(u8 **)(strm + 0x1c);
    if (W(st, 0x14) == 0) W(st, 0x10) = W(st, 8);
  }
}

static inline u32 insertString(u8 *s, u32 pos) {
  u32 h = ((W(s, 0x40) << (W(s, 0x50) & 31)) ^ (*(u8 *)(W(s, 0x30) + pos + 2))) & W(s, 0x4c);
  W(s, 0x40) = h;
  u32 head = H((u8 *)W(s, 0x3c), h * 2);
  H((u8 *)W(s, 0x38), (W(s, 0x2c) & pos) * 2) = (u16)head;
  H((u8 *)W(s, 0x3c), W(s, 0x40) * 2) = (u16)pos;
  return head;
}
static inline bool tallyLiteral(u8 *s, u8 c) {
  u32 ll = W(s, 0x1698);
  H((u8 *)W(s, 0x169c), ll * 2) = 0;
  *((u8 *)W(s, 0x1690) + W(s, 0x1698)) = c;
  W(s, 0x1698)++;
  (*(u16 *)(s + c * 4 + 0x8c))++;
  return W(s, 0x1698) == W(s, 0x1694) - 1;
}

static u32 fast14(u8*s,u32 flush){
 u32 head=0;
 for(;;){
  if(W(s,0x6c)<262){ext_62f1e0(s);if(W(s,0x6c)<262 && !flush)return 0;if(!W(s,0x6c))break;}
  if(W(s,0x6c)>=3)head=insertString(s,W(s,0x64));
  if(head && W(s,0x64)-head<=W(s,0x24)-262 && W(s,0x80)!=2)W(s,0x58)=ext_62f430(s,head);
  bool full;
  if(W(s,0x58)>=3){
   u16 dist=(u16)(W(s,0x64)-W(s,0x68));u8 length=(u8)(W(s,0x58)-3);u32 at=W(s,0x1698);
   H((u8*)W(s,0x169c),at*2)=dist;*((u8*)W(s,0x1690)+at)=length;++W(s,0x1698);
   ++H(s,0x490+G(u8,0x6c0738+length)*4);
   u16 d=dist-1;u32 code=d<256?G(u8,0x6c0838+d):G(u8,0x6c0938+(d>>7));++H(s,0x980+code*4);
   full=W(s,0x1698)==W(s,0x1694)-1;u32 len=W(s,0x58);W(s,0x6c)-=len;
   if(len<=W(s,0x78) && W(s,0x6c)>=3){
    --W(s,0x58);do{++W(s,0x64);head=insertString(s,W(s,0x64));--W(s,0x58);}while(W(s,0x58));++W(s,0x64);
   }else{
    W(s,0x64)+=len;W(s,0x58)=0;u8*p=(u8*)W(s,0x30)+W(s,0x64);W(s,0x40)=((p[0]<<(W(s,0x50)&31))^p[1])&W(s,0x4c);
   }
  }else{full=tallyLiteral(s,*((u8*)W(s,0x30)+W(s,0x64)));--W(s,0x6c);++W(s,0x64);}
  if(full){flushBlock(s,0);if(!W(*(u8**)s,0x10))return 0;}
 }
 flushBlock(s,flush==4);
 if(!W(*(u8**)s,0x10))return flush==4?2:0;
 return flush==4?3:1;
}
PCREG(62e3c0,fast14);
