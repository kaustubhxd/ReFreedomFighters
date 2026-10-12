"""specs_s311.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 311: three compare-and-copy functions. The object
at this+0x1377 has a logged stdcall slot 0x94 (three arguments). The source is the argument (or the exe default 0x6efc90)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cc(off):
    def gen(c):
        e = c.emu

        def h(em, r):
            em.calllog.append(('obj94', 0x94, tuple(em.arg32(k) for k in range(3))))
            em.ret(eax=rv, argbytes=12)

        rv = c.rng.getrandbits(32)
        vt = e.fake_vtable('obj311', 0x95, {0x94: h})
        obj = _rnd(c, 0x40)
        e.w32(obj, vt)
        self_ = _rnd(c, 0x1500)
        e.w32(self_ + 0x1377, obj)
        src = _rnd(c, 0x40)
        if c.rng.random() < 0.5:                  # equal in all 16 dwords, so the compare returns the last one
            e.wbytes(self_ + off, e.rbytes(src, 0x40))
        a = src if c.rng.random() < 0.8 else 0
        return [self_, a]
    return gen


S(0x6107e0, 'cc6107 (GUESS)', 'thiscall', None, ret='eax', gen=_cc(0x142a), note='batch311; ret 4; slot 0x94 logged')
S(0x610e20, 'cc610e (GUESS)', 'thiscall', None, ret='eax', gen=_cc(0x146a), note='batch311; ret 4; slot 0x94 logged')
S(0x610f20, 'cc610f (GUESS)', 'thiscall', None, ret='eax', gen=_cc(0x14aa), note='batch311; ret 4; slot 0x94 logged')
