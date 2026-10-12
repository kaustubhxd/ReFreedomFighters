"""specs_s2305.py - unclaimed-23 batch 5 (docs/20-unclaimed-23.md): ZItemTemplateWeapon::ClassInit (0x46c820), thiscall, no
arguments. The object's vtable slot +0x25c is a stub, rewritten each case, that records its first argument (the key) in a
rings of four cells (first and second arguments), indexes a table of four results by its call count, and returns that result (ret 8). Results are zero or
random, so the stores happen or not. The count and ring are heap cells, reset each case. A translation flush follows the
stub write."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x800)
    vt = c.emu.alloc(0x400, 4)
    cnt = _cell(c)
    ring = _cell(c, 4)
    ring2 = _cell(c, 4)
    tab = c.emu.alloc(16, 4)
    for i in range(4):
        v = 0 if c.rng.random() < 0.25 else c.rng.getrandbits(32) | 1
        c.emu.w32(tab + 4 * i, v)
    # mov eax,[esp+4]; mov edx,[cnt]; mov [ring+edx*4],eax; inc dword [cnt]; mov eax,[tab+edx*4]; ret 8
    code = (b'\x8b\x44\x24\x04' +
            b'\x8b\x15' + _le(cnt) +
            b'\x89\x04\x95' + _le(ring) +
            b'\x8b\x44\x24\x08' + b'\x89\x04\x95' + _le(ring2) +   # second argument into ring2
            b'\xff\x05' + _le(cnt) +
            b'\x8b\x04\x95' + _le(tab) +
            b'\xc2\x08\x00')
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    c.emu.w32(vt + 0x25c, s)
    c.emu.w32(self_, vt)
    _flush(c)
    return [self_]


S(0x46c820, 'ZItemTemplateWeapon::ClassInit (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-23 batch 5; vtbl+0x25c stub records the key and returns table[call count]')
