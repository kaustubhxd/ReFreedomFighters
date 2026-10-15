from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec,obj,sysobj

def pick(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0xe20);e.w8(self+0xd32,r.choice([0,1]));e.w32(self+0xad5,r.choice([0,1,9]))
 owner=rnd(c,0x80);node=rnd(c,0x20);e.w32(owner+0x54,node);e.w32(self+0x44,owner)
 e.w32(self+0xb54,obj(c,0x20,{0xac:pystub(c,0,this=True,st0=r.uniform(-1000,1000))}))
 e.wf32(self+0xdfd,r.uniform(-1000,1000))
 block=r.choice([0,1]);newmode=r.choice([0,9]);hitid=r.getrandbits(32)
 hook_rec(c,0x5cf110,0,this=True,ret=(r.getrandbits(24)<<8)|r.choice([0,0,1]),side=lambda em,k:em.w8(self+0xd33,block))
 hook_rec(c,0x5d2630,1,this=True)
 hook_rec(c,0x5d2860,1,this=True,ret=r.choice([0,1,2,3]))
 vals=r.randbytes(12)
 hook_rec(c,0x4e0d80,1,this=True,side=lambda em,k:em.wbytes(em.reg('ecx'),vals))
 def ray(em,k):em.w32(self+0xb9f,hitid);em.w32(self+0xad5,newmode)
 phys=obj(c,0x20,{0x2e0:pystub(c,6,this=True,deref={0:6},ret=(r.getrandbits(24)<<8)|r.choice([0,1]),side=ray)})
 sys=sysobj(c,table_size=0xb00);e.w32(e.r32(sys+0x9b)+0xadc,phys)
 return [self]
S(0x5d11c0,'GUESS_camera_check_pointer_target','thiscall',None,ret='al',gen=pick)
