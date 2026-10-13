"""specs_s2603.py - wider batch 2603. 0x43e700: thiscall(a1, a2, p, a4), ret 0x10. Bit 8 of byte this+0x18 set in about half the cases; slot 0x74 is a recorder
(thiscall, 2 args); 0x4690b0 hooked (thiscall, no args, records ECX); p points at three random dwords."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4690b0, 0, this=True)
    me = obj(c, 0x60, {0x74: pystub(c, 2, this=True)})
    e.wbytes(me + 0x18, bytes([r.choice([0x08, 0x00, 0xf7, 0xff, 0x18, 0x01])]))
    e.w32(me + 8, rnd(c, 0x20))
    p = rnd(c, 0x10)
    return [me, r.getrandbits(32), r.getrandbits(32), p, r.getrandbits(32)]


S(0x43e700, 'ZHELPER::ModifyBox (GUESS args)', 'thiscall', None, ret=None, gen=_gen, note='batch2603')
