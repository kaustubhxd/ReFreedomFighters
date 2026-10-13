"""specs_s1210.py - unclaimed-12 batch 10 (docs/20-unclaimed-12.md, claim 10, in slice): ZTankIf::opaqueCall. Dispatches on
the word at [arg+0x10] through the table at 0x701a80 (count at 0x701a78); out-of-range indices are reduced by the count and
tail-jump to 0x51ad90, which is a logging stub here. The table entries are per-case logging stubs; the translation cache is flushed."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss  # noqa: F401
from pilot import S


def _flush_code(c):
    """Drop Unicorn's cached translations for the heap and the exe image after a patch (as area 20 does)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    count = c.rng.randint(0, 8)
    c.emu.w32(0x701a78, count)
    for i in range(8):
        base_ret = c.rng.getrandbits(32)

        def slot(e, r, i=i, base_ret=base_ret):
            e.calllog.append(('opaque-slot', i, e.reg('ecx'), (e.arg32(0),)))
            e.ret(eax=base_ret, argbytes=4)
        c.emu.w32(0x701a80 + 4 * i, c.emu.stub_fn('opaque slot %d' % i, slot))

    rv = c.rng.getrandbits(32)

    def tail(e, r):
        e.calllog.append(('0x51ad90', e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    ss.patch(c, 0x51ad90, c.emu.stub_fn('0x51ad90 logger', tail))
    _flush_code(c)


def _opaque_gen(c):
    self_ = _rnd(c, 0x40)
    params = _rnd(c, 0x40)
    c.emu.w16(params + 0x10, c.rng.randint(0, 12))
    return [self_, params]


S(0x522cf0, 'ZTankIf::opaqueCall (unknown) thiscall', 'thiscall', None, ret='eax', gen=_opaque_gen,
  setup=_setup, note='unclaimed-12 batch 10 (in slice, medium name); table dispatch below count; else reduce and tail-jump 0x51ad90')
