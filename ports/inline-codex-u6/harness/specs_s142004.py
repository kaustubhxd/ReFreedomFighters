import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu;me=rnd(c,0xc0);sys=rnd(c,0x80);e.w32(0x70039c,sys)
 now=r.randrange(-10000,10000);e.w32(sys+0x40,now&0xffffffff)
 previous=now/1024-r.choice([-0.1,0,0.001,0.005,0.01,0.03,0.05,0.2])
 e.wbytes(me+0x48,struct.pack('<f',previous))
 for off in [0x30,0x38,0x9c]:e.wbytes(me+off,struct.pack('<f',r.uniform(-5,5)))
 hook_rec(c,0x524f50,0,this=True);hook_rec(c,0x526df0,0,this=True);hook_rec(c,0x524b00,0,this=True)
 # Record arguments for all iterations and make intermediate matrix outputs observable.
 record=e.alloc(128*128,4)
 values=[struct.pack('<9f',*[r.uniform(-2,2) for _ in range(9)]) for i in range(22)]
 def ctor(em,k):
  em.wbytes(record+k*128,em.rbytes(em.reg('edx'),12));em.w32(record+k*128+12,em.reg('ecx'));em.w32(record+k*128+16,em.arg32(0))
  em.wbytes(em.reg('ecx'),values[k])
 hook_rec(c,0x4de040,1,side=ctor)
 def scale(em,k):
  p=record+3000+k*128;em.wbytes(p,em.rbytes(em.reg('edx'),36));em.w32(p+36,em.arg32(0));em.wbytes(em.reg('ecx'),values[k])
 hook_rec(c,0x4ddcb0,1,side=scale)
 def combine(em,k):
  p=record+7000+k*128;em.wbytes(p,em.rbytes(em.reg('ecx'),36));em.wbytes(p+36,em.rbytes(em.reg('edx'),36))
  em.wbytes(em.reg('ecx'),values[21-k%22])
 hook_rec(c,0x4de480,0,side=combine)
 return [me]
S(0x524ff0,'GUESS undercarriage fixed timestep update','thiscall',None,ret=None,gen=gen)
