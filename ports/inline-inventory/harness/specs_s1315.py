"""specs_s1315.py - inventory thread batch 1315 (src/batch1315.cpp): ZItem::PlaySound.

Owner answers (slot 0x2f4) come from a sequence: first call (non-null group or 0), second call (the group), then
arbitrary. The group's slot 0x20 answers the object that gets slots 0x94; the position outputs are quiet (not read).
"""
from pilot import S
from inv_helpers import Rec, rnd, set_global

SYS = 0x70039C


def play(c):
    r = Rec(c)
    sysobj = rnd(c, 0x2000, 4)
    set_global(c, SYS, sysobj)
    ref = rnd(c, 0x1000, 4)
    c.emu.w32(sysobj + 0x9B, ref)
    c.emu.w32(ref, r.vtable({0x4C: r.stub(40, 1, rand=True)}))

    ob = rnd(c, 0x80, 4)
    c.emu.w32(ob, r.vtable({0x94: r.stub(41, 2, rand=True, quiet_args=(0, 1))}))
    grp = rnd(c, 0x80, 4)
    c.emu.w32(grp, r.vtable({0x20: r.stub(42, 0, rets=[ob])}))

    first = c.rng.choice([0, grp])
    seq = [first, grp, c.rng.getrandbits(32)]
    state = {'i': 0}

    def g2f4(emu, res):
        i = state['i']
        state['i'] += 1
        v = seq[i] if i < len(seq) else 0
        emu.ret(eax=v, argbytes=0)

    self_obj = rnd(c, 0x200, 4)
    c.emu.w32(self_obj, r.vtable({
        0x2F4: g2f4,
        0x2C8: r.stub(43, 2, rand=True, quiet_args=(0, 1)),
        0x94: r.stub(44, 2, rand=True, quiet_args=(0, 1)),
    }))
    r.hook(0x43EC00, 45, 6, rand=True, quiet_args=(0, 1))
    return [self_obj, c.rng.choice([0, 1, 2, 7, 0xFFFF, c.rng.getrandbits(32)])]


S(0x46FFD0, 'ZItem::PlaySound', 'thiscall', None, ret=None, gen=play, note='batch1315')
