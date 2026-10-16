"""specs_s390.py - area 76, residue 17, batch 390 (thiscall, one word, ret 4; GUESS).
0x4f05d0: this.vtbl[0x244](this); call 0x45f3c0(this, arg); if result: copy fields from arg to this,
call various arg.vtbl slots with output pointers in this, unpack a byte, store values, call vtbl[0x238].
"""
from pilot import S

def _gen(c):
    e = c.emu
    rng = c.rng

    def fn244(em, r):
        em.calllog.append(('f244', 0x244, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def fn45f3c0(em, r):
        # External helper - return true to enter the main path
        em.ret(eax=1, argbytes=8)

    def fn40(em, r):
        # arg.vtbl[0x40] - takes output pointer, fill it with data
        out_ptr = em.arg32(0)
        e.w32(out_ptr, rng.getrandbits(32))
        e.w32(out_ptr + 4, rng.getrandbits(32))
        em.ret(eax=0, argbytes=4)

    def fn18(em, r):
        # arg.vtbl[0x18] - takes output pointer and a size, fills the buffer
        out_ptr = em.arg32(0)
        size = em.arg32(1)
        # Write a byte value that encodes low 4 bits and high bit
        val = (rng.randint(0, 15) | ((rng.randint(0, 1) & 1) << 4))
        e.w32(out_ptr, val)
        em.ret(eax=0, argbytes=8)

    def fn238(em, r):
        em.calllog.append(('f238', 0x238, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    # Create this object
    this_vt = e.fake_vtable('this_4f05d0', 0x300, {0x244: fn244, 0x238: fn238})
    this = e.alloc(0x100, 4)
    e.w32(this, this_vt)

    # Create arg object
    arg_vt = e.fake_vtable('arg_4f05d0', 0x50, {0x40: fn40, 0x18: fn18})
    arg = e.alloc(0x100, 4)
    e.w32(arg, arg_vt)

    return [this, arg]

S(0x4f05d0, 'unpack4f05d0 (GUESS)', 'thiscall', ('u8 *',), ret='u8', gen=_gen,
  note='area 76 batch 390; residue 17; object vtable slots stubbed')
