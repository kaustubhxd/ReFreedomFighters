from pilot import S
from recruits_util import rnd,obj,clear_hooks,pystub,hook_rec,stub_memset

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng; stub_memset(c)
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    # Self-pointing vtable so the executable's ECX=vtable call and our vcall share the same target/this.
    vt=rnd(c,0xc0)
    e.w32(vt,vt)
    e.w32(vt+0xb0,pystub(c,3,this=True,deref={2:-0x68},stackmark=(0,)))
    e.w32(vt+0xb8,pystub(c,3,this=True,stackmark=(0,)))
    e.w32(0x724a00,vt)
    unused=rnd(c,4)
    p=rnd(c,0x80)
    for i in range(32): e.wf32(p+4*i,r.choice([0.0,0.25,-0.5,1.0,2.0]))
    return [unused,p]
S(0x611710,'GUESS transform vector rows','thiscall',None,gen=gen,note='batch104016')
