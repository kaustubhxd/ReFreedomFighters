"""specs_s2733.py - unclaimed-27 batch 35: FUN_598cf0 (GUESS, thiscall, one argument, ret 4, returns this). Hooks (NOT verified):
0x598a50 (thiscall, counts calls); 0x4690b0 (cdecl, records its two arguments: the exe body is a plain ret); the assert hook at
0x7003b0 is always a counting stub (non-null, per the checker rule). The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f8cf(c):
    rec = c.emu.alloc(0x20, 4)   # +0 0x598a50 calls, +4 assert hook calls, +8/+0xc 0x4690b0 args
    c.emu.hook(0x598a50, lambda e, r, rec=rec: (e.w32(rec, (e.r32(rec) + 1) & 0xffffffff), e.ret(argbytes=0)))

    def h4690(e, r, rec=rec):
        e.w32(rec + 8, e.arg32(0))
        e.w32(rec + 0xc, e.arg32(1))
        e.ret(argbytes=0)

    c.emu.hook(0x4690b0, h4690)
    code = b'\xff\x05' + (rec + 4).to_bytes(4, 'little') + b'\xc3'    # inc dword [rec+4]; ret (cdecl, no args)
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(0x7003b0, st)
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(3)]


S(0x598cf0, 'FUN_598cf0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f8cf, reg_values=True,
  note='unclaimed-27 batch 35; 0x598a50 and 0x4690b0 are hooks; assert hook 0x7003b0 is a counting stub; SEH not reproduced')
