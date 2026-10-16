"""specs_s6513.py - unclaimed-65 batch 13 (docs/20-unclaimed-65.md, claim 13), branch groups 2 to 4: ZRepositionCharacter::Reposition
with the render object's slot +0x58 returning a non-zero object S. Random per case: the B slot +0x1e0 result (al), B's +0x85a (set or
not), the zobj slot +0x25c result W (zero or not), and the tail values. Stubs (by address, with a translation-cache flush):
0x4de7a0 (writes +8 = 1.0; ecx is a stack address, not logged), 0x5d1440 (logs ecx), 0x589c20 (thiscall, one arg, returns a
value), 0x59a580 (thiscall, three args), 0x633654 (cookie, ret). Pointer arguments that point into the stack are never logged."""
import os, sys, struct
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


def _logger(e, name, nargs, argbytes=None, ecx_log=True, ret=0):
    args = tuple(e.arg32(k) for k in range(nargs))
    e.calllog.append((name, e.reg('ecx') if ecx_log else None, args))
    e.ret(eax=ret, argbytes=4 * nargs if argbytes is None else argbytes)


def _setup(c):
    import serial_stubs as ss
    def stub(name, n):
        def h(e, r):
            _logger(e, name, n)
        return c.emu.stub_fn(name, h)
    def cookie(e, r):
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x633654, c.emu.stub_fn('cookie', cookie))
    def r4de(e, r):
        e.w32(e.reg('ecx') + 8, 0x3f800000)
        e.ret(eax=0, argbytes=0)
    ss.patch(c, 0x4de7a0, c.emu.stub_fn('4de7a0', r4de))
    ss.patch(c, 0x5d1440, stub('0x5d1440', 0))
    def r589(e, r):
        e.calllog.append(('0x589c20', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=_ret589, argbytes=4)
    ss.patch(c, 0x589c20, c.emu.stub_fn('0x589c20', r589))
    ss.patch(c, 0x59a580, stub('0x59a580', 3))
    _flush_code(c)


_ret589 = 0


def _gen(c):
    global _ret589
    _ret589 = c.rng.getrandbits(32)
    # S (the render slot +0x58 result): slot +0x80 writes 0.5 and a value through its pointers (no logging of stack pointers)
    def s80(e, r):
        p34 = e.arg32(0)
        p10 = e.arg32(1)
        e.w32(p34, 0x3f000000)
        e.w32(p34 + 4, 0x3f800000)
        e.w32(p10, c.rng.getrandbits(32))
        e.calllog.append(('S-80', e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=8)
    s_vt = c.emu.fake_vtable('reposition-S', 0x90, {0x80: s80})
    S_obj = _rnd(c, 0x40)
    c.emu.w32(S_obj, s_vt)
    c.emu.w32(S_obj + 4, c.rng.choice([0, c.rng.getrandbits(32)]))

    # B (this+0x50): slot +0x1e0 returns al (random), slot +0x100 returns K, slot +0x370 takes two pointers (not logged)
    al = c.rng.choice([0, 1, 0x100, 0x1ff])
    K = _rnd(c, 0x40)
    K_vt = c.emu.logging_vtable('reposition-K', 0x20)
    c.emu.w32(K, K_vt)
    def b370(e, r):
        e.calllog.append(('B-370', e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=8)
    def b1e0(e, r):
        e.calllog.append(('B-1e0', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=al, argbytes=4)

    def b100(e, r):
        e.calllog.append(('B-100', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=K, argbytes=4)
    b_vt = c.emu.fake_vtable('reposition-B', 0x380, {0x370: b370, 0x1e0: b1e0, 0x100: b100})
    B = _rnd(c, 0x900)
    c.emu.w32(B, b_vt)
    c.emu.w32(B + 0x85a, c.rng.choice([0, K]))

    # R (render): slot +0x58 returns S (logs its argument); slot +0x114 returns a word (four args); R+0xadc is zobj
    def w128(e, r):
        # three arguments: the word and the two zeros left on the stack by the 0x114 call (ret 0xc)
        e.calllog.append(('W-128', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    W_vt = c.emu.fake_vtable('reposition-W', 0x140, {0x128: w128})
    W = _rnd(c, 0x40)
    c.emu.w32(W, W_vt)
    wret = c.rng.choice([0, W])
    z_vt = c.emu.logging_vtable('reposition-Z', 0x270, impl={0x25c: lambda e, r: (wret, None)}, argwords={0x25c: 2})
    Z = _rnd(c, 0x40)
    c.emu.w32(Z, z_vt)
    word = c.rng.getrandbits(32)
    R_vt = c.emu.logging_vtable('reposition-R', 0x600, impl={0x58: lambda e, r: (S_obj, None), 0x114: lambda e, r: (word, None)},
                                argwords={0x58: 1, 0x114: 4})
    R = _rnd(c, 0x1000)
    c.emu.w32(R, R_vt)
    c.emu.w32(R + 0xadc, Z)
    rr = _rnd(c, 0x2000)
    c.emu.w32(rr + 0x9b, R)
    # the global X at rr+0x190f: slot +0x20 returns Y; Y's slot +0x64 (no args) logs
    Y = _rnd(c, 0x40)
    c.emu.w32(Y, c.emu.logging_vtable('reposition-Y', 0x70, argwords={0x64: 0}))
    X = _rnd(c, 0x40)
    c.emu.w32(X, c.emu.logging_vtable('reposition-X', 0x30, impl={0x20: lambda e, r: (Y, None)}, argwords={0x20: 0}))
    c.emu.w32(rr + 0x190f, X)
    c.emu.w32(0x70039c, rr)

    # the global 0x7003b8 object (the receiver of 0x589c20)
    G2 = _rnd(c, 0x40)
    c.emu.w32(G2, c.emu.logging_vtable('reposition-G2', 0x20))
    c.emu.w32(0x7003b8, G2)

    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x48, 0)  # replaced below by an actor
    vv = c.rng.getrandbits(32)
    qv = c.rng.getrandbits(32)

    def a14(e, r):
        e.ret(eax=vv, argbytes=0)

    def a30(e, r):
        e.calllog.append(('a-30', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=qv, argbytes=4)
    a_vt = c.emu.fake_vtable('reposition-a2', 0x40, {0x14: a14, 0x30: a30})
    a = _rnd(c, 0x40)
    c.emu.w32(a, a_vt)
    c.emu.w32(self_ + 0x48, a)
    c.emu.w32(self_ + 0x4c, c.rng.choice([vv, c.rng.getrandbits(32)]))
    c.emu.w32(self_ + 0x50, B)
    _flush_code(c)
    return [self_]


S(0x5c4290, 'ZRepositionCharacter::Reposition (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 13 (residue 17); branch groups 2 to 4 (render slot 0x58 non-zero)')
