"""specs_s7909.py - unclaimed-79 batch 9 (docs/20-unclaimed-79.md): CRagdoll2::ComputeParticlePositions (0x6411b0). Orchestration
verified, helpers stubbed: every callee is a call-recording stub (the physics is inside them). Stack-slot pointers (the memcpy
source buffer and the cookie) are logged as 'stack-slot'; the rest is logged as values."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H = {'644660': 0x644660, '641340': 0x641340, '544e10': 0x544e10, '545950': 0x545950, '641e20': 0x641e20,
     '634d22': 0x634d22, '547a70': 0x547a70, '4de480': 0x4de480, '4419f0': 0x4419f0, '441940': 0x441940}


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p


def _rec(name, nargs, fastcall=False):
    def h(e, r):
        if fastcall:
            e.calllog.append((name, e.reg('ecx'), e.reg('edx')))
            e.ret(eax=0, argbytes=0)
        else:
            args = tuple(_norm(e, e.arg32(k)) for k in range(nargs))
            e.calllog.append((name, e.reg('ecx')) + args)
            e.ret(eax=0, argbytes=(4 * nargs if name.startswith('CRagdoll2::') else 4 * nargs))
    return h


def _cdecl_memcpy(e, r):
    args = tuple(_norm(e, e.arg32(k)) for k in range(3))
    e.calllog.append(('memcpy',) + args)
    e.ret(eax=0, argbytes=0)


def _compute(c):
    cnt = c.rng.choice([1, 2, 3, 4])
    self_ = _rnd(c, 0x200)
    c.emu.w32(self_ + 0x26, cnt)
    c.emu.w32(self_ + 0x2e, _rnd(c, 0x2000))
    c.emu.w32(self_ + 0x32, _rnd(c, 0x2000))
    v = c.rng.getrandbits(32)
    # object P: slot 0x2b4 returns v; P+8 -> Z; Z+0x6c dword
    z = _rnd(c, 0x100)
    c.emu.w32(z + 0x6c, c.rng.getrandbits(32))
    vtP = c.emu.fake_vtable('CRagdoll2-P', 0x2c0, {0x2b4: logged_slot('ZObj::slot2b4', eax=v, argbytes=4)})
    P = _rnd(c, 0x100)
    c.emu.w32(P, vtP)
    c.emu.w32(P + 8, z)
    c.emu.w32(self_ + 0x36, P)
    if c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x1b3, v)
    else:
        c.emu.w32(self_ + 0x1b3, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x1bf, v if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    # R: the region the 0xc4 result points into (loop index dwords at R + 0xc + 0x30k)
    R = _rnd(c, 0x1000)
    vtY = c.emu.fake_vtable('CRagdoll2-Y', 0x40, {0xc4: logged_slot('ZObj::slotc4', eax=R, argbytes=4)})
    Y = _rnd(c, 0x100)
    c.emu.w32(Y, vtY)
    X = _rnd(c, 0x100)
    c.emu.w32(X + 0x18, Y)
    sys_ = _rnd(c, 0x2000)
    c.emu.w32(sys_ + 0x1aa3, X)
    c.emu.w32(0x70039c, sys_)
    # the object at +0x17f: slot 8 (no args)
    vt17 = c.emu.fake_vtable('CRagdoll2-17f', 0x10, {0x8: logged_slot('ZObj::slot8', eax=0, argbytes=0)})
    o17 = _rnd(c, 0x100)
    c.emu.w32(o17, vt17)
    c.emu.w32(self_ + 0x17f, o17)
    ss.patch(c, H['634d22'], c.emu.stub_fn('memcpy', _cdecl_memcpy))
    for k in ('644660', '641340', '544e10', '545950'):
        ss.patch(c, H[k], c.emu.stub_fn('CRagdoll2::' + k, _rec('CRagdoll2::' + k, 0)))
    ss.patch(c, H['641e20'], c.emu.stub_fn('CRagdoll2::641e20', _rec('CRagdoll2::641e20', 2)))
    ss.patch(c, H['547a70'], c.emu.stub_fn('PSVEC::547a70', _rec('PSVEC::547a70', 0, True)))
    ss.patch(c, H['4de480'], c.emu.stub_fn('Particle::4de480', _rec('Particle::4de480', 0, True)))
    ss.patch(c, H['4419f0'], c.emu.stub_fn('Particle::4419f0', _rec('Particle::4419f0', 0, True)))
    ss.patch(c, H['441940'], c.emu.stub_fn('Particle::441940', _rec('Particle::441940', 0, True)))
    return [self_]


S(0x6411b0, 'CRagdoll2::ComputeParticlePositions() thiscall', 'thiscall', None, ret=None, gen=_compute,
  note='unclaimed-79 batch 9; orchestration verified, helpers stubbed (call-recording)')
