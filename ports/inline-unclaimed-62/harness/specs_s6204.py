"""specs_s6204.py - unclaimed-62 claim 2 (residue 03): CExplodeMolotov destructor (0x581630). The message table's slot 0x34 is a logged stub.
The assert hook (0x7003b0) is always a logged stub, so the no-bit-2 path never traps. Returns eax (this)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _mol(c):
    e = c.emu
    r = c.rng

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_hook_6204', hook))
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'molmsg', 0x40, argwords={0x34: 1}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = rnd(c, 0x80)
    flags = r.choice([0, 1, 3, 4, 5, 7, 0x10, 0x11, 0x14, 0x15])
    return [self_, flags]


S(0x581630, 'CExplodeMolotov::~CExplodeMolotov', 'thiscall', None, ret='eax', gen=_mol, n=300)
