import struct
from pilot import S
from recruits_util import rnd,obj,pystub,hook_rec,clear_hooks,HEAP_LO,HEAP_HI

def gen(c):
 clear_hooks(c); e=c.emu;r=c.rng
 def fw(a,x):e.wbytes(a,struct.pack('<f',x))
 def floats(n):return [r.uniform(-100,100) for _ in range(n)]
 matrixvals=floats(9); outvals=floats(17)
 renderer=obj(c,0x40,{8:pystub(c,0,this=True,st0=r.uniform(-5,5)),0x2c:pystub(c,5,this=True,deref={1:2,2:9,3:3})})
 def compute(em,k):
  for idx,v in enumerate(outvals[:9]):em.wbytes(em.arg32(6)+idx*4,struct.pack('<f',v))
  for idx,v in enumerate(outvals[9:12]):em.wbytes(em.arg32(4)+idx*4,struct.pack('<f',v))
  for idx,v in enumerate(outvals[12:15]):em.wbytes(em.arg32(5)+idx*4,struct.pack('<f',v))
 s=obj(c,0xb0,{0x220:pystub(c,7,this=True,stackmark=(2,3),deref={2:9,3:3},side=compute)})
 basis=rnd(c,0x30); transform=rnd(c,0x30);pos=rnd(c,12)
 for a in [basis,transform]:
  for i,v in enumerate(floats(12)):fw(a+4*i,v)
 e.w32(s+8,transform)
 n=r.randrange(6);ids=rnd(c,24);entries=rnd(c,48)
 e.w32(s+0x32,n);e.w32(s+0x36,ids);e.w32(s+0x3a,entries if r.randrange(5) else 0)
 e.w8(s+0x90,r.randrange(2))
 xyz=floats(3)
 for i,v in enumerate(xyz):fw(pos+4*i,v);fw(s+0x46+4*i,v if r.randrange(2) else v+1)
 for off in range(0x52,0x8e,4):fw(s+off,r.uniform(-10,10))
 def mat(em,k):
  p=em.reg('ecx')
  for i,v in enumerate(matrixvals):em.wbytes(p+4*i,struct.pack('<f',v))
  em.calllog.append(('basis',em.reg('edx')))
 hook_rec(c,0x4de4b0,1,this='mark',side=mat)
 hook_rec(c,0x4e0d00,1,this=True)
 def reglog(em,k):em.calllog.append(('edx',em.reg('edx')))
 hook_rec(c,0x4419f0,0,this=True,side=reglog)
 hook_rec(c,0x4de480,0,this=True,side=reglog)
 hook_rec(c,0x7003b0,0,ret=r.getrandbits(32))
 return [s,renderer,r.getrandbits(32),basis,pos,r.getrandbits(32)]
S(0x4efe00,'GUESS updateGeometry','thiscall',None,ret=None,gen=gen)
