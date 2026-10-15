import struct
from pilot import S,SENTINELS
from recruits_util import rnd,clear_hooks,hook_rec,pystub
from pe_emu import STACK_TOP

def gen(c):
 clear_hooks(c);e=c.emu;r=c.rng
 # Above pilot.run's overwritten range: the earlier spec placed this below it.
 frame=STACK_TOP-0x100;sp=frame-16
 e.w32(frame,STACK_TOP-0x80);e.w32(frame+4,e.RET_ADDR)
 for off,reg in [(16,'edi'),(12,'esi'),(8,'ebx')]:e.w32(frame-off,SENTINELS[reg])
 dst=rnd(c,36);src=rnd(c,36);arg=rnd(c,36);vec=rnd(c,36)
 if r.random()<.4:
  arena=rnd(c,80);src=arena;dst=arena+r.choice([0,4,8,16,20])
 for p in (dst,src,arg,vec):
  for off in range(0,36,4):e.wf32(p+off,r.uniform(-10,10))
 e.w32(frame+8,arg);e.wf32(frame+12,r.uniform(-2,2))
 def init(em,k):em.calllog.append(('init-edx',em.reg('edx')))
 hook_rec(c,0x4e0390,3,this=True,side=init)
 seq=[r.choice([0.,1.,-1.,r.uniform(-2,2)]) for _ in range(3)]
 hook_rec(c,0x44c840,0,this=True,st0=lambda em,k:seq[k%3],side=lambda em,k:em.calllog.append(('norm-input',em.rbytes(em.reg('ecx'),12).hex())))
 output=bytes(r.getrandbits(8) for _ in range(12))
 def cross(em,k):
  em.calllog.append(('cross',em.reg('edx')));em.wbytes(em.reg('ecx'),output)
 hook_rec(c,0x446ee0,1,this=True,side=cross)
 e.w32(0x7003b0,pystub(c,0))
 return [dst,src,vec,vec,rnd(c,36),struct.unpack('<I',struct.pack('<f',r.uniform(-2,2)))[0],frame,sp]
S(0x4de6a3,'partial-frame transform interpolation',('regs',['ebx','esi','eax','edx','ecx','xmm2','ebp','esp']),None,ret=None,gen=gen)
