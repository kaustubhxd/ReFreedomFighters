"""specs_s815.py - core batch 815 (docs/20-unclaimed-65.md). 0x55fa00: stdcall, one object argument (ret 4). The word at obj+0x10 is the index.
The count at 0x7140c8 is 0..3 and the table at 0x7140d0 holds entries that point at 0x4e5e40 or 0x4e5e60 (both HOOKED here, GUESS: stdcall
one argument, each returns a fixed value and logs its argument). Index below the count calls the entry; otherwise the word is set to
index - count and the function tail-jumps to 0x5060b0 (HOOKED here: logs its argument, pops it). The count, table and object are written
in gen; the hooks are installed in setup."""
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
    ss.patch(c, 0x4e5e40, c.emu.stub_fn('4e5e40 hook', lambda e, r: (e.calllog.append(('0x4e5e40', e.arg32(0))),
                                                                     e.ret(eax=0x1234, argbytes=4))))
    ss.patch(c, 0x4e5e60, c.emu.stub_fn('4e5e60 hook', lambda e, r: (e.calllog.append(('0x4e5e60', e.arg32(0))),
                                                                     e.ret(eax=0x5678, argbytes=4))))
    ss.patch(c, 0x5060b0, c.emu.stub_fn('5060b0 hook', lambda e, r: (e.calllog.append(('0x5060b0', e.arg32(0))),
                                                                     e.ret(eax=0, argbytes=4))))
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    count = c.rng.randint(0, 3)
    c.emu.w32(0x7140c8, count)
    for i in range(count):
        c.emu.w32(0x7140d0 + 4 * i, c.rng.choice([0x4e5e40, 0x4e5e60]))
    obj = _rnd(c, 0x40)
    idx = c.rng.randint(0, count + 2) & 0xffff
    c.emu.wbytes(obj + 0x10, idx.to_bytes(2, 'little'))
    return [obj]


S(0x55fa00, 'core method 0x55fa00 (unknown) stdcall one arg', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='core batch 815: table dispatch or word update and tail jump to 0x5060b0')
