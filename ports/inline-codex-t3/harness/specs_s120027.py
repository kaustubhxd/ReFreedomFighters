from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,sysobj,hook_rec

def slow(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0xd00)
 e.w8(self+0xb45,r.choice([0,1,255]));e.w8(self+0xb46,r.choice([0,0,1]))
 cam=obj(c,0x500,{0xac:pystub(c,0,this=True,st0=r.uniform(-1e5,1e5))});e.w32(self+0xb54,cam)
 sys=sysobj(c);e.w8(sys+0x6c,r.choice([0,1,255]))
 vec=r.randbytes(12);hit=r.randbytes(12)
 hook_rec(c,0x4e0d80,1,this=True,side=lambda em,k:em.wbytes(em.reg('ecx'),vec))
 hook_rec(c,0x5ceed0,6,this=True,deref={1:3,2:3},side=lambda em,k:em.wbytes(em.arg32(0),hit),ret=r.getrandbits(32))
 hook_rec(c,0x5d0bd0,3,this=True,deref={0:3})
 return [self,r.choice([0,1,255,0x100,r.getrandbits(32)])]
S(0x5d24c0,'ZCamHelper::SetSlowPointer','thiscall',None,ret=None,gen=slow)
