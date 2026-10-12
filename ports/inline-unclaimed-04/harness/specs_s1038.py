"""specs_s1038.py - unclaimed-04 batch 38 (docs/20-unclaimed-04.md): 0x654cb0 (thiscall, three stack arguments, ret 0xc).
this->vt[0x230](a1, a2, a3) (recording stub); then bit 0x80 is set in four bytes of the global object (0x70039c): +0xa10,
+0xad8, +0x13fc and +0x13f7. The global object is a random 0x2000-byte block set in setup."""
from pilot import S


def _setup(c):
    G = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(G, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(0x70039c, G)


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(0x100))

    def h230(em, r):
        em.calllog.append(('vt.230', 0, em.reg('ecx'), tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=12)

    vt = c.emu.fake_vtable('owner654', 0x230 // 4 + 1, {0x230: h230})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x654cb0, 'unknown::vt230_then_or_bits (unknown) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 38; vt slot 0x230 recording stub (GUESS)')
