"""specs_s2440.py - decomp area 24, batch 2440 (gap band).
0x449790 ZLIGHT::SetEffectLight(bool), 0x449820 ZLIGHT::SetLightAttributeChanged(bool): thiscall, ret 4; bit 2 (or 3)
of the dword at +0x18 is set or cleared by the low byte of the argument.
0x44c290 ZSNDOBJ::StartPitchShift(dword), thiscall, ret 4 (one argument): with d = [this+0x18], [d+0x60] = a - [d+0x64] and [d+0x64] = a.
0x443030 ZTreeGroup::GetDynamicChildTreeGroupList(out), thiscall, ret 4: *out = 0; with p = [this+0x7b] (null returns 0),
*out = p + 0x404 and the result is the high half of p with the word at p+2.
0x452e20 ZENVIRONMENT::Load(ZLoadGame*) and 0x452e40 ZENVIRONMENT::Save(ZSaveGame*): thiscall, ret 4, AL = result != 0 of
ZLIGHT::Load (0x449550) / ZLIGHT::Save (0x449600), both recorders returning a random value."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _bool(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x40)
    e = c.emu
    e.w32(o + 0x18, r.getrandbits(32))
    return [o, r.getrandbits(32)]


def _three(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    d = rnd(c, 0x80)
    e.w32(o + 0x18, d)
    return [o, r.getrandbits(32)]


def _tree(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    if r.random() < 0.7:
        p = rnd(c, 0x440)
        e.w32(o + 0x7b, p)
    else:
        e.w32(o + 0x7b, 0)
    return [o, rnd(c, 0x10)]


def _env(addr):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, addr, 1, this=True, ret=lambda emu, k: r.getrandbits(32))
        return [rnd(c, 0x80), rnd(c, 0x40)]
    return gen


S(0x449790, 'ZLIGHT::SetEffectLight', 'thiscall', None, ret=None, gen=_bool, note='batch2440')
S(0x449820, 'ZLIGHT::SetLightAttributeChanged', 'thiscall', None, ret=None, gen=_bool, note='batch2440')
S(0x44c290, 'ZSNDOBJ::StartPitchShift', 'thiscall', None, ret=None, gen=_three, note='batch2440')
S(0x443030, 'ZTreeGroup::GetDynamicChildTreeGroupList', 'thiscall', None, ret='eax', gen=_tree, note='batch2440')
S(0x452e20, 'ZENVIRONMENT::Load', 'thiscall', None, ret='al', gen=_env(0x449550), note='batch2440')
S(0x452e40, 'ZENVIRONMENT::Save', 'thiscall', None, ret='al', gen=_env(0x449600), note='batch2440')
