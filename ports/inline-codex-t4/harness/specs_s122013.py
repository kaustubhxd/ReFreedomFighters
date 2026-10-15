from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x40);out=rnd(c,12*8);pts=rnd(c,52*8)
 for i in range(8):
  for j in range(3):e.wbytes(pts+52*i+12+4*j,struct.pack('<f',r.choice([0.,-0.,r.uniform(-10000,10000)])))
 e.w32(s+0x13,out);e.w32(s+0xf,pts);e.w32(s+0x2c,8)
 log=obj(c,0x20,{0x2c:pystub(c,2,pop=0)})
 sys=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,sys)
 return [s,r.choice([-1,0,1,7,8,9]),r.randrange(8),r.randrange(8)]
S(0x545d60,'GUESS set indexed edge distance','thiscall',None,ret=None,gen=gen)
