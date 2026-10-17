"""specs_s6547.py - unclaimed-65 batch 47 (docs/20-unclaimed-65.md, claim 27): 0x45d3a0 with the branches drawn per case (the answers are
hash-based on the case seed and the call's arguments, so the orig and port runs agree). Slot 0x4c of the render sub-object is called with
four arguments (the second is the constant 0x685230) and with one; the callee pops accordingly (told apart by that second argument). The
delete helper 0x634273 (cdecl) and 0x45c560 (thiscall, one argument) are logging stubs for both sides (other claims). The cookie check
runs as the exe code."""
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
    ss.patch(c, 0x634273, c.emu.stub_fn('634273 logger', lambda e, r: (e.calllog.append(('0x634273', (e.arg32(0), e.arg32(1)))),
                                                                       e.ret(eax=0, argbytes=0))))
    ss.patch(c, 0x45c560, c.emu.stub_fn('45c560 logger', lambda e, r: (e.calllog.append(('0x45c560', e.reg('ecx'), (e.arg32(0),))),
                                                                       e.ret(eax=0, argbytes=4))))
    _flush_code(c)


def _gen(c):
    seed = c.rng.getrandbits(32)

    def pick(*keys):
        return hash((seed,) + keys) & 0xffffffff

    # this, S, Y, Q: this+0x10 is S (NULL on 1 case in 10), S+0x1c is Y, Y+4 is Q, Q+8 and Q+0xc hold values
    self_ = _rnd(c, 0x100)
    S_ = _rnd(c, 0x40)
    Y = _rnd(c, 0x40)
    Q = _rnd(c, 0x40)
    c.emu.w32(Q + 8, c.rng.getrandbits(32))
    c.emu.w32(Q + 0xc, c.rng.getrandbits(32))
    c.emu.w32(Y + 4, Q)
    c.emu.w32(S_ + 0x1c, Y)
    c.emu.w32(self_ + 0x10, S_ if pick(1) % 10 else 0)

    # this vtable: slot 0x1d8 writes an empty list head into its out buffer and returns P
    P = _rnd(c, 0x40)
    c.emu.w32(P, c.rng.getrandbits(32))

    def s1d8(e, r):
        out = e.arg32(0)
        e.w32(out, (out + 4) & 0xffffffff)
        e.calllog.append(('0x1d8', (e.arg32(1),)))
        e.ret(eax=P, argbytes=8)
    this_vt = c.emu.fake_vtable('d3a0-this', 0x300, {0x1d8: s1d8})
    c.emu.w32(self_, this_vt)

    # the global objects
    K_vt = c.emu.fake_vtable('d3a0-K', 0x100, {
        0x2c: lambda e, r: (e.calllog.append(('0x2c', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2)))), e.ret(eax=0, argbytes=0))[-1]})
    K = _rnd(c, 0x40)
    c.emu.w32(K, K_vt)
    G390_vt = c.emu.fake_vtable('d3a0-g390', 0x100, {
        0x20: lambda e, r: (e.calllog.append(('0x20', (e.arg32(0), e.arg32(1)))), e.ret(eax=K, argbytes=8))[-1]})
    G390 = _rnd(c, 0x40)
    c.emu.w32(G390, G390_vt)
    X = c.rng.getrandbits(32)
    G38c_vt = c.emu.fake_vtable('d3a0-g38c', 0x100, {
        0x48: lambda e, r: (e.calllog.append(('0x48', (e.arg32(0),))), e.ret(eax=X, argbytes=4))[-1]})
    G38c = _rnd(c, 0x40)
    c.emu.w32(G38c, G38c_vt)
    G_vt = c.emu.fake_vtable('d3a0-g', 0x100, {
        0x40: lambda e, r: (e.calllog.append(('0x40', (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1]})
    G = _rnd(c, 0x40)
    c.emu.w32(G, G_vt)

    # H: slot 0x3c (three args) returns R3 (zero on about half the cases), 0x44, 0x58 and 0x84 (one argument each, logged)
    H_vt = c.emu.fake_vtable('d3a0-h', 0x300, {
        0x3c: lambda e, r: (e.calllog.append(('0x3c', (e.arg32(0), e.arg32(1), e.arg32(2)))),
                            e.ret(eax=(0 if pick(3, e.arg32(0)) & 1 else pick(4, e.arg32(0)) | 1), argbytes=12))[-1],
        0x44: lambda e, r: (e.calllog.append(('0x44', (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1],
        0x58: lambda e, r: (e.calllog.append(('0x58', (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1],
        0x84: lambda e, r: (e.calllog.append(('0x84', (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1]})
    H = _rnd(c, 0x40)
    c.emu.w32(H, H_vt)

    # the render object and its +0x9b sub-object r9: slot 0x4c has two arities (see the docstring); the one-argument form returns a value
    # The exe calls this slot with four arguments (the 45d441 site) and with one (45d56a); the callee's own ret count is unknown here.
    # The fake pops 0x10 at both sites (the one-argument site then leaves the stack 12 bytes low, as the exe would if the ret is 0x10).
    def s4c(e, r):
        e.calllog.append(('0x4c', (e.arg32(0),)))
        e.ret(eax=pick(5, e.arg32(0)), argbytes=0x10)
    r9_vt = c.emu.fake_vtable('d3a0-r9', 0x100, {0x4c: s4c})
    r9 = _rnd(c, 0x40)
    c.emu.w32(r9, r9_vt)
    render_vt = c.emu.fake_vtable('d3a0-render', 0x100, {})
    render = _rnd(c, 0x2000)
    c.emu.w32(render, render_vt)
    c.emu.w32(render + 0x9b, r9)
    c.emu.wbytes(render + 0x1b3b, bytes([c.rng.choice([0, 1])]))

    c.emu.w32(0x70038c, G38c)
    c.emu.w32(0x700390, G390)
    c.emu.w32(0x7003a8, G)
    c.emu.w32(0x7003a4, H if pick(7) % 10 else 0)
    c.emu.w32(0x70039c, render)
    return [self_]


S(0x45d3a0, 'ZMoveOnSpline-like 0x45d3a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 47 (claim 27): all branches by per-case answers; 0x634273 and 0x45c560 stubbed')
