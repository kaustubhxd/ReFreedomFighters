"""specs_s5808.py - unclaimed-57, batch 108: 0x5d78e0 (GUESS name unnamed_5d78e0). Thiscall, no stack args, plain ret. The engine (global 0x70039c) is a
0x2000-byte block with its own fake vtable (slot +0x1cc, one arg, logged). The optional object q at +0x1907 is present in about seven cases in ten
(slot +0xc: three args, logged). p at +0x190f has fake slots: +0xdc (no args, returns a small random int), +0xd8 (one float argument, logged as its
bit pattern, returns a small random int), +0x134 (three args: two dwords and a float, logged), +0x138 (two args, logged), +0x50 (no args, logged).
The callee 0x5d7b10 (unclaimed in the docs) is a logging stub that writes nothing. The engine dword at +0x40 is random, so the stored +0x1c8 is checked."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d78e0(c):
    e = c.emu
    v0 = c.rng.randrange(-500, 501)
    r0 = c.rng.randrange(-500, 501)

    def hq(em, r):
        em.calllog.append(('q0c', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    def heng(em, r):
        em.calllog.append(('eng1cc', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def hdc(em, r):
        em.calllog.append(('dc', 0, None, ()))
        em.ret(eax=v0 & 0xffffffff, argbytes=0)

    def hd8(em, r):
        em.calllog.append(('d8', 0, None, (em.arg32(0),)))
        em.ret(eax=r0 & 0xffffffff, argbytes=4)

    def h134(em, r):
        em.calllog.append(('134', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)

    def h138(em, r):
        em.calllog.append(('138', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def h50(em, r):
        em.calllog.append(('50', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    def h5d7b10(em, r):
        em.calllog.append(('5d7b10', 0, None, ()))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5d7b10, h5d7b10)

    vt_eng = e.fake_vtable('d78e0_eng', 200, {0x1cc: heng})
    vt_q = e.fake_vtable('d78e0_q', 200, {0xc: hq})
    vt_p = e.fake_vtable('d78e0_p', 200, {0xdc: hdc, 0xd8: hd8, 0x134: h134, 0x138: h138, 0x50: h50})
    eng = _rnd(c, 0x2000)
    e.w32(eng, vt_eng)
    e.w32(eng + 0x40, c.rng.getrandbits(32))
    q = _rnd(c, 0x40)
    e.w32(q, vt_q)
    e.w32(eng + 0x1907, 0 if c.rng.random() < 0.3 else q)
    p = _rnd(c, 0x40)
    e.w32(p, vt_p)
    e.w32(eng + 0x190f, p)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x300)  # the function writes +0x1c8: the object must cover it
    e.w32(self_obj + 0x1c8, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d78e0, 'unnamed_5d78e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d78e0,
  note='unclaimed-57 batch 108; engine slot +0x1cc, q slot +0xc, p slots +0xdc, +0xd8, +0x134, +0x138, +0x50 fake; 0x5d7b10 hooked (logs)')
