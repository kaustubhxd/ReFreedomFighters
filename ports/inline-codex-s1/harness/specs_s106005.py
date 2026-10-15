import struct,pefile
from pilot import S,EDGE_F
from recruits_util import rnd,obj,clear_hooks,hook_rec,pystub
from pe_emu import DEFAULT_EXE
pe=pefile.PE(DEFAULT_EXE)
def const(a):return struct.unpack('<f',pe.get_data(a-pe.OPTIONAL_HEADER.ImageBase,4))[0]
def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 me=obj(c,0x2800,{0x130:pystub(c,3,this=True)})
 vec=[r.choice([0.,1.,-1.,r.uniform(-10,10)]) for _ in range(3)]
 if r.random()<.1:vec=[0.,0.,0.]
 def writeout(em,k):em.wbytes(em.arg32(0),struct.pack('<fff',*vec))
 def update(em,k):
  em.calllog.append(('ctl-input',em.rbytes(em.arg32(0),12).hex(),em.rbytes(em.arg32(1),12).hex()))
  em.wbytes(em.arg32(0),struct.pack('<fff',*vec[::-1]))
 ctl=obj(c,16,{8:pystub(c,1,this=True,side=writeout),0xc:pystub(c,0,this=True,ret=r.choice([0,1,0x100,0x101])),4:pystub(c,2,this=True,side=update)})
 e.w32(me+0x2695,e.r32(ctl));e.w32(me+0x216,r.choice([0,1,2]))
 child=rnd(c,0x30);e.w32(me+0x5c,child)
 e.wf32(child+0x24,r.choice([const(0x680a70),const(0x680a84),-1.,0.,1.,r.uniform(-100,100)]))
 for off in [0x2d8,0x2dc,0x2e0,0x2e4,0x2e8,0x2ec,0x2f0]:e.wf32(me+off,r.uniform(-10,10))
 delta=[r.choice([0.,1.,100.,r.uniform(-20,20)]) for _ in range(3)]
 def sub(em,k):
  em.calllog.append(('sub-edx',em.reg('edx')));em.wbytes(em.reg('ecx'),struct.pack('<fff',*delta))
 hook_rec(c,0x43e920,1,this='mark',side=sub)
 def scale(em,k):
  p=em.reg('ecx');em.calllog.append(('scale-input',em.rbytes(p,12).hex()))
  f=struct.unpack('<f',struct.pack('<I',em.arg32(0)))[0]
  for i in range(3):em.wf32(p+4*i,em.rf32(p+4*i)*f)
 hook_rec(c,0x4e0d00,1,this='mark',side=scale)
 hook_rec(c,0x521600,1,this=True,deref={0:3})
 hook_rec(c,0x44c840,0,this=True,st0=r.uniform(-10,10))
 hook_rec(c,0x633654,0)
 e.w32(0x7003b0,e.stub_fn('assert',lambda em,k:em.ret(eax=0)))
 return [me]
S(0x521bd0,'update planar motion','thiscall',None,ret=None,gen=gen,nan_heap=True)
