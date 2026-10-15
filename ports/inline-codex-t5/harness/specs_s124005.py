from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub
import struct

def g(c):
 clear_hooks(c);r=c.rng;e=c.emu
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 holder=obj(c,0x20,{0x2e8:pystub(c,2,this=True)})
 ref=obj(c,0x20,{0x58:pystub(c,1,this=True,ret=r.choice([0,holder,holder]))})
 sys=rnd(c,0xb0);e.w32(0x70039c,sys);e.w32(sys+0x9b,ref)
 ticks=r.choice([0,1024,4096,-1024,2147483647,-2147483648,r.randrange(-100000,100000)]);e.w32(sys+0x40,ticks&0xffffffff)
 now=struct.unpack('<f',struct.pack('<f',float(ticks)))[0]/1024
 elems=[rnd(c,8) for _ in range(r.randrange(5))]
 records=[rnd(c,0x50) for _ in elems]
 lookup={e.r32(p):v for p,v in zip(elems,records)}
 mgr=obj(c,0x20,{0xcc:pystub(c,1,this=True,ret=lambda em,k:lookup[em.arg32(0)])});e.w32(0x70038c,mgr)
 def begin(em,k):
  for i in range(4):em.w32(em.arg32(0)+4*i,0)
 def nxt(em,k):
  em.w32(em.arg32(0),k+1)
 listobj=obj(c,0x20,{0x4c:pystub(c,1,this=True,stackmark=[0],side=begin),0x64:pystub(c,1,this=True,stackmark=[0],side=nxt,ret=lambda em,k:elems[k] if k<len(elems) else 0),0x44:pystub(c,1,this=True,deref={0:4})})
 dues=[r.choice([now-1,now,now+1,-1e9,1e9,float('nan')]) for _ in elems]
 controller=obj(c,0x20,{0x9c:pystub(c,1,this=True,st0=lambda em,k:dues[k])})
 me=rnd(c,0x90);e.w32(me+0x74,controller);e.w32(me+0x78,r.choice([0,listobj,listobj,listobj]))
 return [me]
S(0x471860,'GUESS update queued activations','thiscall',None,ret=None,gen=g,note='batch124005')
