from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu;e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 target=obj(c,0x20,{0x2dc:pystub(c,4,this=True)})
 me=obj(c,0xc0,{0x35c:pystub(c,1,this=True),0x2c4:pystub(c,0,this=True,ret=target)})
 table=obj(c,0x20,{0x4c:pystub(c,1,this=True,ret=r.getrandbits(32))})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,table)
 backing=rnd(c,0x30);e.w32(me+8,backing);e.w32(me+0x8f,r.choice([0,1]));e.w32(me+0xab,r.choice([0,1,2,100,0xffffffff,0x7fffffff,r.getrandbits(32)]));e.wbytes(me+0xb3,bytes([r.choice([0,1,2])]))
 vec=rnd(c,8)
 for p in [vec,me+0x9f,backing+0x24]:e.wbytes(p,struct.pack('<2f',*[r.choice([0.,1.,-1.,float('nan'),float('inf'),r.uniform(-100,100)]) for _ in range(2)]))
 e.wbytes(me+0xa7,struct.pack('<f',r.choice([0.,1.,-1.,float('nan'),r.uniform(-10,10)])))
 return [me,vec]
S(0x4fa400,'GUESS clamp slider and send normalized value','thiscall',None,ret='al',gen=g,nan_heap=True,note='batch124015',tries=2)
