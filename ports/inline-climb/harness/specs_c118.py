"""specs_c118.py - climb thread batch 118: ZLNKWHANDS::CalcAnimRemapNames (0x472460)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt, cstr


def _h(c):
    r = c.rng
    e = c.emu
    pool = [rnd(c, 0x100) for _ in range(6)]
    for p in pool:
        e.w32(p + 0x7c, r.getrandbits(32))

    def lookup(e, t, a):
        name = bytes(e.rbytes(a[0], 40)).split(b'\0')[0]
        k = r.random()
        ret = 0 if k < 0.2 else pool[r.randrange(len(pool))]
        return (ret, None, (name,))
    vt = rvt(e, 'hands', {0x35c: (1, lookup)}, nslots=0x360 // 4)
    self_ = rnd(c, 0x400)
    e.w32(self_, vt)
    return [self_]


S(0x472460, 'ZLNKWHANDS::CalcAnimRemapNames', 'thiscall', None, ret=None, gen=_h,
  note='c118; name lookups are logging fakes returning pool objects or null')
