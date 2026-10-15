import struct,math
from unicorn.x86_const import UC_X86_REG_XMM0,UC_X86_REG_XMM1
from pilot import S,F,EDGE_F
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def put(e,p,v):e.wbytes(p,struct.pack('<f',v))
def g546(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x80);n=r.choice([0,1,2,3,5]);particles=rnd(c,0x34*5)
 e.w32(s+0xf,particles);e.w32(s+0x28,n if r.random()<0.9 else 0xffffffff)
 put(e,s+0x61,r.choice([-1.,0.,0.001,0.1,1.,float('nan')]))
 for i in range(5):
  for off in [0xc,0x10,0x14,0x18,0x1c,0x20,0x30]:put(e,particles+0x34*i+off,r.choice(EDGE_F) if r.random()<0.1 else r.uniform(-10,10))
  if r.random()<0.3:e.w32(particles+0x34*i+0x30,e.r32(0x67ff1c))
 def power(em,k):
  a=em.mu.reg_read(UC_X86_REG_XMM0)&((1<<64)-1);b=em.mu.reg_read(UC_X86_REG_XMM1)&((1<<64)-1)
  em.calllog.append(('pow',a,b));x=struct.unpack('<d',struct.pack('<Q',a))[0];y=struct.unpack('<d',struct.pack('<Q',b))[0]
  try:z=math.pow(x,y)
  except (ValueError,OverflowError):z=float('nan')
  em.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',z))[0])
 hook_rec(c,0x634db2,0,side=power)
 return [s,F(r.choice([0.,0.001,0.01,0.1,1.,-0.1,float('nan')]))]

def g529(c):
 clear_hooks(c);r=c.rng;e=c.emu;s=rnd(c,0x140)
 stream=obj(c,32,{0x68:pystub(c,1,this=True,deref={0:3}),0x10:pystub(c,2,this=True,deref={0:1}),0x4c:pystub(c,1,this=True),0x64:pystub(c,1,this=True),0x60:pystub(c,1,this=True)})
 hook_rec(c,0x516e20,1,this=True)
 return [s,stream]
S(0x546860,'GUESS damped particle integration','thiscall',None,ret=None,gen=g546,note='batch116012',nan_heap=True)
S(0x529fa0,'GUESS serialize wheel and dampers','thiscall',None,ret='al',gen=g529,note='batch116012')
