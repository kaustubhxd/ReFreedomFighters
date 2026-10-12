"""specs_s2434.py - decomp area 24, batch 2434.
0x651330 ZRender::UPlotFNxt(const char*), cdecl (the caller pops 16): the dword at this+0x78 is bumped and the vtable slot
0x124 is called with (this, 0, old count, name) as four stack arguments; the callee is a recorder that pops nothing.
0x4360f0 (GUESS owner), thiscall, ret 4, AL: when the index is below the count at +0x60 and the element at +0x20+4*index is
set, its slot 0x34 is called (no arguments) and the result is returned; else 0. Elements are recorders or null.
0x436230 ZSysInput::StopAllGCEffects(int), thiscall, ret 4, AL: the same element lookup, slot 0x40 is called and AL = 1;
else 0."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks


def _uplot(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x100, {0x124: pystub(c, 4, pop=0)})
    c.emu.w32(o + 0x78, r.getrandbits(32))
    return [o, rnd(c, 0x20)]


def _elems(slot):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        o = rnd(c, 0x100)
        cnt = r.randint(0, 6)
        e.w32(o + 0x60, cnt)
        for i in range(cnt + 1):
            if i == cnt or (i < cnt and r.random() < 0.8):
                el = obj(c, 0x40, {slot: pystub(c, 0, pop=0, ret=lambda emu, k: r.getrandbits(32))})
            else:
                el = 0
            e.w32(o + 0x20 + 4 * i, el)
        return [o, r.randint(0, 8)]
    return gen


S(0x651330, 'ZRender::UPlotFNxt', 'cdecl', None, ret=None, gen=_uplot, note='batch2434')
S(0x4360f0, 'GUESS: indexed slot-0x34 call (0x4360f0)', 'thiscall', None, ret='al', gen=_elems(0x34), note='batch2434')
S(0x436230, 'ZSysInput::StopAllGCEffects', 'thiscall', None, ret='al', gen=_elems(0x40), note='batch2434')
