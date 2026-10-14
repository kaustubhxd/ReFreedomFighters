"""specs_s35035.py - 0x514890 (stdcall, six stack args; o null in 1/6). Object with slots 0x33c, 0x360, 0x32c (1 arg), 0x2d0 (2 args), 0x35c (zero in half), 0x354 (AL true in half); [o+8] random word; 0x4dcb50
hooked (thiscall, 2 args). `on` and `set` include values whose low byte is zero."""
from pilot import S
from recruits_util import obj, clear_hooks, hook_rec, pystub


def _g514890(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4dcb50, 2, this=True)
    o = 0 if r.random() < 1 / 6 else obj(c, 0x20, {0x33c: pystub(c, 1, this=True), 0x35c: pystub(c, 0, ret=0 if r.random() < 0.5 else r.getrandbits(32) | 1, this=True),
                                                  0x360: pystub(c, 1, this=True), 0x354: pystub(c, 0, ret=(r.getrandbits(32) | 1) if r.random() < 0.5 else (r.getrandbits(32) & ~0xff), this=True),
                                                  0x2d0: pystub(c, 2, this=True), 0x32c: pystub(c, 1, this=True)}, nslots=0xe0)
    flag = lambda: r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    return [o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), flag(), flag()]


S(0x514890, 'GUESS switch mode and forward range', 'stdcall', None, ret=None, gen=_g514890, note='batch35035')
