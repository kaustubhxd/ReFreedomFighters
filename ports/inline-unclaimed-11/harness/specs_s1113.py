"""specs_s1113.py - unclaimed-11 batch 14 (slice 10, full list): four leaves, GUESS where the name map disagrees with the body.
0x429460 (GUESS, thiscall, one arg, ret 4): al = (dword at this+4 == arg).
0x5ac620 (GUESS name CMessageBasics::SetPositionScreenX, thiscall, two args, ret 8): dword arg1 to this+9, dword arg2 to this+0x11.
0x43d960 (GUESS name ZHapticsBase::SetEnabled, thiscall, one arg, ret 4): byte (arg byte == 0) to this+0x349.
0x48f760 (GUESS, no name, stdcall: two stack pointers, ret 8): al = (dword at *arg1 == dword at *arg2)."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x400, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    return o


def _cmp_gen(c):
    o = _obj(c)
    v = c.rng.getrandbits(32)
    c.emu.w32(o + 4, v if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o, v]


def _two(c):
    o = _obj(c)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _ptr2(c):
    # stdcall shape: two pointer arguments, no this. The two dwords are equal in about half the cases.
    a = c.emu.alloc(8, 4)
    b = c.emu.alloc(8, 4)
    v = c.rng.getrandbits(32)
    c.emu.w32(a, v)
    c.emu.w32(b, v if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [a, b]


S(0x429460, 'GUESS (no GC name) compare +4 thiscall', 'thiscall', None, ret='al', gen=_cmp_gen,
  note='unclaimed-11 batch 14 (slice 10)')
S(0x5ac620, 'GUESS CMessageBasics::SetPositionScreenX (name doubtful) thiscall', 'thiscall', None, ret=None, gen=_two,
  note='unclaimed-11 batch 14 (slice 10)')
S(0x43d960, 'GUESS ZHapticsBase::SetEnabled (sense doubtful) thiscall', 'thiscall', None, ret=None,
  gen=lambda c: [_obj(c), c.rng.choice([0, 1, 0x100, 0xff, c.rng.getrandbits(8)])], note='unclaimed-11 batch 14 (slice 10)')
S(0x48f760, 'GUESS (no GC name) equal dwords through two pointers', 'stdcall', None, ret='al', gen=_ptr2,
  note='unclaimed-11 batch 14 (slice 10); ABI shape: two stack args, ret 8')
