"""specs_s1680.py - residue 13 batch 1680: 0x476ae0 (queue step, five stack arguments, ret 0x14). The manager's slot 0x58
returns an element object (random, sometimes zero) recorded with its argument; the element has slots 0x2c and 0x138; the
obj argument has slot 0x288. The counter at +0x60 is 1..3, so both the reset and the no-reset branches run."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    elem_obj = obj(c, 0x40, {0x2c: stub(c, seq, 0), 0x138: stub(c, seq, 3)})
    mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=elem_obj if r.random() < 0.8 else 0)})
    from sthelp import sysobj
    sysobj(c, db=mgr)
    o = obj(c, 0x40, {0x288: stub(c, seq, 3)})
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x60, r.randint(1, 3))
    c.emu.w32(me + 0x5c, r.randint(1, 3))
    arr = rnd(c, 16)
    c.emu.w32(me + 0x68, arr)
    for i in range(4):
        c.emu.w32(arr + 4 * i, r.getrandbits(32))
    c.emu.w16(me + 0x70, r.getrandbits(16))
    return [me, o, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x476ae0, 'GUESS FUN_476ae0', 'thiscall', None, ret='eax', gen=_gen, note='batch1680; queue step; ret 0x14')
