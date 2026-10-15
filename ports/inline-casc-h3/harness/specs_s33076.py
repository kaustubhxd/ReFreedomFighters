"""specs_s33076.py - h3 (Sonnet) batch 33076: tier H float/SSE functions."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.2))


def _g64fbf0(c):
    clear_hooks(c)
    me = rnd(c, 0x100)
    c.emu.w32(me + 0xb9, __import__('struct').unpack('<I', __import__('struct').pack('<f', c.fv(-10.0, 10.0, 0.2)))[0])
    return [me]


def _g51c540(c):
    clear_hooks(c)
    hook_rec(c, 0x51c470, 0, this=True)
    me = rnd(c, 0x600)
    c.emu.w32(me + 0x597, __import__('struct').unpack('<I', __import__('struct').pack('<f', c.fv(-10.0, 10.0, 0.2)))[0])
    return [me]


def _gf(c):
    clear_hooks(c)
    return [rnd(c, 0x100), _fl(c)]


def _g51cef0(c):
    clear_hooks(c)
    return [rnd(c, 0x4c0), _w(c), _fl(c)]


def _gi(c):
    clear_hooks(c)
    return [rnd(c, 0x51c0 if False else 0x52c0), c.rng.choice([0, 1, -1, 127, -127, 0x7fffffff, -0x80000000 & 0xffffffff, _w(c), c.rng.randrange(-1000, 1000) & 0xffffffff])]


def _g5d0c60(c):
    clear_hooks(c)
    return [rnd(c, 0xb40), c.rng.choice([0, 1, 0xffffffff, 127, 0x7fffffff, 0x80000000, _w(c), c.rng.randrange(-1000, 1000) & 0xffffffff])]


def _g514410(c):
    clear_hooks(c)
    hook_rec(c, 0x523b90, 2, this=True)
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, rnd(c, 0x20)) if False else None
    me = rnd(c, 0x600)
    c.emu.w32(me + 0x5c, rnd(c, 0x20))
    return [me, _w(c), _fl(c)]


S(0x64fbf0, 'GUESS float field times 6', 'thiscall', None, ret='st0', gen=_g64fbf0, note='batch33076', )
S(0x51c540, 'GUESS call then return float field', 'thiscall', None, ret='st0', gen=_g51c540, note='batch33076')
S(0x527250, 'GUESS store float arg', 'thiscall', None, ret=None, gen=_gf, note='batch33076')
S(0x4dce50, 'GUESS flag and store float arg', 'thiscall', None, ret=None, gen=_gf, note='batch33076')
S(0x51cef0, 'GUESS store dword and float', 'thiscall', None, ret=None, gen=_g51cef0, note='batch33076')
S(0x539c70, 'GUESS int to float times 0.01', 'thiscall', None, ret=None, gen=_gi, note='batch33076')
S(0x5d0c60, 'GUESS int over -127 to float', 'thiscall', None, ret=None, gen=_g5d0c60, note='batch33076')
S(0x514410, 'GUESS forward arg and float', 'thiscall', None, ret=None, gen=_g514410, note='batch33076')
