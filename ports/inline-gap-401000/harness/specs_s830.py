"""specs_s830.py - unported-PC batch 830 (docs/20-unclaimed-65.md). 0x5bd750: thiscall with one stack argument (the source; ret 4). The source's
first dword is a seed. 0x4e5e60 and 0x4e5e40 are HOOKED by address (GUESS): thiscall, no arguments; each returns a value that is a hash of the
seed, the helper's name and the call count within the run (the same in the orig and port runs). The result is written through to memory and
logged by its value."""
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


def _h(seed, *keys):
    return hash((seed,) + keys) & 0xffffffff


def _setup(c):
    import serial_stubs as ss

    def hook(addr, tag):
        def f(e, r):
            seed = e.r32(e.reg('ecx'))
            k = sum(1 for x in e.calllog if x[0] == tag)
            v = _h(seed, tag_id[tag], k)
            e.calllog.append((tag, v))
            e.ret(eax=v, argbytes=0)
        ss.patch(c, addr, c.emu.stub_fn(tag + ' hook', f))

    tag_id = {'0x4e5e60': 1, '0x4e5e40': 2}
    hook(0x4e5e60, '0x4e5e60')
    hook(0x4e5e40, '0x4e5e40')
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    src = _rnd(c, 0x40)
    c.emu.w32(src, c.rng.getrandbits(32))
    this = _rnd(c, 0x100)
    return [this, src]


S(0x5bd750, 'CCheckInsideByType::CopyEventDataBlock (unknown) thiscall one arg', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unported-PC batch 830: word and bit writes from the hooked helpers 0x4e5e60 and 0x4e5e40')
