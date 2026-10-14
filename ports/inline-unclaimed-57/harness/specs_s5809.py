"""specs_s5809.py - unclaimed-57, batch 109: 0x5d79f0 (GUESS name unnamed_5d79f0). Thiscall, no stack args, plain ret. The engine's sub-object (at
+0x9b) has fake slots: +0x58 (one arg, logged; the first two calls return random dwords that are stored raw, the last two return an object or
null, and the object's dword at +0x18 is stored), +0xb0 (no args: returns a plain object e3), +0x138 (no args: returns object e4, which has
fake slot +0x60 (two args, logged)), +0x4c (two args, logged; returns a random dword). The fastcall 0x4cc850 (another area's function) is a
logging stub returning a per-case value (zero in about half the cases). The global pointer at 0x7003a0 points at a block whose byte +0x79 is
cleared. The object at this+0x44 is a plain pointer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d79f0(c):
    e = c.emu
    m_v = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    o_objs = [_rnd(c, 0x40) for _ in range(2)]
    for o in o_objs:
        e.w32(o + 0x18, c.rng.getrandbits(32))
    null_s = c.rng.random() < 0.3
    null_s2 = c.rng.random() < 0.3
    r1v = c.rng.getrandbits(32)
    r2v = c.rng.getrandbits(32)
    e3 = _rnd(c, 0x40)
    e4 = _rnd(c, 0x40)
    v4 = c.rng.getrandbits(32)
    k = [0]

    def h58(em, r):
        i = k[0]
        k[0] += 1
        em.calllog.append(('58', i, None, (em.arg32(0),)))
        if i == 0:
            em.ret(eax=r1v, argbytes=4)
        elif i == 1:
            em.ret(eax=r2v, argbytes=4)
        elif i == 2:
            em.ret(eax=0 if null_s else o_objs[0], argbytes=4)
        else:
            em.ret(eax=0 if null_s2 else o_objs[1], argbytes=4)

    def hb0(em, r):
        em.calllog.append(('b0', 0, None, ()))
        em.ret(eax=e3, argbytes=0)

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=e4, argbytes=0)

    def h4c(em, r):
        em.calllog.append(('4c', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=v4, argbytes=8)

    def h60(em, r):
        em.calllog.append(('60', 0, 'E4' if em.reg('ecx') == e4 else 'other', (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=8)

    def hfast(em, r):
        em.calllog.append(('4cc850', 0, 'E3' if em.reg('ecx') == e3 else 'other', (em.reg('edx'),)))
        em.ret(eax=m_v, argbytes=0)
    e.hook(0x4cc850, hfast)

    vt_sub = e.fake_vtable('d79f0_sub', 200, {0x58: h58, 0xb0: hb0, 0x138: h138, 0x4c: h4c})
    vt_e4 = e.fake_vtable('d79f0_e4', 200, {0x60: h60})
    e.w32(e4, vt_e4)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    gblock = _rnd(c, 0x100)
    e.w32(0x7003a0, gblock)
    self_obj = _rnd(c, 0x300)
    e.w32(self_obj + 0x1de, c.rng.getrandbits(32))
    e.w32(self_obj + 0x1e2, c.rng.getrandbits(32))
    e.w32(self_obj + 0x1d6, c.rng.getrandbits(32))
    e.w32(self_obj + 0x1da, c.rng.getrandbits(32))
    e.w32(self_obj + 0x44, c.rng.getrandbits(32))
    return [self_obj]


S(0x5d79f0, 'unnamed_5d79f0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d79f0,
  note='unclaimed-57 batch 109; sub slots +0x58, +0xb0, +0x138, +0x4c fake; e4 slot +0x60; fastcall 0x4cc850 hooked (logs EDX)')
