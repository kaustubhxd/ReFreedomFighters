"""specs_s1681.py - residue 13 batch 1681: 0x476b50 (queue step, seven stack arguments, ret 0x1c). Same element and manager
as batch 1680; the element records slot 0x74 (two arguments) and the obj argument records slot 0x288 (three arguments)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    elem_obj = obj(c, 0x40, {0x2c: stub(c, seq, 0), 0x74: stub(c, seq, 2), 0x138: stub(c, seq, 3)})
    mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=elem_obj if r.random() < 0.8 else 0)})
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
    return [me, o] + [r.getrandbits(32) for _ in range(5)]


S(0x476b50, 'GUESS FUN_476b50', 'thiscall', None, ret='eax', gen=_gen, note='batch1681; queue step; ret 0x1c')
