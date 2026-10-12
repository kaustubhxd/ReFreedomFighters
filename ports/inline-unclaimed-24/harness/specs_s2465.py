"""specs_s2465.py - decomp area 24, batch 2465 (gap band).
0x441d50 (GUESS destructor) and 0x4440e0 ZROOM::~ZROOM: the base destructor (0x441c00 and 0x444020, recorders) runs first;
with flag bit 0 set, SetState(this, 0x83) (0x441d50) or SetState(this, 0xc4) (0x4440e0) when bit 2 is set, else operator
delete (0x45c510, recorder). Thiscall, ret 4, eax = this.
0x45be20 ZProjectMarks::FadeMark(unsigned int, float), thiscall, ret 8: slot 0x20 of the sys table's object at +0x190f gives
an object r; slot 0x44 of r is called with (the dword at (this+0x40)[index], the float bits)."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _dtor(base):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, base, 0, this=True)
        hook_rec(c, 0x4690b0, 2, pop=0)
        hook_rec(c, 0x45c510, 1, pop=0)
        return [rnd(c, 0x100), r.getrandbits(32)]
    return gen


def _fade(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    obj2 = obj(c, 0x40, {0x44: pystub(c, 2)})
    obj1 = obj(c, 0x40, {0x20: pystub(c, 0, ret=lambda emu, k: obj2)})
    so = sysobj(c)
    e.w32(so + 0x190f, obj1)
    o = rnd(c, 0x100)
    arr = rnd(c, 0x40)
    e.w32(o + 0x40, arr)
    return [o, r.randint(0, 15), r.getrandbits(32)]


S(0x441d50, 'GUESS: destructor (0x441d50)', 'thiscall', None, ret='eax', gen=_dtor(0x441c00), note='batch2465')
S(0x4440e0, 'ZROOM::~ZROOM', 'thiscall', None, ret='eax', gen=_dtor(0x444020), note='batch2465')
S(0x45be20, 'ZProjectMarks::FadeMark', 'thiscall', None, ret=None, gen=_fade, note='batch2465')
