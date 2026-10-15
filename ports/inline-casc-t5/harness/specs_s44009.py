"""specs_s44009.py - t5 (Sonnet) batch 44009: 0x515850."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def g515850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)

    def fill(emu, k):
        a = emu.arg32(1)
        for i in range(3):
            emu.w32(a + 4 * i, r.getrandbits(32))
    hook_rec(c, 0x523470, 3, this=True, pop=0xc, side=fill, ret=r.getrandbits(32))

    def edx_log(emu, k):
        p = emu.reg('edx')
        emu.calllog.append(('4de040', tuple(emu.r32(p + 4 * i) for i in range(3))))
    hook_rec(c, 0x4de040, 1, this=True, pop=4, side=edx_log)

    def fv():
        return r.choice([r.uniform(-5, 5), r.uniform(0.1, 3), 0.0, 1.0, r.uniform(-100, 100), 0.5])
    s10 = r.choice([1.0, 2.0, r.uniform(0.1, 5), -1.5, 0.0])
    cobj = obj(c, 0x40, {0xc: pystub(c, 0, this=True, st0=fv()), 0x10: pystub(c, 0, this=True, st0=s10),
                         0x14: pystub(c, 0, this=True, st0=fv())}, nslots=0x18 // 4)
    e.w32(cobj + 0x24, r.choice([_bits(fv()), _bits(r.uniform(0, 1)), _bits(r.uniform(2, 50)), _bits(0.0), e.r32(0x680a84), e.r32(0x680a84)]))
    me = obj(c, 0x280, {0x80: pystub(c, 2, this=True, ret=r.getrandbits(32))}, nslots=0x84 // 4)
    e.w32(me + 0x5c, cobj)
    e.wbytes(me + 0x22f, struct.pack('<I', r.choice([_bits(fv()), _bits(r.uniform(0, 100)), NAN, _bits(1e9)])))
    e.wbytes(me + 0x267, struct.pack('<I', r.choice([_bits(fv()), _bits(r.uniform(0, 5)), _bits(1.0)])))
    return [me]


S(0x515850, 'GUESS compute step and apply', 'thiscall', None, ret=None, gen=g515850, nan_heap=True, note='batch44009')
