"""specs_s2735.py - unclaimed-27 batch 37: FUN_584c30 (GUESS, thiscall, one argument, ret 4, void). The object is 0xb00 random bytes
with a list at +0x750: count 0..6 and the elements; the argument v is one of the list's elements in about 70% of cases, else random.
The assert hook at 0x7003b0 is a counting stub (non-null, per the checker rule). No other callees. No SEH frame."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f4c30(c):
    rec = c.emu.alloc(0x10, 4)   # +0 assert hook calls
    code = b'\xff\x05' + rec.to_bytes(4, 'little') + b'\xc3'   # inc dword [rec]; ret (cdecl, no args)
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(0x7003b0, st)
    o = _rnd(c, 0xb00)
    cnt = c.rng.randint(0, 6)
    c.emu.w32(o + 0x750, cnt)
    elems = [c.rng.choice([1, 2, 3, 0x40, 0x41, 0x42, 0x77, c.rng.getrandbits(32)]) for _ in range(cnt)]
    for i, e in enumerate(elems):
        c.emu.w32(o + 0x754 + 4 * i, e)
    if elems and c.rng.random() < 0.7:
        v = c.rng.choice(elems)
    else:
        v = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, v]


S(0x584c30, 'FUN_584c30 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f4c30, reg_values=True,
  note='unclaimed-27 batch 37; assert hook 0x7003b0 is a counting stub; no SEH')
