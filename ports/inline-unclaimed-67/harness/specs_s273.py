"""specs_s273.py - unclaimed area 67, gap band: six tail-call forwarders through the object at this+0x15 (logged slots, no args)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(k):
    def gen(c):
        vt = c.emu.logging_vtable('Fwd%x' % k, 0x140, impl={k: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={k: 0})
        o = _rnd(c, 0x40)
        c.emu.w32(o, vt)
        self_ = _rnd(c, 0x100)
        c.emu.w32(self_ + 0x15, o)
        c.emu.mu.ctl_flush_tb()
        return [self_]
    return gen


S(0x5f2e00, 'FUN_5f2e00 (fwdSlot68)', 'thiscall', None, ret='eax', gen=_fwd(0x68), note='batch273; tail call slot 0x68 of [this+0x15]')
S(0x5f2e50, 'FUN_5f2e50 (fwdSlot60)', 'thiscall', None, ret='eax', gen=_fwd(0x60), note='batch273; tail call slot 0x60')
S(0x5f2f00, 'FUN_5f2f00 (fwdSlot48)', 'thiscall', None, ret='eax', gen=_fwd(0x48), note='batch273; tail call slot 0x48')
S(0x5f3000, 'FUN_5f3000 (fwdSlot18)', 'thiscall', None, ret='eax', gen=_fwd(0x18), note='batch273; tail call slot 0x18')
S(0x5f31b0, 'FUN_5f31b0 (fwdSlot5c)', 'thiscall', None, ret='eax', gen=_fwd(0x5c), note='batch273; tail call slot 0x5c')
S(0x5f3360, 'FUN_5f3360 (fwdSlot10)', 'thiscall', None, ret='eax', gen=_fwd(0x10), note='batch273; tail call slot 0x10')
