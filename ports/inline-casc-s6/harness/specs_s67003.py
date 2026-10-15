from pilot import S
from recruits_util import obj, sysobj, clear_hooks, pystub

def _g67003(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:em.ret(eax=r.getrandbits(32))))
    item=e.alloc(0x40,4); e.wbytes(item,bytes(r.getrandbits(8) for _ in range(0x40))); e.w32(item+0x18,0)
    factory=obj(c,0x20,{0x25c:pystub(c,2,this=True,pop=8,ret=item)})
    so=sysobj(c,table_size=0xb00)
    table=e.r32(so+0x9b); e.w32(table+0xadc,factory)
    self_=obj(c,0x20,{0x68:pystub(c,2,this=True,pop=8)})
    return [self_]

S(0x5dacd0,'GUESS process_resource_list','thiscall',None,ret=None,gen=_g67003)
