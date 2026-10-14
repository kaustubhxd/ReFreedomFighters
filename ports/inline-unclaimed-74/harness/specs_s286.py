"""specs_s286.py - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaves: 0x545d10 (indexed record read into three
out-parameters) and 0x514350 (engine slot 0x4c result and a 0x12c call on this)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rec(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    base = _rnd(c, 0x34 * 24 + 0x40)
    e.w32(self_ + 0xf, base)
    a = c.rng.choice([c.rng.randrange(0, 20), c.rng.getrandbits(32) & 0x3fff])
    return [self_, a, _rnd(c, 0x20), _rnd(c, 0x20), _rnd(c, 0x20)]


def _req(c):
    e = c.emu
    r = c.rng.getrandbits(32)
    o_vt = e.logging_vtable('eng514', 0x14, impl={0x4c: lambda em, a: (r, None)}, argwords={0x4c: 0})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    def h12c(em, r):                       # logs the first two arguments only: the third is a stack address (&local)
        args = [em.arg32(k) for k in range(3)]
        em.calllog.append(('self514', 0x12c, tuple(args[:2])))
        em.ret(eax=0, argbytes=12)
    self_vt = e.fake_vtable('self514', 0x4c, {0x12c: h12c})
    self_ = _rnd(c, 0x400)
    e.w32(self_, self_vt)
    e.w16(self_ + 0x211, c.rng.getrandbits(16))
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x545d10, 'readRec (GUESS)', 'thiscall', None, ret=None, gen=_rec, note='batch286; ret 0x10')
# 0x514350 is held out: the exe leaves ESI equal to this on return (its second 'push esi' is popped into ESI before the
# epilogue, and the first saved ESI is never restored), so a C port reports 'clobbered esi'. Needs an asm epilogue. Not in src/.
_HELD = (_req,)
