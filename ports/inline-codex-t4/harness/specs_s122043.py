from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 vals=[r.uniform(-100,100) for _ in range(3)]
 dmg=obj(c,0x20,{0x324:pystub(c,0,this=True,st0=lambda em,k:vals[k]),0x328:pystub(c,0,this=True,st0=r.uniform(-100,100))})
 target=obj(c,0x20,{0x328:pystub(c,0,this=True,ret=dmg if r.randrange(5) else 0)})
 log=obj(c,0x20,{0x2c:pystub(c,2,pop=0)});logger=obj(c,0x20,{0x20:pystub(c,2,this=True,ret=log)});e.w32(0x700390,logger)
 s=rnd(c,0xc0);low=r.uniform(1,10);high=low+r.uniform(1,10)
 for off,v in [(0xb0,low),(0xb4,high),(0xb8,r.uniform(-5,5))]:e.wbytes(s+off,struct.pack('<f',v))
 return [s,target,F(r.choice([0.,low,high,high+5,(low+high)*0.5,r.uniform(-5,30)]))]
S(0x46b4c0,'GUESS distance dependent damage','thiscall',None,ret='st0',gen=gen)
