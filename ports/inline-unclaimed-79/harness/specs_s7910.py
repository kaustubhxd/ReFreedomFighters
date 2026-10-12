"""specs_s7910.py - unclaimed-79 batch 10 (docs/20-unclaimed-79.md): CMsgForwardToActors::Command (0x49f0a0). SEH frame not
reproduced (fs:[0] writes not compared). The chain (this+0x50 -> +0x18) is a logging fake: slot +0x4c resets nothing, slot +0x5c
returns the next element and sets the flag while elements remain (0 to 3). The sys object's slot +0x58 returns a candidate
(zero, the this+0x44 object, or a fresh element). Helper 0x4e0830 is a fastcall stub returning a random float in st0."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from helpers_trial import logged_slot
import serial_stubs as ss

H_4E0830 = 0x4e0830


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _norm(e, p):
    return 'stack-slot' if abs(p - e.reg('esp')) < 0x2000 else p


def _slot84(name):
    def h(e, r):
        e.calllog.append((name, _norm(e, e.arg32(0))))
        e.ret(eax=0, argbytes=4)
    return h


def _elem(c):
    vt = c.emu.fake_vtable('MsgElem', 0x240, {0x84: _slot84('MsgElem::slot84')})
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    return o


def _cmd(c):
    self_ = _rnd(c, 0x200)
    cmd = c.rng.getrandbits(16)
    c.emu.w16(self_ + 0x48, cmd if c.rng.random() < 0.4 else (0 if c.rng.random() < 0.5 else c.rng.getrandbits(16)))
    c.emu.w16(self_ + 0x4a, c.rng.choice([0, 0, c.rng.getrandbits(16)]))
    c.emu.w32(self_ + 0x4c, struct.unpack('<I', struct.pack('<f', c.rng.choice([-1.0, 0.0, 0.5, 2.0, 1e-3,
                                                                              c.rng.uniform(-4, 4)])))[0])
    objA = _elem(c)
    c.emu.w32(self_ + 0x44, objA)
    vtA = c.emu.fake_vtable('MsgActorA', 0x140, {
        0x84: _slot84('MsgActorA::slot84'),
        0x130: logged_slot('MsgActorA::slot130', eax=0, argbytes=12),
    })
    c.emu.w32(objA, vtA)
    n = c.rng.randint(0, 3)
    chain = [_elem(c) for _ in range(n)]
    st = {'j': 0}
    pool = [0, objA, _elem(c), _elem(c)]

    def h5c(e, r):
        flag_ptr = e.arg32(0)
        st['j'] += 1
        j = st['j']
        if j <= n:
            e.w32(flag_ptr, 1)
            e.calllog.append(('MsgChain::next', _norm(e, flag_ptr), 1))
            e.ret(eax=chain[j - 1], argbytes=4)
        else:
            e.w32(flag_ptr, 0)
            e.calllog.append(('MsgChain::next', _norm(e, flag_ptr), 0))
            e.ret(eax=0, argbytes=4)

    def h4c(e, r):
        e.calllog.append(('MsgChain::begin', _norm(e, e.arg32(0))))
        e.ret(eax=0, argbytes=4)

    vt18 = c.emu.fake_vtable('MsgChain', 0x40, {0x4c: h4c, 0x5c: h5c})
    o18 = _rnd(c, 0x100)
    c.emu.w32(o18, vt18)
    o50 = _rnd(c, 0x100)
    c.emu.w32(o50 + 0x18, o18)
    c.emu.w32(self_ + 0x50, o50)

    def h58(e, r):
        cur = e.arg32(0)
        pick = c.rng.choice(pool)
        e.calllog.append(('MsgSys::candidate', cur, pick))
        e.ret(eax=pick, argbytes=4)
    vtS = c.emu.fake_vtable('MsgSys', 0x240, {0x58: h58})
    t = _rnd(c, 0x100)
    c.emu.w32(t, vtS)
    sys_ = _rnd(c, 0x200)
    c.emu.w32(sys_ + 0x9b, t)
    c.emu.w32(0x70039c, sys_)
    fval = c.rng.choice([0.25, -1.0, 3.0, c.rng.uniform(-8.0, 8.0)])

    def h4e0830(e, r):
        e.calllog.append(('MsgHelper::4e0830', _norm(e, e.reg('ecx')), _norm(e, e.reg('edx'))))
        e.ret(eax=0, argbytes=0, st0=fval)
    ss.patch(c, H_4E0830, c.emu.stub_fn('MsgHelper::4e0830', h4e0830))
    return [self_, cmd, c.rng.getrandbits(32)]


S(0x49f0a0, 'CMsgForwardToActors::Command(unsigned short, void*) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-79 batch 10; SEH frame not reproduced (fs:[0] writes not compared); chain with 0 to 3 elements')
