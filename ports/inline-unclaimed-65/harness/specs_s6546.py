"""specs_s6546.py - unclaimed-65 batch 46 (docs/20-unclaimed-65.md, claim 26): 0x4daaf0 with the branches drawn per case: the flag a5 (0 or
1), this+0x54 (NULL or an object c with slot 0xe0, logged), c+0x14 (bits 0, 2 and 3 random), the object a1 with slots 0xdc and 0x80 (logged).
The vector helpers 0x441970 and 0x441940 run as the exe code. Its own floats come from random blocks at this+0x30 and this+0x40. The cookie
check is patched to a ret. The answers are deterministic per case (hash of the case seed and the call's arguments)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    _flush_code(c)


def _gen(c):
    seed = c.rng.getrandbits(32)
    self_ = _rnd(c, 0x100)
    c_vt = c.emu.fake_vtable('daaf0-c', 0x200, {
        0xe0: lambda e, r: (e.calllog.append(('0xe0', e.reg('ecx'), tuple(e.arg32(k) for k in range(4)))),
                            e.ret(eax=0, argbytes=0x10))[-1]})
    cobj = _rnd(c, 0x40)
    c.emu.w32(cobj, c_vt)
    c.emu.w32(cobj + 0x14, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x54, cobj if (hash((seed, 1)) & 1) else 0)
    a1_vt = c.emu.fake_vtable('daaf0-a1', 0x200, {
        # the vector buffers are frame addresses: their 12-byte contents are logged, not the addresses
        0xdc: lambda e, r: (e.calllog.append(('0xdc', e.reg('ecx'), (e.arg32(0), e.rbytes(e.arg32(1), 12), e.rbytes(e.arg32(2), 12)))),
                            e.ret(eax=0, argbytes=0xc))[-1],
        0x80: lambda e, r: (e.calllog.append(('0x80', e.reg('ecx'), (e.arg32(0), e.rbytes(e.arg32(1), 12), e.arg32(2)))),
                            e.ret(eax=0, argbytes=0xc))[-1]})
    a1 = _rnd(c, 0x40)
    c.emu.w32(a1, a1_vt)
    a2 = c.rng.getrandbits(32)
    a3 = _rnd(c, 0x40)                       # the matrix pointer of 0x441970 (a stack argument there); also passed to slots 0xdc and 0x80
    a4 = _rnd(c, 0x40)
    a5 = c.rng.choice([0, 1, 0x100, 0x1234])
    return [self_, a1, a2, a3, a4, a5]


S(0x4daaf0, 'ZFFClass 0x4daaf0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 46 (claim 26): flag, object c, bit tests; vector helpers run as exe code')
