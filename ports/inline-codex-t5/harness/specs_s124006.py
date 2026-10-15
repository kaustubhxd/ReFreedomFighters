from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 vals=[r.getrandbits(32) for _ in range(r.randrange(5))]
 def begin(em,k):
  for i in range(3):em.w32(em.arg32(0)+4*i,0)
 def advance(em,k):em.w32(em.arg32(0),1 if k<len(vals) else 0)
 listing=obj(c,0x20,{0x4c:pystub(c,1,this=True,stackmark=[0],side=begin),0x5c:pystub(c,1,this=True,stackmark=[0],side=advance,ret=lambda em,k:vals[k] if k<len(vals) else 0)})
 backing=rnd(c,0x20);e.w32(backing+0x18,r.choice([0,listing,listing]))
 draw=obj(c,0x20,{0x12c:pystub(c,3,this=True)})
 target=rnd(c,0x100);e.wbytes(target+0x88,struct.pack('<f',r.choice([0.,1.,-1.,float('inf'),float('nan'),r.uniform(-100,100)])))
 ref=obj(c,0x20,{0x60:pystub(c,1,this=True,ret=r.choice([0,target,target]))})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,ref);e.w32(sys+0x40,r.getrandbits(32))
 manager=rnd(c,0x20);e.w32(0x7003b8,manager)
 sound=rnd(c,0x20)
 hook_rec(c,0x589c20,1,this=True,ret=r.choice([0,sound,sound]))
 hook_rec(c,0x59a5b0,3,this=True)
 me=rnd(c,0xa30);e.w32(me+0x180,backing);e.w32(me+0x44,draw)
 return [me]
S(0x566a10,'GUESS refresh entries and timed transition','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124006')
