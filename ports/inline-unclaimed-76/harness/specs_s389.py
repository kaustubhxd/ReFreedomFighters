"""specs_s389.py - area 76, residue 17, batch 389 (thiscall, no arguments, plain ret; GUESS).
0x6404d0: iterates via iterator at this+0x1f0. Iterator vtbl[0xc] initializes; [0x10] gets next.
"""
from pilot import S

def _gen(c):
    e = c.emu
    rng = c.rng

    def iter_init(em, r):
        # Initialize with null element (empty iteration)
        out_ptr = em.arg32(0)
        e.w32(out_ptr, 0)  # elem = null
        em.ret(eax=0, argbytes=8)

    def iter_next(em, r):
        out_ptr = em.arg32(0)
        e.w32(out_ptr, 0)
        em.ret(eax=0, argbytes=8)

    def this_h80(em, r):
        # Callback function - just return
        em.ret(eax=0, argbytes=4)

    # Create iterator vtable with init at 0xc and next at 0x10
    iter_vt = e.fake_vtable('iter_6404d0', 0x20, {0xc: iter_init, 0x10: iter_next})

    # Create this object with callback at 0x80
    this_vt = e.fake_vtable('this_6404d0', 0x100, {0x80: this_h80})

    this = e.alloc(0x400, 4)
    e.w32(this, this_vt)
    e.w32(this + 0x1f0, iter_vt)  # iterator vtable pointer

    return [this]

S(0x6404d0, 'loop6404d0 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 389; residue 17; empty iterator')
