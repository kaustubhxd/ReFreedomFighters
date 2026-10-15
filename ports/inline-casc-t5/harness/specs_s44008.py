"""specs_s44008.py - t5 (Sonnet) batch 44008: 0x64ff80."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _log(tag):
    return lambda emu, k: emu.calllog.append((tag,))


def g64ff80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x6449c0, 1, this=True, pop=4, ret=r.getrandbits(32))
    lastn = []

    def side40(emu, k):
        a = emu.arg32(0)
        if r.random() < 0.4:
            emu.w32(a, r.choice([0, 1, 100, 0xffffff00, r.getrandbits(32)]))
    st = obj(c, 0x20, {0xc: pystub(c, 1, this=True), 0x18: pystub(c, 2, this=True),
                       0x40: pystub(c, 1, this=True, nullflag=(), side=side40, deref={0: 1})}, nslots=0x44 // 4)
    sub = obj(c, 0x20, {0x1ac: pystub(c, 1, this=True)}, nslots=0x1b0 // 4)
    so = sysobj(c)
    e.wbytes(so + 0x190f, struct.pack('<I', sub))
    inner = obj(c, 0x20, {0x2c: pystub(c, 5, ret=r.getrandbits(32), pop=0, side=_log('log2'))}, nslots=0x30 // 4)
    g = obj(c, 0x20, {0x20: pystub(c, 2, ret=inner, this=True, side=_log('log1'))})
    e.w32(0x700390, g)
    hdr = rnd(c, 0x10)
    e.w32(hdr + 4, r.choice([0, 8, 0x10, r.randrange(0, 0x100)]))
    me = rnd(c, 0x40)
    e.w32(me + 0x20, hdr)
    b = hdr + e.r32(hdr + 4)
    e.w32(me + 0x28, (b + r.choice([0, 0, 4, 100, -4 & 0xffffffff, r.getrandbits(32) if r.random() < 0.3 else 0x7fffffff])) & 0xffffffff)
    e.w32(me + 0x38, rnd(c, 0x10))
    return [me, st]


S(0x64ff80, 'GUESS flush stream and call', 'thiscall', None, ret='al', gen=g64ff80, nan_heap=True, note='batch44008')
