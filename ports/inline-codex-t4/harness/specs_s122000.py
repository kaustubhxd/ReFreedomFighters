from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c)
 e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,ret=r.getrandbits(32),pop=0)
 hook_rec(c,0x562440,0,this=True)
 hook_rec(c,0x57dd10,0,this=True)
 s=rnd(c,0x380)
 for off in (0x310,0x314,0x54):
  ch=obj(c,0x20,{0x70:pystub(c,1,this=True,deref={0:3})})
  data=rnd(c,0x60)
  for k in range(3):e.wbytes(data+0x24+4*k,struct.pack('<f',r.choice([0.,-0.,1.,-3.5,r.uniform(-10000,10000)])))
  e.w32(ch+8,data);e.w32(s+off,ch)
 return [s]
S(0x57d8a0,'GUESS init child offsets','thiscall',None,ret=None,gen=gen)
