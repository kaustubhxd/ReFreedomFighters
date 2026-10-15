from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    hook_rec(c,0x4640f0,1,this=True,ret=1,stackmark=(0,))
    hook_rec(c,0x467850,2,this=True,ret=0,stackmark=(0,1))
    selfp=rnd(c,0x220)
    e.w32(selfp+0x1ce,0)
    child=obj(c,0x10,{0x4c:pystub(c,1,this=True)})
    slots={off:pystub(c,1,this=True) for off in (0x3c,0x44,0x60)}
    slots[0x4c]=pystub(c,1,this=True)
    slots[0x68]=pystub(c,1,this=True,ret=child)
    stream=obj(c,0x20,slots)
    return [selfp,stream]
S(0x467770,'GUESS serialize actor state','thiscall',None,ret='al',gen=gen,note='batch104013')
