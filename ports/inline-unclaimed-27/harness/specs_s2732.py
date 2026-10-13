"""specs_s2732.py - unclaimed-27 batch 34: FUN_59ad40 (GUESS, thiscall, one argument, ret 4, returns this). Callee 0x59ac70 is a HOOK
(stub, NOT verified): it counts calls. The assert hook at 0x7003b0 is always set to a stub that counts its calls (non-null, per the
checker rule). 0x4690b0 is hooked to record its two arguments (its exe body is a plain ret; the hook makes the line argument visible). The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f9ad(c):
    rec = c.emu.alloc(0x10, 4)   # +0 0x59ac70 calls, +4 the assert hook calls
    h = lambda e, r, rec=rec: (e.w32(rec, (e.r32(rec) + 1) & 0xffffffff), e.ret(argbytes=0))
    c.emu.hook(0x59ac70, h)
    rec4 = c.emu.alloc(0x10, 4)   # 0x4690b0 records its two cdecl arguments (the exe's own body is a plain ret)

    def h4690(e, r, rec4=rec4):
        e.w32(rec4, e.arg32(0))
        e.w32(rec4 + 4, e.arg32(1))
        e.ret(argbytes=0)

    c.emu.hook(0x4690b0, h4690)
    code = b'\xff\x05' + (rec + 4).to_bytes(4, 'little') + b'\xc3'    # inc dword [rec+4]; ret (cdecl, no args)
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    c.emu.w32(0x7003b0, st)
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(3)]


S(0x59ad40, 'FUN_59ad40 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f9ad, reg_values=True,
  note='unclaimed-27 batch 34; 0x59ac70 is a hook; assert hook 0x7003b0 is a counting stub; SEH frame not reproduced')
