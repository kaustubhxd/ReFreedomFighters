"""specs_s6512.py - unclaimed-65 batch 12 (docs/20-unclaimed-65.md, claim 13), branch group 1: ZRepositionCharacter::Reposition
with the render object's slot +0x58 returning zero (s == 0). The chain: the actor's slot +0x14 and +0x30 (fakes), the render
object (global 0x70039c, +0x9b), the global 0x700390 slot +0x20 (returns x) and x's slot +0x2c (caller cleans two args). The cookie
check 0x633654 is patched to a ret (no effect). Translation cache flushed after the patch."""
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
    # the cookie check is a ret with no effect (fastcall-like, no stack arguments)
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', lambda e, r: e.ret(eax=0, argbytes=0)))
    _flush_code(c)


def _gen(c):
    # actor a: slot +0x14 returns v; slot +0x30 returns q (logs); render slot +0x58 returns 0 (group 1)
    def slot14(e, r):
        e.ret(eax=vv, argbytes=0)
    vv = c.rng.getrandbits(32)
    a_vt = c.emu.fake_vtable('reposition-a', 0x40, {0x14: slot14,
                                                    0x30: lambda e, r: (e.calllog.append(('a-30', e.reg('ecx'), (e.arg32(0),))),
                                                                       e.ret(eax=qv, argbytes=4))})
    qv = c.rng.getrandbits(32)
    a = _rnd(c, 0x40)
    c.emu.w32(a, a_vt)
    # render object: slot +0x58 returns zero (logs its argument)
    r_vt = c.emu.logging_vtable('reposition-render', 0x60, impl={0x58: lambda e, x: (0, None)}, argwords={0x58: 1})
    R = _rnd(c, 0x40)
    c.emu.w32(R, r_vt)
    rr = _rnd(c, 0x2000)
    c.emu.w32(rr + 0x9b, R)
    c.emu.w32(0x70039c, rr)
    # global 0x700390: slot +0x20 (two args) returns x; x's slot +0x2c (caller cleans two args) logs
    def x2c(e, r):
        e.calllog.append(('x-2c', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    x_vt = c.emu.fake_vtable('reposition-x', 0x40, {0x2c: x2c})
    x = _rnd(c, 0x40)
    c.emu.w32(x, x_vt)
    g_vt = c.emu.logging_vtable('reposition-g', 0x30, impl={0x20: lambda e, x_: (x, None)}, argwords={0x20: 2})
    g = _rnd(c, 0x40)
    c.emu.w32(g, g_vt)
    c.emu.w32(0x700390, g)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x48, a)
    c.emu.w32(self_ + 0x4c, c.rng.choice([qv, c.rng.getrandbits(32)]))
    return [self_]


S(0x5c4290, 'ZRepositionCharacter::Reposition (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 12 (residue 17); branch group 1: render slot 0x58 returns zero')
