"""specs_s5755.py - unclaimed-57, band batch 55 (GUESS): 0x5c7c30, thiscall, two stack args (w, unused), returns 0. The word w equals this+0x4c in
half the cases. The engine's sub-object (+0x9b) holds a pointer at +0xae4 to a stub object whose slot 0 (two args) logs and returns a fixed value.
The callees 0x589c20 (thiscall, four args, ECX = the global at 0x7003b8, returns a value) and 0x59a580 (thiscall, no args) are hooked and logged;
their effects are not modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _seq(c):
    rv = c.rng.getrandbits(32)

    def h589(em, r):
        em.calllog.append(('589c20', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3))))
        em.ret(eax=rv, argbytes=16)

    def h59a(em, r):
        em.calllog.append(('59a580', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x589c20, h589)
    c.emu.hook(0x59a580, h59a)
    r0 = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('band5c7c30_c2', 8, impl={0: lambda em, a: (r0, None)}, argwords={0: 2})
    c2 = _rnd(c, 0x40)
    c.emu.w32(c2, vt)
    obj = _rnd(c, 0xb00)
    c.emu.w32(obj + 0xae4, c2)
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x9b, obj)
    c.emu.w32(0x70039c, eng)
    g = _rnd(c, 0x100)
    c.emu.w32(0x7003b8, g)
    me = _rnd(c, 0x200)
    c.emu.wbytes(me + 0x4c, bytes([0, 0]))
    wv = c.rng.getrandbits(16)
    c.emu.wbytes(me + 0x4c, bytes([wv & 0xff, wv >> 8]))
    w = wv if c.rng.random() < 0.5 else (wv ^ 1) & 0xffff
    return [me, w | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)]


S(0x5c7c30, 'unnamed_5c7c30 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_seq,
  note='unclaimed-57 band batch 55; sub object slot 0 stubbed; 0x589c20 and 0x59a580 hooked and logged')
