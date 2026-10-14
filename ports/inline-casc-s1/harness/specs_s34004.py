"""specs_s34004.py - cascade escalation batch 34004: forwarder 0x63b690 (member +4, slot 8), empty-frame tail stubs 0x46fd90 / 0x4bf4c0,
0x4c1f70 (engine +0x9b object, slot 0x2c) and 0x483400 (decrement +0x602, flag +0x5ff when it hits zero)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g63b690(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    inner = obj(c, 0x40, {8: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    c.emu.w32(me + 4, inner)
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _tail(tgt):
    def g(c):
        clear_hooks(c)
        hook_rec(c, tgt, 1, ret=c.rng.getrandbits(32), this=True)
        return [rnd(c, 0x40), c.rng.getrandbits(32)]
    return g


def _g4c1f70(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x2c: pystub(c, 2, ret=r.getrandbits(32), this=True)})
    return [rnd(c, 0x40), r.getrandbits(32), r.getrandbits(32)]


def _g483400(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x700)
    v = r.choice([1, 1, 0, 2, 0xffffffff, r.getrandbits(32)])
    c.emu.wbytes(me + 0x602, v.to_bytes(4, 'little'))
    return [me]


S(0x63b690, 'GUESS forward to member +4 slot 8', 'thiscall', None, ret='eax', gen=_g63b690, note='batch34004')
S(0x46fd90, 'GUESS empty frame tail 0x46f9d0', 'thiscall', None, ret='eax', gen=_tail(0x46f9d0), note='batch34004')
S(0x4bf4c0, 'GUESS empty frame tail 0x4c1060', 'thiscall', None, ret='eax', gen=_tail(0x4c1060), note='batch34004')
S(0x4c1f70, 'GUESS forward to engine +0x9b slot 0x2c', 'thiscall', None, ret='eax', gen=_g4c1f70, note='batch34004')
S(0x483400, 'GUESS decrement +0x602, flag at zero', 'thiscall', None, ret=None, gen=_g483400, note='batch34004')
