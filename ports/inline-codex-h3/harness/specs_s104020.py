from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    vals=[r.choice([0,1,2,0x40,0xffffffff]) for _ in range(12)]
    hook_rec(c,0x4e5e60,0,this=True,ret=lambda em,k: vals[(k-1)%len(vals)])
    hook_rec(c,0x4e5e40,0,this=True,ret=lambda em,k:r.choice([0,1,0x1234,0xabcd,0xffff]))
    hook_rec(c,0x4e5e80,0,this=True,st0=lambda em,k:r.choice([-2.5,-0.0,0.25,3.75,100.0]))
    selfp=rnd(c,0x80)
    arg=rnd(c,0x10); payload=rnd(c,0x10)
    e.w32(arg,payload); e.w8(payload,r.choice([0xff,2,3,0x42,0x83,0x7f]))
    return [selfp,arg]
S(0x4a4ad0,'GUESS copy widget state','thiscall',None,ret=None,gen=gen,note='batch104020')
