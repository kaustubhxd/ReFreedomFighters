from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = obj(c, 0x5200, {
        0x19c: pystub(c, 0, ret=1, this=True, pop=0),
        0x164: pystub(c, 0, ret=r.getrandbits(32), this=True, pop=0),
    }, nslots=0x19d // 4)
    e.wbytes(self + 0x50ba, b'\x01')
    buf = rnd(c, 0x20)
    e.w32(self + 0x51a5, buf)
    return [self, r.getrandbits(32)]


S(0x539850, 'GUESS encode value into staged output buffer', 'thiscall', None,
  ret='eax', gen=gen, note='batch62047')
