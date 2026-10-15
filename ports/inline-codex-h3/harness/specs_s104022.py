from pilot import S
from recruits_util import rnd,clear_hooks,pystub,hook_rec

def gen(c):
    clear_hooks(c); e=c.emu; r=c.rng
    hook_rec(c,0x7003b0,0,ret=lambda em,k:r.getrandbits(32))
    def qpc(em,regs):
        p=em.arg32(0); v=r.getrandbits(64)
        em.w32(p,v & 0xffffffff); em.w32(p+4,v>>32)
        em.ret(eax=1,argbytes=4)
    e.stub_import('QueryPerformanceCounter',qpc)
    def clock(em,regs): em.ret(eax=r.randrange(1,0x7fffffff))
    e.stub_import('clock',clock)
    selfp=rnd(c,0x2400); vt=rnd(c,0x210)
    e.w32(selfp,vt); e.w8(selfp+0x1e90,1)
    e.w32(vt+0x1fc,pystub(c,5,this=True,ret=0))
    return [selfp]
S(0x4234f0,'GUESS stamp event time','thiscall',None,ret=None,gen=gen,note='batch104022')
