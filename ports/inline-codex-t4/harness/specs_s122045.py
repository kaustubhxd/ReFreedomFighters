from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 group=obj(c,0x20,{0x98:pystub(c,2,this=True,deref={0:9,1:3})})
 child=obj(c,0x20,{0x20:pystub(c,0,this=True,ret=group),0x74:pystub(c,2,this=True,deref={0:9,1:3})});e.w32(child+8,rnd(c,0x40))
 s=obj(c,0x80,{0x348:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101])),0x20:pystub(c,0,this=True,ret=child),0x1e0:pystub(c,1,this=True,ret=r.choice([0,1,0x100,0x101])),0x7c:pystub(c,2,this=True,deref={0:9,1:3})})
 e.w32(s+0x6c,rnd(c,0x260))
 for j in range(12):e.wbytes(s+0x24+4*j,struct.pack('<f',r.uniform(-2,2)))
 data=struct.pack('<12f',*[r.uniform(-2,2) for _ in range(12)])
 def fill(em,k):em.wbytes(em.arg32(0),data[:36]);em.wbytes(em.arg32(1),data[36:])
 hook_rec(c,0x4db2c0,2,this=True,stackmark=(0,1),side=fill)
 return [s]
S(0x461c40,'GUESS linked object frame transform','thiscall',None,ret=None,gen=gen)
