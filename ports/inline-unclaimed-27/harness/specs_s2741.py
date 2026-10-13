"""specs_s2741.py - unclaimed-27 batch 43 (residue 12): 0x656140 (stdcall, two pointer args), 0x64fc00 (thiscall, one out pointer), 0x639b80
(stdcall, four ignored args, returns 0; calls the assert hook at 0x7003b0). The assert hook is a counting stub (non-null, the checker rule).
No other hooks; all stubs are the hook only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f0(c):
    rec = c.emu.alloc(0x10, 4)
    code = b'\xff\x05' + rec.to_bytes(4, 'little') + b'\xc3'   # inc dword [rec]; ret (cdecl, no args)
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(0x7003b0, st)
    c.emu.mu.ctl_flush_tb()
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _f1(c):
    o = _rnd(c, 0x80)
    out = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [o, out]


def _f2(c):
    rec = c.emu.alloc(0x10, 4)
    code = b'\xff\x05' + rec.to_bytes(4, 'little') + b'\xc3'
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(0x7003b0, st)
    c.emu.mu.ctl_flush_tb()
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _f656(c):
    dst = _rnd(c, 0x10)
    src = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [dst, src]


S(0x656140, 'GUESS copy dword (stdcall)', 'stdcall', None, ret=None, gen=_f656, reg_values=True, stack_arg_bytes=8, note='residue-12 batch 43')
S(0x64fc00, 'GUESS copy pair (thiscall)', 'thiscall', None, ret=None, gen=_f1, reg_values=True, note='residue-12 batch 43')
S(0x639b80, 'GUESS hook call ret0 (stdcall)', 'stdcall', None, ret='eax', gen=_f2, reg_values=True, stack_arg_bytes=16,
  note='residue-12 batch 43; assert hook 0x7003b0 is a counting stub')
