from pilot import S
from recruits_util import rnd,clear_hooks,pystub,obj,hook_rec,sysobj

def init(c):
 clear_hooks(c);e,r=c.emu,c.rng
 e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
 self=rnd(c,0x80);db=rnd(c,16)
 vals=[r.choice([0,1,2,r.getrandbits(32)]) for _ in range(5)]
 hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k:vals[k])
 fs=[r.choice([0.0,-0.0,float('nan'),float('inf'),r.uniform(-100,100)]) for _ in range(2)]
 hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:fs[k])
 frame=r.randbytes(48)
 def get(em,k):em.wbytes(em.arg32(0),frame[:36]);em.wbytes(em.arg32(1),frame[36:])
 owner=obj(c,0x30,{0x80:pystub(c,2,this=True,stackmark=(0,1),side=get),0x7c:pystub(c,2,this=True,deref={0:9,1:3})})
 e.w32(owner+8,rnd(c,16));e.w32(self+0x44,owner)
 phys=obj(c,0x20,{0x28c:pystub(c,3,this=True)})
 sys=sysobj(c,table_size=0xb00);e.w32(e.r32(sys+0x9b)+0xadc,phys)
 return [self,rnd(c,16),db]
S(0x4c5d00,'ZFollowShape::Init','thiscall',None,ret=None,gen=init,nan_heap=True)
