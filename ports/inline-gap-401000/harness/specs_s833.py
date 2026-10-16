"""specs_s833.py - residue-01 batch 833 (docs/20-unclaimed-65.md). 0x51c210: thiscall with one stack argument (the block, ret 4). The block
(0x1000) carries a seed at +0; +0x44d and +0x451 are the flags that 0x4e12e0 writes. The global at 0x700390 is an object O whose slot 0x20 (two
arguments, callee pops) returns P; P's slot 0x2c is called with ecx = [P] and three arguments the caller removes (logged). All callees HOOKED by
address (GUESS): 0x512850 (one argument, pops 4), 0x4e12e0 (two arguments, pops 8; writes a flag through its first argument, derived from the
seed and the call count), 0x4e1600 (no arguments; returns al in {8, 3, 0x108} by the seed), 0x4e1b30 (no arguments)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _h(seed, *keys):
    return hash((seed,) + keys) & 0xffffffff


def _count(e, name):
    return sum(1 for x in e.calllog if x[0] == name)


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x512850, c.emu.stub_fn('512850 hook', lambda e, r: (e.calllog.append(('0x512850', e.reg('ecx'), e.arg32(0))), e.ret(eax=0, argbytes=4))))

    def f12e0(e, r):
        seed = e.r32(e.reg('ecx'))
        k = _count(e, '0x4e12e0')
        v = _h(seed, 0x4e12e0, k)
        e.calllog.append(('0x4e12e0', e.reg('ecx'), e.arg32(1)))
        e.w32(e.arg32(0), 0 if (v & 1) == 0 else 1)
        e.ret(eax=0, argbytes=8)
    ss.patch(c, 0x4e12e0, c.emu.stub_fn('4e12e0 hook', f12e0))

    def f1600(e, r):
        seed = e.r32(e.reg('ecx'))
        v = _h(seed, 0x4e1600, _count(e, '0x4e1600'))
        al = (8, 3, 0x108)[v % 3]
        e.calllog.append(('0x4e1600', e.reg('ecx'), al))
        e.ret(eax=al, argbytes=0)
    ss.patch(c, 0x4e1600, c.emu.stub_fn('4e1600 hook', f1600))
    ss.patch(c, 0x4e1b30, c.emu.stub_fn('4e1b30 hook', lambda e, r: (e.calllog.append(('0x4e1b30', e.reg('ecx'))), e.ret(eax=0, argbytes=0))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    p_vt = c.emu.fake_vtable('c833-p', 0x100, {
        0x2c: lambda e, r: (e.calllog.append(('0x2c', e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2))), e.ret(eax=0, argbytes=0))[-1]})
    p = _rnd(c, 0x40)
    c.emu.w32(p, p_vt)
    o_vt = c.emu.fake_vtable('c833-o', 0x100, {
        0x20: lambda e, r: (e.calllog.append(('0x20', e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=p, argbytes=8))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    c.emu.w32(0x700390, o)
    this = _rnd(c, 0x1000)
    c.emu.w32(this, c.rng.getrandbits(32))
    c.emu.w32(this + 4, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.wbytes(this + 0x44d, bytes(4))
    c.emu.wbytes(this + 0x451, bytes(4))
    return [this, c.rng.getrandbits(32)]


S(0x51c210, 'ZHeli::CopyDataBlock (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='residue-01 batch 833: integer copy path with hooked helpers and the 0x700390 object')
