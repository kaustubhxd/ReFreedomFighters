from pilot import S
from recruits_util import rnd,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 encoding=rnd(c,0x150)
 for i in range(256):e.wbytes(encoding+0x4c+i,bytes([5 if 0xc0<=i<=0xdf else 6 if 0xe0<=i<=0xef else 7 if 0xf0<=i<=0xf7 else 0]))
 chars=[]
 for _ in range(r.randrange(0,20)):
  cp=r.choice([r.randrange(0x80),r.randrange(0x80,0x800),r.randrange(0x800,0xd800),r.randrange(0x10000,0x110000)]);chars.append(cp)
 data=''.join(map(chr,chars)).encode();units=[2 if cp>=0x10000 else 1 for cp in chars];total=sum(units);cap=r.randrange(total+3);used=0
 for u in units:
  if u==2 and cap-used==1:cap+=1;break
  used+=u
 source=rnd(c,len(data)+8);e.wbytes(source,data);inp=rnd(c,4);e.w32(inp,source);dest=rnd(c,2*(total+3));out=rnd(c,4);e.w32(out,dest)
 return [encoding,inp,source+len(data),out,dest+2*cap]
S(0x622db0,'GUESS utf8_to_utf16','cdecl',None,ret=None,gen=gen,note='valid UTF8; avoids original nonprogress loop when a surrogate pair has only one output slot')
