from pilot import S
from recruits_util import rnd, clear_hooks

def _g67001(c):
    clear_hooks(c)
    r,e=c.rng,c.emu
    e.w32(0x7003b0,e.stub_fn('assert',lambda em,_:em.ret(eax=r.getrandbits(32))))
    # Focus this attempt on the null nested-object and empty-root fallback path.
    this=e.alloc(0x500,4); e.wbytes(this,bytes(r.getrandbits(8) for _ in range(0x500)))
    e.w32(this+8,0)
    root=e.alloc(0x2000,4); e.wbytes(root,bytes(r.getrandbits(8) for _ in range(0x2000)))
    e.wbytes(root+0x123,b'\0'+bytes(15)); e.w32(0x70039c,root)
    e.w32(0x4cc1d0,e.stub_fn('root',lambda em,_:em.ret(eax=em.reg_read('ecx'))))
    p=e.alloc(32,1); e.wbytes(p,b'C:\\folder\\file.ext\0'+bytes(10))
    return [this,p]

S(0x4351c0,'GUESS path_validation','thiscall',None,ret='eax',gen=_g67001)
