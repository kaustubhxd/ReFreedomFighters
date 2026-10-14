"""specs_s35044.py - 0x603900 (thiscall, no args). Stack of 0..4 entries (8 bytes: value dword, kind byte at +4): kind 4 (value = object with slots 0x24 (returns an object with slot 0x28) and 0x28) in half
the entries, any other kind byte (value random) otherwise; [this+0x14] = count, [this+0xc] = entries; assert hook always set (never reached)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g603900(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    n = r.choice([0, 1, 2, 3, 4])
    ents = rnd(c, 0x40)
    for i in range(n):
        if r.random() < 0.5:
            tgt = obj(c, 0x10, {0x28: pystub(c, 0, this=True)}, nslots=0x10)
            v = obj(c, 0x10, {0x24: pystub(c, 0, this=True, ret=tgt), 0x28: pystub(c, 0, this=True)}, nslots=0x10)
            kind = 4
        else:
            v = r.getrandbits(32)
            kind = r.choice([0, 1, 2, 3, 5, 0xff])
        e.w32(ents + 8 * i, v)
        e.wbytes(ents + 8 * i + 4, bytes([kind]))
    me = rnd(c, 0x20)
    e.w32(me + 0x14, n)
    e.w32(me + 0xc, ents)
    return [me]


S(0x603900, 'GUESS pop and release tagged stack entries', 'thiscall', None, ret=None, gen=_g603900, note='batch35044')
