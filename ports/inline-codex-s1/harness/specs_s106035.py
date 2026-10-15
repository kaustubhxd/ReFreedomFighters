import math,struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
from recruits_util import rnd,sysobj,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 n=r.randrange(9);me=rnd(c,0x700);e.w32(me+0x48,n)
 now=r.choice([r.randrange(5000),r.getrandbits(32)])
 decreasing=r.random()<.3
 for i in range(max(n,1)):
  p=me+0x4c+0x28*i
  e.w32(p+0xc,now if decreasing else r.getrandbits(32));e.wf32(p+0x14,1.0 if decreasing else r.uniform(.25,6));e.wf32(p+0x18,float(n-i) if decreasing else r.uniform(-2,3))
 system=sysobj(c);e.w32(system+0x40,now)
 src=rnd(c,40)
 if n>=5 and r.random()<.2:src=me+0x4c+0x28*r.randrange(n)
 def append(em,k):
  p=em.reg('ecx');count=em.r32(p);data=em.rbytes(em.arg32(0),40);em.wbytes(p+4+count*40,data);em.w32(p,count+1)
 hook_rec(c,0x5de900,1,this=True,deref={0:10},side=append,ret=lambda em,k:em.r32(em.arg32(0)+36))
 def exp(em,k):
  bits=em.reg('xmm0')&((1<<64)-1);em.calllog.append(('exp',bits));v=struct.unpack('<d',struct.pack('<Q',bits))[0]
  try:y=math.exp(v)
  except OverflowError:y=math.inf
  em.mu.reg_write(UC_X86_REG_XMM0,struct.unpack('<Q',struct.pack('<d',y))[0])
 hook_rec(c,0x634db8,0,side=exp);e.w32(0x7003b0,pystub(c,0))
 return [me,src]
S(0x5de090,'replace minimum scored record','thiscall',None,ret='eax',gen=gen)
