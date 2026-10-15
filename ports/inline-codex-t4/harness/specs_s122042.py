from pilot import S,F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
import struct

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 hook_rec(c,0x7003b0,4,pop=0,ret=r.getrandbits(32))
 def shift(em,k):
  p=em.arg32(0)
  for j in range(3):x=struct.unpack('<f',em.rbytes(p+4*j,4))[0];em.wbytes(p+4*j,struct.pack('<f',x+1))
 s=obj(c,0x80,{0x84:pystub(c,1,this=True,deref={0:3},side=shift),0x88:pystub(c,1,this=True,deref={0:3},side=shift)})
 for off in [0x64,0x68]:e.wbytes(s+off,struct.pack('<f',r.uniform(-100,100)))
 pos=struct.pack('<3f',*[r.uniform(-10,10) for _ in range(3)]);ident=r.getrandbits(32);record=e.alloc(8,4)
 def hit(em,k):
  p=em.arg32(0);em.w32(record,em.r32(p+52));em.w32(record+4,em.rbytes(p+108,1)[0]);em.wbytes(p+40,pos);em.w32(p+68,ident)
 mgr=obj(c,0x20,{0x2e0:pystub(c,6,this=True,deref={0:6},side=hit,ret=r.choice([0,1,0x100,0x101]))})
 tab=obj(c,0xb00,{0x54:pystub(c,1,this=True,ret=r.choice([0,1,r.getrandbits(32)]))});e.w32(tab+0xadc,mgr)
 sys=rnd(c,0x100);e.w32(0x70039c,sys);e.w32(sys+0x9b,tab)
 return [s,rnd(c,16),r.getrandbits(32),r.getrandbits(32),F(r.uniform(-50,50))]
S(0x445e90,'GUESS screen selection hit or fallback','thiscall',None,ret='al',gen=gen)
