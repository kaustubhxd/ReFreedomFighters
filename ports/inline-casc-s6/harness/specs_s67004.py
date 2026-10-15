from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub

def _g67004(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:em.ret(eax=r.getrandbits(32))))
    first=obj(c,0x20,{0x90:pystub(c,2,this=True,pop=8,side=lambda em,k:em.wbytes(em.arg32(1),b'\0'))})
    system=obj(c,0x20,{0x88:pystub(c,2,this=True,pop=8,side=lambda em,k:em.w32(em.arg32(1),0x12345678))})
    slots={0x134:pystub(c,0,this=True,ret=first),0x138:pystub(c,0,this=True,ret=system),
           0x4c:pystub(c,1,this=True,pop=4,ret=0x9988),0x114:pystub(c,5,this=True,pop=20,ret=0x4321)}
    sysobj(c,table_slots=slots,table_size=0xb00)
    target=obj(c,0x20,{0x12c:pystub(c,2,this=True,pop=8)})
    self_=e.alloc(0x80,4); e.wbytes(self_,bytes(r.getrandbits(8) for _ in range(0x80))); e.w32(self_+0x44,target)
    return [self_]

S(0x5d6af0,'GUESS update_resource_metadata','thiscall',None,ret=None,gen=_g67004)
