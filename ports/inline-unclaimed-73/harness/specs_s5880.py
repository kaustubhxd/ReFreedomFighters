"""specs_s5880.py - area 73 batch 58 (gap band, GUESS names).
FUN_4f4520 (plain ret): calls 0x4ef1c0 (hooked, logged, no args), then if [this+0xac] is non-null deletes it through
0x634273(ptr, 1) and clears [this+0xac].
FUN_4f8480 (ret 4): [this+0x97] = arg; [this+0x9b] = 1.0f / (float)(arg - 1), the constant 1.0 at 0x678858.
FUN_4fa5e0 (ret 4): when [this+0x70] != 0x20: vtable +0x2ec(2), vtable +0x314(), vtable +0x2ec(8)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4f4520(c):
    e = c.emu

    def h_ef1c0(em, r):
        em.calllog.append(('4ef1c0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

    def h_del(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    e.hook(0x4ef1c0, h_ef1c0)
    e.hook(0x634273, h_del)
    o = _rnd(c, 0x100)
    e.w32(o + 0xac, _rnd(c, 0x20) if c.rng.random() < 0.6 else 0)
    return [o]


def _gen_4f8480(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _gen_4fa5e0(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x70, c.rng.choice([0x20, c.rng.getrandbits(32)]))
    e.w32(o, e.logging_vtable('fa5e0', 0x320 // 4,
                              impl={0x2ec: lambda em, a: (0, None), 0x314: lambda em, a: (0, None)},
                              argwords={0x2ec: 1, 0x314: 0}))
    return [o, c.rng.getrandbits(32)]


S(0x4f4520, 'GUESS FUN_4f4520 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f4520,
  note='area 73 batch 58; calls 0x4ef1c0; if [this+0xac]: delete(ptr, 1), [this+0xac] = 0')
S(0x4f8480, 'GUESS FUN_4f8480 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f8480,
  note='area 73 batch 58; [this+0x97] = arg; [this+0x9b] = 1.0f / (float)(arg-1)')
S(0x4fa5e0, 'GUESS FUN_4fa5e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4fa5e0,
  note='area 73 batch 58; if [this+0x70] != 0x20: vt+0x2ec(2), vt+0x314(), vt+0x2ec(8)')
