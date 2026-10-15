#include "ff.h"
static void convert(u8*encoding,u8**input,u8*inputend,u16**output,u16*outputend){
 u8*p=*input;u16*q=*output;while(p!=inputend&&q!=outputend){u8 c=*p,kind=encoding[0x4c+c];
 if(kind==5){*q++=((c&31)<<6)|(p[1]&63);p+=2;}
 else if(kind==6){*q++=((u16)(s16)(s8)c<<12)|((p[1]&63)<<6)|(p[2]&63);p+=3;}
 else if(kind==7){if(q+1==outputend)continue;u32 cp=((c&7)<<18)|((p[1]&63)<<12)|((p[2]&63)<<6)|(p[3]&63);cp-=0x10000;q[0]=(cp>>10)|0xd800;q[1]=(cp&0x3ff)|0xdc00;q+=2;p+=4;}
 else{*q++=(s16)(s8)c;++p;}
 }
 *input=p;*output=q;
}
PCREG(622db0,convert);
