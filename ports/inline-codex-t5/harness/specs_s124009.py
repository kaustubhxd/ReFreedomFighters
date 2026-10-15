from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 hook_rec(c,0x633654,0,pop=0)
 words=[r.choice([0,1,0xffff,r.getrandbits(32)]) for _ in range(2)]
 hook_rec(c,0x4e5e40,0,this=True,ret=lambda em,k:words[k])
 hook_rec(c,0x4e5e80,0,this=True,st0=r.choice([0.,1.,-1.,float('nan'),float('inf'),r.uniform(-100,100)]))
 hook_rec(c,0x4e5e60,0,this=True,ret=r.choice([0,0,1,2,0x100]))
 vals=[r.getrandbits(32) for _ in range(3)]
 def init(em,k):
  for i in range(3):em.w32(em.arg32(0)+4*i,vals[i])
 hook_rec(c,0x4db500,1,this=True,stackmark=[0],side=init)
 window=obj(c,0xb0,{0x378:pystub(c,1,this=True),0x70:pystub(c,1,this=True,deref={0:3})})
 e.w32(window+8,rnd(c,0x20));e.wbytes(window+0x9b,struct.pack('<f',r.choice([0.,1.,-1.,640.,r.uniform(-1000,1000),float('nan'),float('inf')])))
 sys=rnd(c,0xb0);e.w32(0x70039c,sys)
 for off in [0x6f,0x73]:e.w32(sys+off,r.choice([0,1,640,480,0xffffffff,0x80000000,r.getrandbits(32)]))
 me=obj(c,0x70,{0x64:pystub(c,1,this=True)})
 e.w32(me+0x44,window)
 return [me,r.getrandbits(32),rnd(c,0x20)]
S(0x4f66b0,'GUESS read configuration and center window','thiscall',None,ret=None,gen=g,nan_heap=True,note='batch124009')
