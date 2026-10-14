"""specs_s5708.py - unclaimed-57, batch 8: four call-free leaves from the full function list (names GUESS). 0x54db80 and 0x49b340 are
thiscall; 0x61c5c0 is cdecl (the caller pops); 0x4d61c0 is stdcall (ret 4). No stubs: none of them calls anything."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_with(off, edge):
    def gen(c):
        o = _rnd(c, 0x800)
        v = (1 if c.rng.random() < 0.3 else c.rng.getrandbits(32))
        if edge:
            v = c.rng.choice([0, 1, 2, 0xffffffff, c.rng.getrandbits(32)])
        c.emu.w32(o + off, v)
        return [o]
    return gen


def _two(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _three(c):
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x54db80, 'unnamed_54db80 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_obj_with(0x40ad, True),
  note='unclaimed-57 batch 8; leaf; returns 0 if +0x40ad == 1 else +0x40ad + 1')
S(0x49b340, 'unnamed_49b340 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_two,
  note='unclaimed-57 batch 8; leaf; stores two arguments at +0x14 and +0x18')
def _flag42e(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x42e, 1 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o]


S(0x4d61c0, 'unnamed_4d61c0 (GUESS) stdcall', 'stdcall', None, ret='al', gen=_flag42e,
  note='unclaimed-57 batch 8; leaf; al = dword +0x42e == 1 (the dword at +0x42e is 1 in half the cases, so both values occur)')
S(0x61c5c0, 'unnamed_61c5c0 (GUESS) cdecl', 'cdecl', None, ret=None, gen=_three,
  note='unclaimed-57 batch 8; leaf; stores two arguments at +0x34 and +0x38')
