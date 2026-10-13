"""specs_s1207.py - unclaimed-12 batch 7 (docs/20-unclaimed-12.md, claim 7, in slice): ZSHAPE::Load (one call to 0x45f3c0,
stubbed with a per-case result that logs its argument) and ZProjectile::ReadInput (DBREAD dword, float, bool and dword reads;
dword/word operators through the shared dbread_patch stubs, the float and bool operators through per-case stubs)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S

def _flush_code(c):
    """Drop Unicorn's cached translations for the heap and the exe image after a patch (as area 20 does): a stale
    translation otherwise runs in place of the new stub bytes."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_shape(c):
    # stands in for 0x45f3c0: logs the object (ecx) and its one stack argument into the call log; returns a per-case value
    rv = c.rng.getrandbits(32)

    def helper(e, r):
        e.calllog.append(('0x45f3c0', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    ss.patch(c, 0x45f3c0, c.emu.stub_fn('0x45f3c0 logger', helper))
    _flush_code(c)


def _shape_gen(c):
    return [_rnd(c, 0x40), _rnd(c, 0x40)]


def _setup_readinput(c):
    rets32 = [c.rng.getrandbits(32) for _ in range(8)]
    rets16 = [c.rng.getrandbits(16) for _ in range(8)]
    ss.dbread_patch(c, rets32, rets16, [0] * 8)
    fval = c.fv(-10.0, 10.0)
    bval = c.rng.getrandbits(32)

    def float_read(e, r):
        e.ret(eax=None, argbytes=0, st0=fval)

    def bool_read(e, r):
        e.ret(eax=bval, argbytes=0)
    ss.patch(c, 0x4e5e80, c.emu.stub_fn('DBREAD float', float_read))
    _flush_code(c)
    ss.patch(c, 0x4e5ef0, c.emu.stub_fn('DBREAD bool', bool_read))
    _flush_code(c)


def _readinput_gen(c):
    return [_rnd(c, 0x100), _rnd(c, 0x40)]


S(0x44b2f0, 'ZSHAPE::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_shape_gen,
  setup=_setup_shape, note='unclaimed-12 batch 7 (in slice); returns (0x45f3c0 result != 0)')
S(0x4b9570, 'ZProjectile::ReadInput (unknown) thiscall', 'thiscall', None, ret=None, gen=_readinput_gen,
  setup=_setup_readinput, note='unclaimed-12 batch 7 (in slice); DBREAD reads into +0x4c, +0x48 (float), +0x50 (bool), +0x91, bit 0 of +0x89')
