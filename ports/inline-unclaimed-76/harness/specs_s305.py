"""specs_s305.py - gap band 0x601000-0x621000 (docs/20-unclaimed-76.md), batch 305: thirteen small field accessors. Pure memory,
except 0x604d50 (calls the first slot of its argument object: a logged stub)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _idx_obj(c):
    e = c.emu
    self_ = _rnd(c, 0x200)
    buf = _rnd(c, 0x200)
    e.w32(self_ + 0x17, buf)
    e.w32(self_ + 0x23, buf)
    idx = c.rng.randrange(1, 12)
    return [self_, idx]


def _idx_val(c):
    s, idx = _idx_obj(c)
    return [s, idx, c.rng.getrandbits(16)]


def _slot0(c):
    e = c.emu
    o_vt = e.logging_vtable('kid604d', 0x2, impl={0: lambda em, a: (0, None)}, argwords={0: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0xc, c.rng.getrandbits(32))
    return [self_, o]


def _cd_obj(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _cd_two(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x601560, 'setByte18 (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch305; ret 4')
S(0x6044e0, 'setWord24 (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch305; ret 4')
S(0x6106c0, 'setDword118a (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch305; ret 4')
S(0x6106d0, 'setDword20 (GUESS)', 'thiscall', None, ret=None, gen=_obj, note='batch305; ret 4')
S(0x606d90, 'dwordAt17 (GUESS)', 'thiscall', None, ret='eax', gen=_idx_obj, note='batch305; ret 4')
S(0x606d40, 'wordAt23 (GUESS)', 'thiscall', None, ret='eax', gen=_idx_obj, note='batch305; ret 4')
S(0x606e80, 'setWordAt23 (GUESS)', 'thiscall', None, ret=None, gen=_idx_val, note='batch305; ret 8')
S(0x604d50, 'callSlot0 (GUESS)', 'thiscall', None, ret=None, gen=_slot0, note='batch305; ret 4')
S(0x61f590, 'readAt114 (GUESS)', 'cdecl', None, ret='eax', gen=lambda c: [_rnd(c, 0x200)], note='batch305; plain ret')
S(0x61c590, 'setAt3c (GUESS)', 'cdecl', None, ret=None, gen=_cd_two, note='batch305; plain ret')
S(0x61c600, 'setAt6c (GUESS)', 'cdecl', None, ret=None, gen=_cd_two, note='batch305; plain ret')
S(0x61c610, 'setAt60 (GUESS)', 'cdecl', None, ret=None, gen=_cd_two, note='batch305; plain ret')
S(0x61c620, 'setAt40 (GUESS)', 'cdecl', None, ret=None, gen=_cd_two, note='batch305; plain ret')
