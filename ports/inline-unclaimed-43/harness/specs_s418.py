"""specs_s418.py - residue 2 leaves 0x57f960 (thiscall, no arguments, returns this) and 0x54dfa0 (thiscall, no arguments).
0x54dfa0 appends the dword at this+0x61 to the array at [this+8] (counter at +0x8018, drawn 0..9) and clears flags; the object
at this+0x29 is a zeroed block or NULL, and dword +0x75 is 3 in half the cases so both branches run. No calls in either row."""
from pilot import S
import engine_stubs as E


def _gen_a(c):
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [o]


def _gen_b(c):
    r = c.rng
    o = E.zero_obj(c, 0x100)
    c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x100)))
    arr = E.zero_obj(c, 0x8100)
    c.emu.w32(arr + 0x8018, r.randint(0, 9))
    c.emu.w32(o + 0x8, arr)
    c.emu.w32(o + 0x61, r.getrandbits(32))
    c.emu.w32(o + 0x75, 3 if r.random() < 0.5 else r.getrandbits(32))
    p = 0 if r.random() < 0.3 else E.zero_obj(c, 0x80)
    c.emu.w32(o + 0x29, p)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x57f960, 'constructor: constant vtable-like dwords and zero fields (residue 2 leaf) thiscall', 'thiscall', None, ret='eax',
  gen=_gen_a, note='residue 2 batch 418; leaf, no calls')
S(0x54dfa0, 'append dword to array and clear flags (residue 2 leaf) thiscall', 'thiscall', None, ret=None, gen=_gen_b,
  note='residue 2 batch 418; leaf, no calls')
