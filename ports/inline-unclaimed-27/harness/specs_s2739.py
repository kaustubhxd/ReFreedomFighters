"""specs_s2739.py - unclaimed-27 batch 41: FUN_581200 (GUESS, thiscall, no arguments, returns this). Hooks and stubs, NOT verified:
0x469870 (thiscall, no args) records ecx; the engine E = G+0x9b has a vtable slot +0x114 (thiscall, four stack arguments, ret 0x10)
that records its four arguments and returns a chosen eax. The object is 0x200 random bytes. The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _f1200(c):
    rec = c.emu.alloc(0x40, 4)   # +0 count of slot 0x114 calls; +4..+0x14 its four args; +0x18 count of 0x469870; +0x1c its ecx
    c.emu.hook(0x469870, lambda e, r, rec=rec: (e.w32(rec + 0x18, (e.r32(rec + 0x18) + 1) & 0xffffffff), e.w32(rec + 0x1c, e.reg('ecx')), e.ret(argbytes=0)))
    ret_val = c.rng.getrandbits(32)
    # stub: count++, store [esp+4..esp+16] into rec+4..rec+0x14, eax = ret_val, ret 0x10
    code = (b'\xff\x05' + rec.to_bytes(4, 'little'))
    for i in range(4):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + (rec + 4 + 4 * i).to_bytes(4, 'little')
    code += b'\xb8' + ret_val.to_bytes(4, 'little') + b'\xc2\x10\x00'
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x114, _stub(c, code))
    E = _rnd(c, 0x100)
    c.emu.w32(E, vt)
    G = _rnd(c, 0x400)
    c.emu.w32(G + 0x9b, E)
    c.emu.w32(0x70039c, G)
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x581200, 'FUN_581200 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_f1200, reg_values=True,
  note='unclaimed-27 batch 41; 0x469870 hook; engine slot +0x114 stub (four stack args, ret 0x10)')
