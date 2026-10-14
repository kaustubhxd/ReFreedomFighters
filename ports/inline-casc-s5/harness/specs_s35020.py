"""specs_s35020.py - 0x51e700 (stdcall(o, on, c)). Object slots 0x33c, 0x360, 0x32c (1 arg), 0x2d0 (2 args), 0x35c (returns zero in half), 0x354 (returns AL true in half); `on` includes values whose low byte is 0."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g51e700(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x33c: pystub(c, 1, this=True), 0x35c: pystub(c, 0, ret=0 if r.random() < 0.5 else r.getrandbits(32) | 1, this=True),
                      0x360: pystub(c, 1, this=True), 0x354: pystub(c, 0, ret=(r.getrandbits(32) | 1) if r.random() < 0.5 else (r.getrandbits(32) & ~0xff), this=True),
                      0x2d0: pystub(c, 2, this=True), 0x32c: pystub(c, 1, this=True)}, nslots=0xe0)
    return [o, r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]), r.getrandbits(32)]


S(0x51e700, 'GUESS switch mode on/off', 'stdcall', None, ret=None, gen=_g51e700, note='batch35020')
