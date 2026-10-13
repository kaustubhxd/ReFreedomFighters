"""specs_s2742.py - unclaimed-27 batch 44 (residue 6): 0x606ea0 (stdcall, pointer to a char pointer and a modulus, returns the hash
mod the modulus) and 0x66ffe0 (cdecl, no arguments, splices two globals). No callees; no hooks. Objects that the splice writes into
are 0x40 random bytes each; the string is random printable text of 0..20 characters."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hash(c):
    n = c.rng.randint(0, 20)
    chars = bytes(c.rng.choice(b'abcdefXYZ019 _-') for _ in range(n)) + b'\x00'
    sp = c.emu.alloc(len(chars) + 16, 4)
    c.emu.wbytes(sp, chars)
    pp = c.emu.alloc(0x10, 4)
    c.emu.w32(pp, sp)
    c.emu.mu.ctl_flush_tb()
    return [pp, c.rng.randint(1, 1000)]


def _splice(c):
    cobj = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    aobj = _rnd(c, 0x40) if c.rng.random() < 0.7 else 0
    c.emu.w32(0x6e5d50, cobj)
    c.emu.w32(0x6e5d54, aobj)
    c.emu.w32(0x7003bc, c.rng.getrandbits(32))
    c.emu.w32(0x7003c0, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return []


S(0x606ea0, 'GUESS string hash mod (stdcall)', 'stdcall', None, ret='eax', gen=_hash, reg_values=True, stack_arg_bytes=8,
  note='residue-6 batch 44')
S(0x66ffe0, 'GUESS splice globals (cdecl)', 'cdecl', None, ret=None, gen=_splice, reg_values=True, note='residue-6 batch 44')
