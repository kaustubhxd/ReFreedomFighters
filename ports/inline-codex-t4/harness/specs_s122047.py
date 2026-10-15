from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 def writer():
  data=struct.pack('<12f',*[r.uniform(-2,2) for _ in range(12)])
  def f(em,k):em.wbytes(em.arg32(0),data[:36]);em.wbytes(em.arg32(1),data[36:])
  return f
 s=obj(c,0xe20,{0x90:pystub(c,2,this=True,stackmark=(0,1),side=writer())})
 owner=obj(c,0x20,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=writer())})
 flag=rnd(c,0x130);e.w32(flag+0x119,owner if r.randrange(3) else 0)
 cfg=rnd(c,0x490);e.wbytes(cfg+0x479,struct.pack('<f',r.uniform(-10,10)));e.w32(s+0xb54,cfg)
 sys=rnd(c,0x1b80);e.w32(0x70039c,sys);e.w32(sys+0x1b5d,r.choice([0,1,2]))
 hook_rec(c,0x5cd7f0,4,this=True,deref={0:3,1:3})
 return [s,flag]
S(0x5d26c0,'GUESS start flag raising camera swing','thiscall',None,ret=None,gen=gen)
