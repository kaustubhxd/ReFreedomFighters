import struct
from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,sysobj

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 me=obj(c,0xb0,{0x64:pystub(c,1,this=True),0x68:pystub(c,2,this=True)})
 xyz=[r.getrandbits(32) for _ in range(3)]
 def fill(em,k):
  for i,x in enumerate(xyz):em.w32(em.arg32(0)+i*4,x)
 child=obj(c,0x10,{0x84:pystub(c,1,this=True,deref={0:3},side=fill),0x2c:pystub(c,0,this=True,ret=r.getrandbits(32))})
 e.w32(me+0x44,child);e.wbytes(me+0x48,bytes([r.choice([0,1,255])]))
 tag=r.randrange(0x500,0x10000);globaltag=r.randrange(0x500,0x10000)
 e.wbytes(me+0x76,struct.pack('<H',tag));e.wbytes(0x700348,struct.pack('<H',globaltag))
 for off in [0x7a,0x4e]:e.wbytes(me+off,struct.pack('<f',r.choice([0.,-0.,1.,-1.,float('nan'),1e20,r.uniform(-100,100)])))
 so=sysobj(c);e.w32(so+0x40,r.getrandbits(32))
 message=r.choice([0x400,0x401,tag,tag,globaltag,r.randrange(0x10000)]) | (r.getrandbits(16)<<16)
 return [me,message,r.getrandbits(32)]
S(0x4c3b40,'GUESS dispatch timer messages','thiscall',None,ret='eax',gen=gen,nan_heap=True)
