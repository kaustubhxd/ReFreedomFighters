"""specs_s6529.py - unclaimed-65 batch 29 (docs/20-unclaimed-65.md, claim 20), path J: ZItemWeapon::OwnerDraw through one pass of the render
loop. The slot 0x20 of p10 returns non-zero, the flags of self+8 are clear, slot 0x2dc of self returns zero (obj = self), and the
object at self+0xd9 has slot 0x4c (writes L70 = 1) and slot 0x5c (the first call returns the value 'last' and writes L70 = 1, the
second writes L70 = 0). The render object's slot 0x58 returns an object res whose +8 record o has +0x6c != 0 and clear flags, so the
body runs: the real helpers 0x441970, 0x441940 and 0x4de440 run; 0x4daa70 (a claim of its own) is a logging stub for both sides,
logging its object, p10, p14 and its last argument. The cookie check is patched to a ret. The data pointers p18 and p1c point at valid
blocks."""
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

    def daa70(e, r):
        # the two struct arguments are logged by content (the frame addresses themselves are not); L10 is a 3-float vector
        # (0x441970 writes three floats; its fourth dword is uninitialised stack in the exe), so only 12 bytes of it are logged
        e.calllog.append(('0x4daa70', e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(4),
                                                   e.rbytes(e.arg32(2), 0x24), e.rbytes(e.arg32(3), 0xc))))
        e.ret(eax=0, argbytes=0x14)
    ss.patch(c, 0x4daa70, c.emu.stub_fn('4daa70 logger', daa70))
    _flush_code(c)


def _gen(c):
    # p10: slot 0x20 returns non-zero
    p10_vt = c.emu.fake_vtable('owner-p10', 0x40, {
        0x20: lambda e, r: (e.calllog.append(('0x20', e.reg('ecx'), ())), e.ret(eax=1, argbytes=0))})
    p10 = _rnd(c, 0x40)
    c.emu.w32(p10, p10_vt)

    # self+8: the record, flags clear
    rec = _rnd(c, 0x80)
    c.emu.w32(rec + 0x3c, c.rng.getrandbits(32) & ~0x2c00 & 0xffffffff)

    # the loop object at self+0xd9: slot 0x4c and the two slot 0x5c calls (see the docstring)
    last = c.rng.getrandbits(32)
    state = {'n': 0}

    def s4c(e, r):
        e.calllog.append(('0x4c', e.reg('ecx'), ()))
        e.w32(e.arg32(0), 1)
        e.ret(eax=0, argbytes=4)

    def s5c(e, r):
        e.calllog.append(('0x5c', e.reg('ecx'), ()))
        e.w32(e.arg32(0), 1 if state['n'] == 0 else 0)
        v = last if state['n'] == 0 else 0
        state['n'] += 1
        e.ret(eax=v, argbytes=4)

    d9_vt = c.emu.fake_vtable('owner-d9', 0x100, {0x4c: s4c, 0x5c: s5c})
    d9 = _rnd(c, 0x40)
    c.emu.w32(d9, d9_vt)

    # render object: slot 0x58 (one argument: last) returns res; res+8 is o, the record the body reads
    o = _rnd(c, 0x80)
    c.emu.w32(o + 0x6c, 1)
    c.emu.w32(o + 0x3c, c.rng.getrandbits(32) & ~0x2c00 & 0xffffffff)
    res = _rnd(c, 0x40)
    c.emu.w32(res + 8, o)
    r_vt = c.emu.fake_vtable('owner-render', 0x100, {
        0x58: lambda e, r: (e.calllog.append(('0x58', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=res, argbytes=4))})
    render = _rnd(c, 0x40)
    c.emu.w32(render, r_vt)
    gobj = _rnd(c, 0x2000)
    c.emu.w32(gobj + 0x9b, render)
    c.emu.w32(0x70039c, gobj)

    # self: slot 0x2dc returns zero (obj = self); +8 is the record, +0xd9 the loop object
    self_vt = c.emu.fake_vtable('owner-self', 0x300, {
        0x2dc: lambda e, r: (e.calllog.append(('0x2dc', e.reg('ecx'), ())), e.ret(eax=0, argbytes=0))})
    self_ = _rnd(c, 0x200)
    c.emu.w32(self_, self_vt)
    c.emu.w32(self_ + 8, rec)
    c.emu.w32(self_ + 0xd9, d9)

    v = [c.rng.getrandbits(32) for _ in range(7)]
    # p18 and p1c are data pointers (0x4de480 and 0x43e920 read through them)
    v[4] = _rnd(c, 0x40)
    v[5] = _rnd(c, 0x40)
    # the seven stack arguments: p8, pc, p10, p14, p18, p1c, p20
    return [self_, v[0], v[1], p10, v[3], v[4], v[5], v[6]]


S(0x46fda0, 'ZItemWeapon::OwnerDraw (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 29 (claim 20); path J: one pass of the render loop, 0x4daa70 stubbed')
