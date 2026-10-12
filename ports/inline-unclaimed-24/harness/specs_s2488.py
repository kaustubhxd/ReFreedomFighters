"""specs_s2488.py - decomp area 24, batch 2488.
0x46e9c0 (GUESS): thiscall; slot 0x25c with (0x688860, 0) returns a dword; nonzero is the result, otherwise this.
0x485f60 ZActionReloadItem::~ZActionReloadItem(flags): thiscall, returns this; writes the vtable 0x685294; __builtin_delete (0x634273,
cdecl, recorded) with (this, 0x40) when bit 0 is set.
0x49e490 ZRunParamAnim::~ZRunParamAnim(flags): thiscall, returns this; base step 0x4e6ce0 (recorded, thiscall, no argument), then
__builtin_delete with (this, 0xc1) when bit 0 is set.
0x5db150 ZDamageBox::CopyEventDataBlock(DBREAD&): thiscall; DBREAD::operator bool (0x4e5ef0, recorded, returns AL fixed per case)
stored as a byte at +0x88 and as a dword at +0x60."""
from pilot import S
from recruits_util import rnd, pystub, obj, clear_hooks, hook_rec


def _guess(c):
    clear_hooks(c)
    r = c.rng
    rv = r.choice([0, 0x10000 + 0x40, r.getrandbits(32)])
    o = obj(c, 0x40, {0x25c: pystub(c, 2, ret=rv)})
    return [o]


def _reload(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x634273, 2, pop=0)
    o = rnd(c, 0x40)
    return [o, r.choice([0, 1, 3])]


def _runparam(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e6ce0, 0, this=True)
    hook_rec(c, 0x634273, 2, pop=0)
    o = rnd(c, 0x100)
    return [o, r.choice([0, 1, 2])]


def _damage(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5ef0, 0, this=True, ret=r.choice([0, 1]))
    o = rnd(c, 0x100)
    db = rnd(c, 0x40)
    return [o, db]


S(0x46e9c0, 'GUESS 0x46e9c0', 'thiscall', None, ret='eax', gen=_guess, note='batch2488')
S(0x485f60, 'ZActionReloadItem::~ZActionReloadItem', 'thiscall', None, ret='eax', gen=_reload, note='batch2488')
S(0x49e490, 'ZRunParamAnim::~ZRunParamAnim', 'thiscall', None, ret='eax', gen=_runparam, note='batch2488')
S(0x5db150, 'ZDamageBox::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_damage, note='batch2488')
