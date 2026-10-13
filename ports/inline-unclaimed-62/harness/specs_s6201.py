"""specs_s6201.py - unclaimed-62 claim 1 (residue 02): ZInputActions::PrintActionDebugInfo (0x439f60). The object's slot 0x58 (one
argument) returns an action object, 0, or an object whose first dword is non-zero; the reporter (pfspec.reporter) takes the output.
The action's bytes +0x2e, +0x2f and dword +4 are random, so both string choices come up."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def reporter_all(c):
    """g_pDebug (0x700390) whose slot 0x20 gives a reporter; the reporter's slot 0x2c (cdecl printf) logs all five stack words."""
    e = c.emu
    rep = e.alloc(16)

    def log(em, rr):
        em.calllog.append(('report',) + tuple(em.arg32(k) for k in range(5)))
        em.ret(argbytes=0)
    e.w32(rep, e.fake_vtable('reporter_all', 0x40, {0x2c: log}))
    dbg = e.alloc(16)
    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('g_pDebug_all', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)
    e.w32(0x7003b0, 0)


def _pad(c):
    e = c.emu
    r = c.rng
    reporter_all(c)
    action = rnd(c, 0x40)
    e.w32(action, 0 if r.random() < 0.8 else r.getrandbits(32) | 1)
    e.w8(action + 0x2e, r.choice([0x7f, 0x80, 0x81, r.getrandbits(8)]))
    e.w8(action + 0x2f, r.choice([0x10, 0x00, 0x20, r.getrandbits(8)]))
    e.w32(action + 4, r.getrandbits(32))
    result = action if r.random() < 0.8 else 0
    self_ = rnd(c, 0x100)
    e.w32(self_, vtable(c, 'inputactions', 0x80, impl={0x58: lambda em, a: result}, argwords={0x58: 1}))
    name = e.alloc(16)
    e.wbytes(name, b'jump\x00')
    return [self_, name]


S(0x439f60, 'ZInputActions::PrintActionDebugInfo', 'thiscall', None, gen=_pad, n=1000)
