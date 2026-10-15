import struct
from pilot import S,EDGE_F
from recruits_util import rnd,obj,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 values=[r.choice([0.,1.,-1.,r.uniform(-4,4)]) for _ in range(3)]
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:values[k%3])
 hook_rec(c,0x4e5e60,0,this=True,ret=r.choice([0,0,1]))
 def scale(em,k):
  p=em.reg('ecx'); f=struct.unpack('<f',struct.pack('<I',em.arg32(0)))[0]
  for i in range(3):e.wf32(p+4*i,e.rf32(p+4*i)*f)
 hook_rec(c,0x4e0d00,1,this=True,side=scale)
 rot=[r.choice([0.,1.,-1.,r.uniform(-1,1)]) for _ in range(3)]
 def rotate(em,k):
  em.calllog.append(('rotation-in',em.rbytes(em.reg('ecx'),12).hex()))
  em.wbytes(em.reg('ecx'),struct.pack('<fff',*rot))
 hook_rec(c,0x4e0d80,1,this=True,side=rotate)
 matrix=[r.choice([0.,1.,-1.,r.uniform(-1,1)]) for _ in range(9)]
 def mat(em,k):em.wbytes(em.arg32(0),struct.pack('<9f',*matrix))
 hook_rec(c,0x4db2a0,1,this=True,nullflag=(0,),side=mat)
 hook_rec(c,0x633654,0)
 sysobj(c,table_slots={0x114:pystub(c,4,this=True,ret=lambda em,k:r.getrandbits(32))})
 me=obj(c,0x100,{0x68:pystub(c,2,this=True)})
 child=rnd(c,16);e.w32(me+0x44,child);e.w32(child+8,rnd(c,16))
 src=rnd(c,16);tag=rnd(c,4);e.w32(src,tag);e.wbytes(tag,bytes([r.choice([0xff,3,0x43,0x23,4,0])]))
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [me,src]
S(0x4c9330,'load rotation derived components','thiscall',None,ret=None,gen=gen,nan_heap=True)
