from pilot import S,F
import math,struct
from unicorn.x86_const import UC_X86_REG_XMM0
from recruits_util import clear_hooks,rnd,pystub

def gen(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 def power(em,_):
  ab=em.reg("xmm0")&0xffffffffffffffff;bb=em.reg("xmm1")&0xffffffffffffffff
  a=struct.unpack("<d",ab.to_bytes(8,"little"))[0];b=struct.unpack("<d",bb.to_bytes(8,"little"))[0]
  em.calllog.append(("pow",ab,bb));v=math.pow(a,b);em.mu.reg_write(UC_X86_REG_XMM0,int.from_bytes(struct.pack("<d",v),"little"));em.ret()
 e.stub_import("_libm_sse2_pow_precise",power)
 t=rnd(c,0xc4);n=r.randrange(9);e.w32(t+0x44,n);flags=rnd(c,4*max(1,n));e.w32(t+0x64,flags)
 p=rnd(c,24*max(1,n));force,sub=rnd(c,12),rnd(c,12)
 for i in range(n):e.w32(flags+4*i,r.choice([0,1,1,0xffffffff]))
 for a,size in [(p,6*n),(force,3),(sub,3)]:
  for i in range(size):e.wf32(a+4*i,r.uniform(-100,100))
 e.wf32(t+0x38,r.uniform(-2,2));e.wf32(t+0x3c,r.choice([0.,1.,r.uniform(0,1)]));old=r.choice([0.,-.1,.01,.1,1.,10.]);e.wf32(t+0xc0,old)
 dt=r.choice([0.,.001,.1,1.,10.,100.,-.1])
 return [t,p,force,r.choice([0,sub]),F(dt)]
S(0x44ef80,'GUESS damped Verlet update','thiscall',None,ret=None,gen=gen)
