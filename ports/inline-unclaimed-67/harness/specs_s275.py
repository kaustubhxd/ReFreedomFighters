"""specs_s275.py - unclaimed area 67, gap band: five leaves (store, two forwarders on this+0xaca, ctor-like global store, sum)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    o = _rnd(c, 0x1000)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _fwd(k):
    def gen(c):
        vt = c.emu.logging_vtable('Aca%x' % k, 0x140, impl={k: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={k: 0})
        self_ = _rnd(c, 0x1000)
        c.emu.w32(self_ + 0xaca, vt)
        c.emu.mu.ctl_flush_tb()
        return [self_]
    return gen


def _arg(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x5fb910, 'FUN_5fb910 (setAt30)', 'thiscall', None, ret=None, gen=_arg, note='batch275; [this+0x30] = arg')
S(0x5f5150, 'FUN_5f5150 (fwdAca0)', 'thiscall', None, ret='eax', gen=_fwd(0), note='batch275; slot 0 of this+0xaca')
S(0x5f3fb0, 'FUN_5f3fb0 (fwdAca4)', 'thiscall', None, ret='eax', gen=_fwd(4), note='batch275; slot 4 of this+0xaca')
S(0x5fa5d0, 'FUN_5fa5d0 (ctorGlobal724270)', 'thiscall', None, ret='eax', gen=_obj, note='batch275; vtable word, global 0x724270 = this')
S(0x5f3150, 'FUN_5f3150 (sumInto8)', 'thiscall', None, ret=None, gen=_arg, note='batch275; [this+8] = [this+4] + arg')
