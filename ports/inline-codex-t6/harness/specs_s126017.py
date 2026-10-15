from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0x30);dest=rnd(c,36);src=rnd(c,36);other=rnd(c,36)
 e.wbytes(me+0x18,bytes([r.randrange(2)]))
 for p in [src,other]:e.wbytes(p,struct.pack('<9f',*[r.uniform(-2,2) for _ in range(9)]))
 if r.random()<0.4:
  e.wbytes(src,struct.pack('<3f',1,0,0));e.wbytes(other,struct.pack('<3f',0,1,0))
 o=obj(c,0x20,{0x38:pystub(c,0,this=True,ret=dest),0x40:pystub(c,0,this=True,ret=src),0x3c:pystub(c,0,this=True,ret=other)})
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 return [me,o,r.getrandbits(32)]
S(0x44c660,'GUESS construct orientation basis','thiscall',None,ret='al',gen=gen)
