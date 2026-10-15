from pilot import S
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 s=rnd(c,0x60);pos=rnd(c,12)
 p=[r.uniform(-3,3) for _ in range(3)];e.wbytes(pos,struct.pack('<3f',*p))
 e.wbytes(s+0x51,struct.pack('<f',r.choice([0.,1.,5.,10.,-5.])))
 entries=[]
 for i in range(r.randrange(6)):
  center=struct.pack('<3f',*[x+r.choice([0.,1.,10.]) for x in p])
  def fill(em,k,center=center):em.wbytes(em.arg32(0),bytes(36));em.wbytes(em.arg32(1),center)
  node=obj(c,0x20,{0x384:pystub(c,2,this=True,stackmark=(0,1),side=fill),0x128:pystub(c,3,this=True,deref={1:3})});entries.append(node)
 def advance(em,k):em.w32(em.arg32(2),k)
 mgr=obj(c,0x20,{0x84:pystub(c,4,this=True,deref={0:3,2:1},side=advance,ret=lambda em,k:entries[k] if k<len(entries) else 0)})
 cfg=rnd(c,0x2c20);e.w32(0x7003b8,cfg);e.w32(cfg+0x2c11,mgr);e.w16(0x71428c,r.randrange(65536))
 return [s,pos]
S(0x585200,'GUESS notify nearby spatial objects','thiscall',None,ret=None,gen=gen)
