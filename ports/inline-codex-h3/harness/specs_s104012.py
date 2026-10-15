from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    selfp=rnd(c,0x1d0)
    stream=obj(c,0x20,{off:pystub(c,1,this=True) for off in (0x40,0x4c,0x60,0x6c)})
    return [selfp,stream]
S(0x4a4600,'GUESS serialize extended entity fields','thiscall',None,ret='al',gen=gen,note='batch104012')
