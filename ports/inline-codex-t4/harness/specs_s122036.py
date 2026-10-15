from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x30);key=r.getrandbits(32);e.w32(s+0x1c,key);e.w32(s+0x18,r.choice([0,1,2,3]))
 dst=rnd(c,36);src=rnd(c,36);basis=rnd(c,36)
 for p in [src,basis]:
  for j in range(9):e.wbytes(p+4*j,struct.pack('<f',r.uniform(-2,2)))
 o=obj(c,0x20,{0x38:pystub(c,0,this=True,ret=dst),0x40:pystub(c,0,this=True,ret=src),0x3c:pystub(c,0,this=True,ret=basis)})
 return [s,o,key if r.randrange(4) else key^1]
S(0x5a7560,'GUESS construct orientation for matching key','thiscall',None,ret='al',gen=gen)
