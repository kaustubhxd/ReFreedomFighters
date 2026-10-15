from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    src=rnd(c,0x90)
    out=obj(c,0x20,{})
    vt=e.r32(out)
    for off in (0x3c,0x4c,0x60,0x64):
        e.w32(vt+off,pystub(c,1,this=True))
    # system slot 0x138 returns an object; slot 0x88 writes the output word
    target=obj(c,0x20,{0x88:pystub(c,2,this=True,stackmark=(1,),side=lambda em,k: em.w32(em.arg32(1),0x12345678+k))})
    sysobj(c,table_slots={0x138:pystub(c,0,this=True,ret=target)})
    return [src,out]
S(0x5d4840,'GUESS serialize effect fields','thiscall',None,ret='al',gen=gen,note='batch104000')
