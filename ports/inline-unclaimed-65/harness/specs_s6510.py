"""specs_s6510.py - unclaimed-65 batch 10 (docs/20-unclaimed-65.md, claim 11): ZActor::ClassCommand. The command word is matched
against the words at 0x6ffa40, 0x6ffa1c, 0x6ffa20 (set per case) and the actor's words at +0x5be and +0x5c0. Fakes: the actor
(slots +0x58c, +0x590, +0x594, +0x5e4, +0x2fc logging; +0x2fc returns a per-case byte), the argument object (slot +0x350 returns X),
X (slot +0x340 returns R), R (slot +0x32c returns a per-case result). 0x472ae0 is a logging stub (thiscall, two args, popped by the
callee). Translation cache flushed after the patch."""
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
    from serial_stubs import patch

    def ext2(e, r):
        e.calllog.append(('0x472ae0', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    patch(c, 0x472ae0, c.emu.stub_fn('0x472ae0', ext2))
    _flush_code(c)
    # the globals: three words that the command can match
    g40 = c.rng.getrandbits(16)
    g1c = c.rng.getrandbits(16)
    g20 = c.rng.getrandbits(16)
    c.emu.w16(0x6ffa40, g40)
    c.emu.w16(0x6ffa1c, g1c)
    c.emu.w16(0x6ffa20, g20)
    return g40, g1c, g20


def _gen(c):
    g40, g1c, g20 = [c.emu.r32(0x6ffa40) & 0xffff, c.emu.r32(0x6ffa1c) & 0xffff, c.emu.r32(0x6ffa20) & 0xffff]
    # the actor: its words at +0x5be and +0x5c0
    w5be = c.rng.getrandbits(16)
    w5c0 = c.rng.getrandbits(16)
    byte2fc = c.rng.choice([0, 1, 2, 0x80])
    rv = c.rng.choice([0, 1, 3, 4, 5, 6, 7, 8, 9])
    # the three result objects
    R_vt = c.emu.logging_vtable('cc-r', 0x340, impl={0x32c: lambda e, a: (rv, None)}, argwords={0x32c: 0})
    R = _rnd(c, 0x40)
    c.emu.w32(R, R_vt)
    X_vt = c.emu.logging_vtable('cc-x', 0x348, impl={0x340: lambda e, a: (R, None)}, argwords={0x340: 1})
    X = _rnd(c, 0x40)
    c.emu.w32(X, X_vt)
    A_vt = c.emu.logging_vtable('cc-arg', 0x358, impl={0x350: lambda e, a: (X, None)}, argwords={0x350: 0})
    # the argument is a struct whose first dword is the object (ecx = [arg] in the original); byte +4 is the flag
    A_obj = _rnd(c, 0x40)
    c.emu.w32(A_obj, A_vt)
    arg = _rnd(c, 0x40)
    c.emu.w32(arg, A_obj)
    # the actor
    self_vt = c.emu.logging_vtable('cc-actor', 0x600, impl={0x2fc: lambda e, a: (byte2fc, None)},
                                   argwords={0x58c: 0, 0x590: 0, 0x594: 0, 0x5e4: 1, 0x2fc: 0})
    self_ = _rnd(c, 0x800)
    c.emu.w32(self_, self_vt)
    c.emu.w16(self_ + 0x5be, w5be)
    c.emu.w16(self_ + 0x5c0, w5c0)
    pick = c.rng.random()
    if pick < 0.14:
        cmd = g40
    elif pick < 0.28:
        cmd = w5be
    elif pick < 0.42:
        cmd = w5c0
    elif pick < 0.56:
        cmd = g1c
    elif pick < 0.7:
        cmd = g20
    else:
        cmd = c.rng.getrandbits(16)
    return [self_, cmd | (c.rng.getrandbits(16) << 16 if c.rng.random() < 0.3 else 0), arg]


S(0x477950, 'ZActor::ClassCommand (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 10 (residue 17); word-matched command dispatch; tail via slot 0x2fc then 0x472ae0')
