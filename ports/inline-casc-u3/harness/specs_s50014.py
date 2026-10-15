"""specs_s50014.py - u3 batch 50014 (Haiku slot, run by Sonnet 5.5), tier H. 0x467d00: unaligned [this+0x136] / [this+0x1a6]; table slot 0x58 returns w (or 0); this slots 0x324 / 0x320 / 0x8c / 0x21c / 0x230 / 0x20;
w slot 0x84 and this slot 0x8c fill the vector partially (0x44c840 normalises it as exe code); the logger object at [0x700390] (slot 0x20 -> L, L slot 0x30 is cdecl with four args recorded); name pointer present or null."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g467d00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))

    pat = r.random() < 0.3   # unit vectors whose z is exactly +-0.5 (boundary of both thresholds)
    sx, sz = r.choice([1, -1]), r.choice([1, -1])

    def part(em, k):
        v = em.arg32(0)
        if pat:
            if em.reg('esp') is not None and not getattr(part, 'done', False):
                em.wbytes(v, _fb(sx * 0.8660254))
                em.wbytes(v + 8, _fb(sz * 0.5))
            return
        for j in (0, 2):
            if r.random() < 0.8:
                em.wbytes(v + 4 * j, _fb(r.choice([r.uniform(-5, 5), 0.0, r.uniform(-1, 1)])))
        if r.random() < 0.3:
            em.wbytes(v + 4, _fb(r.uniform(-5, 5)))
    w = obj(c, 0x20, {0x84: pystub(c, 1, this=True, deref={0: 3}, side=part)}, nslots=0x88 // 4) if r.random() > 0.1 else 0
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=w)})
    name = rnd(c, 0x20)
    e.w32(name + 4, r.choice([0, 0x1234, r.getrandbits(32)]))
    L = obj(c, 0x20, {0x30: pystub(c, 4, pop=0)}, nslots=0x34 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=L)}, nslots=0x24 // 4)
    e.w32(0x700390, lg)
    me = obj(c, 0x200, {0x324: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff])),
                        0x320: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0x200, 0x1ff, r.getrandbits(32)])),
                        0x8c: pystub(c, 1, this=True, deref={0: 3}, side=part),
                        0x21c: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, r.getrandbits(32)])),
                        0x230: pystub(c, 2, this=True),
                        0x20: pystub(c, 0, this=True, ret=name)}, nslots=0x328 // 4)
    f136 = r.getrandbits(32)
    f136 = (f136 | 0x200000) if r.random() < 0.85 else (f136 & ~0x200000)
    e.wbytes(me + 0x136, f136.to_bytes(4, 'little'))
    e.wbytes(me + 0x1a6, (0 if r.random() < 0.08 else r.getrandbits(32) | 1).to_bytes(4, 'little'))
    return [me]


S(0x467d00, 'GUESS pick facing-name string and apply', 'thiscall', None, ret=None, gen=_g467d00, nan_heap=True, note='batch50014')
