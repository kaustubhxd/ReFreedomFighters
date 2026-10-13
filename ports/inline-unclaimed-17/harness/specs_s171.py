"""specs_s171.py - unclaimed area 17, player-mechanics slice: 0x53e900 CRigidBody::Disable (calls into exe code)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _disable(c):
    obj = _rnd(c, 0x200)
    if c.rng.random() < 0.6:
        blk = _rnd(c, 0x100)
        c.emu.w32(obj + 0x62, blk)
    else:
        c.emu.w32(obj + 0x62, 0)
    return [obj]


S(0x53e900, 'CRigidBody::Disable', 'thiscall', None, ret=None, gen=_disable,
  note='batch171; calls exe code (ext_635490, ext_634273, ext_6352a0); the object pointer is nulled')
