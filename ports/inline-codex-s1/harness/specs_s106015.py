import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,clear_hooks,pystub

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 owner=obj(c,0x440,{0x534:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101]))})
 e.w32(owner+0x417,r.choice([0,0x400,0x800,0xc00]))
 me=rnd(c,0x140);e.w32(me+4,owner);e.wf32(me+0xc,r.choice(EDGE_F+[r.uniform(-10,10)]))
 for off in [0xdd,0xf5,0x10d]:
  ptr=rnd(c,4)
  tr=obj(c,16,{0x14:pystub(c,1,this=True,ret=r.choice([0,ptr])),0xc:pystub(c,1,this=True,st0=r.choice(EDGE_F+[r.uniform(-10,10)])),4:pystub(c,0,this=True)})
  e.w32(me+off,e.r32(tr))
 e.w32(0x7003b0,pystub(c,0))
 return [me,rnd(c,4)]+[r.getrandbits(32) for _ in range(4)]
S(0x488900,'sample selected track','thiscall',None,ret='st0',gen=gen,nan_heap=True)
