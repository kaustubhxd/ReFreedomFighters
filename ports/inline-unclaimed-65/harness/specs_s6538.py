"""specs_s6538.py - unclaimed-65 batch 38 (docs/20-unclaimed-65.md, claim 21), group 4: ZInputActions::GetButtonName (stdcall, ret 8) with
the high word 2 or 3: edx = hi, no search, the entry is bank base + 12 * index and out := assign(entry + 8) (cases 2 and 3). The bank
pointers at 0x6e48c0 + 16 * edx are set to 12-byte entry blocks whose +8 is a C string pointer. The real 0x4cbe80 and 0x4cc630 run.
The cookie check runs as the real code. Globals are set in gen."""
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


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 4)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _gen(c):
    hi = c.rng.choice([2, 3])
    idx = c.rng.randint(0, 31)
    base = _rnd(c, 12 * 32)
    for k in range(32):
        c.emu.w32(base + 12 * k + 8, _cstr(c, b'Name%d' % k))
    c.emu.w32(0x6e48c0 + 16 * hi, base)
    # the other banks and the search table are not used: the search is skipped because hi is non-zero
    c.emu.w32(0x6e48bc, 0)
    c.emu.w32(0x6e4928, 0)
    rend = _rnd(c, 0x200)
    c.emu.w32(rend, c.emu.fake_vtable('gbn-rend4', 0x100, {}))   # not called on cases 2 and 3
    c.emu.w32(0x70039c, rend)
    out = _rnd(c, 0x80)
    return [out, (hi << 16) | idx]


def _setup(c):
    _flush_code(c)


S(0x439020, 'ZInputActions::GetButtonName (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 38 (claim 21); group 4: high word 2 or 3, cases 2 and 3 (assign from entry + 8)')
