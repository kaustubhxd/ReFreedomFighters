"""specs_s6535.py - unclaimed-65 batch 35 (docs/20-unclaimed-65.md, claim 21), group 1: ZInputActions::GetButtonName (stdcall, ret 8) with
code 0xffffffff, the default: out := the literal 0x677b5a (through the real 0x4cbe80 and 0x4cc630). The out object is a heap block.
The /GS cookie check 0x633654 runs as the real code (it keeps eax, the return value). Translation cache flushed."""
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


def _setup(c):
    # the real /GS check runs here (its ecx is the cookie xor ebp, which matches the global; it keeps eax, the return value)
    _flush_code(c)


def _gen(c):
    out = _rnd(c, 0x80)
    # the string object: its first dword points at its own inline buffer (as the exe builds it), the rest random
    return [out, 0xffffffff]


S(0x439020, 'ZInputActions::GetButtonName (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-65 batch 35 (claim 21); group 1: code -1, the literal default')
