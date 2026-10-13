"""specs_s6527.py - unclaimed-65 batch 27 (docs/20-unclaimed-65.md, claim 20), path H: ZItemWeapon::OwnerDraw with the slot 0x20 of p10
returning non-zero and the flags of self+8 carrying 0x2c00 (the exit at 46ff04, nothing else runs). The tail call 0x46f9d0 (248 lines, another claim) is stubbed as a
logging callee for both sides: it logs its this and its seven arguments and pops 0x1c. The cookie check 0x633654 is patched to a ret.
Translation cache flushed after the patches."""
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

    def tail(e, r):
        e.calllog.append(('0x46f9d0', e.reg('ecx'), tuple(e.arg32(i) for i in range(7))))
        e.ret(eax=0, argbytes=0x1c)
    ss.patch(c, 0x46f9d0, c.emu.stub_fn('46f9d0 logger', tail))
    _flush_code(c)


def _gen(c):
    # p10: slot 0x20 returns zero (group 1)
    p10_vt = c.emu.fake_vtable('owner-p10', 0x40, {
        0x20: lambda e, r: (e.calllog.append(('0x20', e.reg('ecx'), ())), e.ret(eax=1, argbytes=0))})
    p10 = _rnd(c, 0x40)
    c.emu.w32(p10, p10_vt)

    # self: the object with +8 (a record whose +0x3c flags have no 0x2c00 bits, so the early exit is not taken) and +0xd9
    rec = _rnd(c, 0x80)
    c.emu.w32(rec + 0x3c, (c.rng.getrandbits(32) | 0x2c00) & 0xffffffff)
    self_vt = c.emu.fake_vtable('owner-self', 0x300, {})
    self_ = _rnd(c, 0x200)
    c.emu.w32(self_, self_vt)
    c.emu.w32(self_ + 8, rec)
    c.emu.w32(self_ + 0xd9, 0)
    v = [c.rng.getrandbits(32) for _ in range(7)]
    # the seven stack arguments: p8, pc, p10 (the object above), p14, p18, p1c, p20
    return [self_, v[0], v[1], p10, v[3], v[4], v[5], v[6]]


S(0x46fda0, 'ZItemWeapon::OwnerDraw (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 27 (claim 20); path H: slot 0x20 non-zero, self+8 flags 0x2c00 set: early exit')
