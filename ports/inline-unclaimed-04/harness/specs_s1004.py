"""specs_s1004.py - unclaimed-04 batch 4 (docs/20-unclaimed-04.md): ZMovementBaseMove::CalcNewSpeed (0x487c70, high name).
thiscall, four stack arguments (ret 0x10). The object is 0x1000 random bytes; its owner (+4) is an 0x800-byte record
whose flags dword (+0x417) is random, so every flag combination the function tests comes up.
Object vtable slot +0x60 is a stub returning R, a fake object whose vtable slot +0x10 is a stub returning one of four
result objects chosen by the pushed argument (1 to 4). The original-code callees 0x43e960, 0x441940 and 0x4e0d80 are
left as the exe has them."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _args(c):
    own = _rnd(c, 0x800)
    flags = c.rng.getrandbits(32)
    o = _rnd(c, 0x1000)
    # the state pointer at +0x21 is read even when no branch stores it, so it starts as null or a valid buffer
    prev = 0 if c.rng.random() < 0.4 else _rnd(c, 0x100)
    c.emu.w32(o + 0x21, prev)
    if c.rng.random() < 0.3:
        # no flag that sets the state pointer, and a null pointer at +0x21: the 0x678858 fallback runs
        flags &= ~(0x20 | 0x40 | 0x2000 | 0x4000 | 0x8 | 0x10 | 0x1 | 0x2) & 0xffffffff
        c.emu.w32(o + 0x21, 0)
    c.emu.w32(own + 0x417, flags)
    results = {k: _rnd(c, 0x100) for k in (1, 2, 3, 4)}

    def h10(em, r):
        em.ret(eax=results[em.arg32(0)], argbytes=4)

    vr = c.emu.fake_vtable('R', 5, {0x10: h10})
    R = c.emu.alloc(0x100, 4)
    c.emu.w32(R, vr)

    def h60(em, r):
        em.ret(eax=R, argbytes=0)

    vo = c.emu.fake_vtable('CalcNewSpeed owner', 0x64 // 4 + 1, {0x60: h60})
    c.emu.w32(o, vo)
    c.emu.w32(o + 4, own)
    a1 = _rnd(c, 0x100)
    out_a = _rnd(c, 0x100)
    out_b = _rnd(c, 0x100)
    return [o, a1, c.rng.getrandbits(32), out_a, out_b]


S(0x487c70, 'ZMovementBaseMove::CalcNewSpeed (high) thiscall', 'thiscall', None, ret=None, gen=_args,
  note='unclaimed-04 batch 4; flags at owner+0x417 random; vtable slots 0x60 (self) and 0x10 (R) are stubs')
