from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    # Helper is observed but returns a deterministic result; the routine zeroes its output afterwards.
    hook_rec(c,0x487c70,4,this=True,ret=0,stackmark=(0,1,2,3))
    selfp=rnd(c,0x400)
    found=rnd(c,0x10)
    vt=rnd(c,0x14)
    e.w32(found,vt)
    e.w32(vt+0x10,pystub(c,0,this=True,ret=1))
    e.w32(selfp+0xc,found)
    e.w32(selfp+0x28,1)
    state=rnd(c,0x420)
    e.w32(selfp+4,state)
    e.w8(state+0x417,0)
    e.w8(selfp+0x3ad,1)
    e.w8(selfp+0x3bb,0); e.w8(selfp+0x3bc,0); e.w8(selfp+0x3be,0)
    a=rnd(c,0x20); b=rnd(c,0x20); out=rnd(c,0x20); d=rnd(c,0x20)
    return [selfp,a,b,out,d]
S(0x487e50,'GUESS clear inactive motion vector','thiscall',None,ret='al',gen=gen,note='batch104018')
