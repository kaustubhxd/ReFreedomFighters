"""specs_s822.py - core batch 822 (docs/20-unclaimed-65.md). 0x46d5d0: stdcall, two stack words (ret 8). The first word is not read. The
render sub-object at [0x70039c]+0x9b has the object at +0xadc. 0x46d530 is HOOKED by address (GUESS): thiscall with two stack words (callee
pops 8), it logs ecx and both words and returns a random eax chosen per case (the same value in the orig and port runs)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x46d530, c.emu.stub_fn('46d530 hook', lambda e, r: (
        e.calllog.append(('0x46d530', e.reg('ecx'), e.arg32(0), e.arg32(1))),
        e.ret(eax=e.reg('ecx') ^ 0x5a5a5a5a, argbytes=8))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    r9 = _rnd(c, 0x1000)
    c.emu.w32(r9 + 0xadc, c.rng.choice([0, _rnd(c, 0x40)]))
    render = _rnd(c, 0x200)
    c.emu.w32(render + 0x9b, r9)
    c.emu.w32(0x70039c, render)
    this = _rnd(c, 0x40)
    return [this, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x46d5d0, 'ZItemTemplateWeapon::CreateItem (unknown) stdcall two args', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='core batch 822: pass-through call to 0x46d530 with the object at +0xadc (hooked)')
