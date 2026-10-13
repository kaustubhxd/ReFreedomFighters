"""specs_s2736.py - unclaimed-27 batch 38: FUN_59dd10 and FUN_58bbc0 (GUESS). ABI: ecx = this, edx = esi value, two stack args (ret 8).
Hooks (NOT verified): 0x45c4f0 (cdecl, two args) and 0x45c4b0 (cdecl, one arg) return a chosen r (0 or a pointer); 0x59d580 (for
59dd10) and 0x58ab50 (for 58bbc0) are thiscall with three stack args (ret 0xc) and return a chosen eax. Each records its arguments.
The SEH frames are not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c, callee_chain, callee_eax_addr):
    rec = c.emu.alloc(0x60, 4)   # +0x20/+0x24 0x45c4f0 args, +0x28 0x45c4b0 arg; +0 0x45c4f0 calls, +4 0x45c4b0 calls, +8 chain calls, +0xc chain ecx, +0x10 a1, +0x14 t, +0x18 e
    R = _rnd(c, 0x100)
    r = R if c.rng.random() < 0.7 else 0
    eax_val = c.rng.getrandbits(32)

    def h4f(e, r_, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 0x20, e.arg32(0))
        e.w32(rec + 0x24, e.arg32(1))
        e.ret(eax=r, argbytes=0)   # cdecl: the caller cleans

    def h4b(e, r_, rec=rec):
        e.w32(rec + 4, (e.r32(rec + 4) + 1) & 0xffffffff)
        e.w32(rec + 0x28, e.arg32(0))
        e.ret(eax=r, argbytes=0)   # cdecl: the caller cleans

    def hch(e, r_, rec=rec):
        e.w32(rec + 8, (e.r32(rec + 8) + 1) & 0xffffffff)
        e.w32(rec + 0xc, e.reg('ecx'))
        e.w32(rec + 0x10, e.arg32(0))
        e.w32(rec + 0x14, e.arg32(1))
        e.w32(rec + 0x18, e.arg32(2))
        e.ret(eax=eax_val, argbytes=12)

    c.emu.hook(0x45c4f0, h4f)
    c.emu.hook(0x45c4b0, h4b)
    c.emu.hook(callee_chain, hch)


def _gen_for(callee_chain):
    def f(c):
        _hooks(c, callee_chain, None)
        o = _rnd(c, 0x100)
        a1 = c.rng.getrandbits(32)
        a2 = c.rng.choice([0, 1, c.rng.getrandbits(32)])
        esiv = c.rng.getrandbits(32)
        c.emu.mu.ctl_flush_tb()
        return [o, esiv, a1, a2]
    return f


S(0x59dd10, 'FUN_59dd10 (GUESS) fastcall', ('regs', ['ecx', 'edx', 's', 's']), None, ret='eax', gen=_gen_for(0x59d580), stack_arg_bytes=8, reg_values=True,
  note='batch 38; 0x45c4f0 0x45c4b0 0x59d580 hooks; SEH frame not reproduced')
S(0x58bbc0, 'FUN_58bbc0 (GUESS) fastcall', ('regs', ['ecx', 'edx', 's', 's']), None, ret='eax', gen=_gen_for(0x58ab50), stack_arg_bytes=8, reg_values=True,
  note='batch 38; 0x45c4f0 0x45c4b0 0x58ab50 hooks; SEH frame not reproduced')
