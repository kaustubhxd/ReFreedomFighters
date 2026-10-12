"""specs_s1913.py - unclaimed-66 batch 1913: GUESS FUN_0057bd90 (class constructor), thiscall, no arguments, returns this.

The base constructor is the real port 0x561020 (batch 1918), called directly from the C++ (no stub). So this batch verifies the
whole 0x57bd90 chain: the base constructor, then the class's vtable store and the return value."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    import specs_s1918 as b18
    c.emu.unhook(0x561020)          # no stub: the base constructor is the real port (batch 1918)
    b18.setup_engine(c)
    return [_rnd(c, 0x1100)]


S(0x57bd90, 'GUESS FUN_0057bd90 (class ctor; base 0x561020 stubbed)', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-66 batch 1913; calls the real base ctor 0x561020 (batch 1918)')
