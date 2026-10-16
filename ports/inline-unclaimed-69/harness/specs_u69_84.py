"""specs_u69_84.py - area 69, residue-8 cleanup routines (push N; mov eax,[ebp+disp]; push eax; call 0x634273; add esp,8; ret).
Each takes its pointer from an EBP-relative local, passed through the ('regs', ['ebp']) ABI with a buffer in emulator memory.
GUESS stub: 0x634273 (sized delete, cdecl) logs whether its pointer is the stored value and the size (booleans and small ints only)."""
from pilot import S
from ckit import rnd


def _gen663e42(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-148), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x663e42, 'cleanup663e42 (free local -0x94, size 0x50)', ('regs', ['ebp']), None, ret=None, gen=_gen663e42, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen6645c8(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x6645c8, 'cleanup6645c8 (free local -0x14, size 0x28)', ('regs', ['ebp']), None, ret=None, gen=_gen6645c8, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen6668c0(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x6668c0, 'cleanup6668c0 (free local -0x10, size 0x2c)', ('regs', ['ebp']), None, ret=None, gen=_gen6668c0, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen667186(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x667186, 'cleanup667186 (free local 0x10, size 0x1c)', ('regs', ['ebp']), None, ret=None, gen=_gen667186, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen6677c8(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x6677c8, 'cleanup6677c8 (free local -0x10, size 0x108)', ('regs', ['ebp']), None, ret=None, gen=_gen6677c8, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen6695c0(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x6695c0, 'cleanup6695c0 (free local -0x10, size 0x432)', ('regs', ['ebp']), None, ret=None, gen=_gen6695c0, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen669848(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x669848, 'cleanup669848 (free local 0x10, size 0xac)', ('regs', ['ebp']), None, ret=None, gen=_gen669848, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen669fc8(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x669fc8, 'cleanup669fc8 (free local 0x10, size 0x1c)', ('regs', ['ebp']), None, ret=None, gen=_gen669fc8, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66a748(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66a748, 'cleanup66a748 (free local -0x14, size 0x108)', ('regs', ['ebp']), None, ret=None, gen=_gen66a748, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66a880(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66a880, 'cleanup66a880 (free local -0x10, size 0x120a)', ('regs', ['ebp']), None, ret=None, gen=_gen66a880, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66ad80(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66ad80, 'cleanup66ad80 (free local -0x10, size 0xf4)', ('regs', ['ebp']), None, ret=None, gen=_gen66ad80, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66b14c(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66b14c, 'cleanup66b14c (free local -0x14, size 0x108)', ('regs', ['ebp']), None, ret=None, gen=_gen66b14c, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66bb44(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66bb44, 'cleanup66bb44 (free local -0x14, size 0x108)', ('regs', ['ebp']), None, ret=None, gen=_gen66bb44, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66c684(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66c684, 'cleanup66c684 (free local -0x14, size 0x1c)', ('regs', ['ebp']), None, ret=None, gen=_gen66c684, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66ca4d(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-20), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66ca4d, 'cleanup66ca4d (free local -0x14, size 0x29)', ('regs', ['ebp']), None, ret=None, gen=_gen66ca4d, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66d1c0(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-24), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66d1c0, 'cleanup66d1c0 (free local -0x18, size 0x48)', ('regs', ['ebp']), None, ret=None, gen=_gen66d1c0, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66d589(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-192), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66d589, 'cleanup66d589 (free local -0xc0, size 0x17e)', ('regs', ['ebp']), None, ret=None, gen=_gen66d589, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66e980(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-24), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66e980, 'cleanup66e980 (free local -0x18, size 0x65)', ('regs', ['ebp']), None, ret=None, gen=_gen66e980, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66eac0(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66eac0, 'cleanup66eac0 (free local -0x10, size 0x14)', ('regs', ['ebp']), None, ret=None, gen=_gen66eac0, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66eacf(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (-16), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66eacf, 'cleanup66eacf (free local -0x10, size 0x14)', ('regs', ['ebp']), None, ret=None, gen=_gen66eacf, note='u69 group 84; delete 0x634273 is a GUESS hook')

def _gen66ed48(c):
    e = c.emu
    buf = rnd(c, 0x200)
    ebp = buf + 0x100
    p = c.rng.getrandbits(32) | 0x10000   # the stored pointer (an opaque value, not dereferenced)
    e.w32(ebp + (12), p)
    e.hook(0x634273, lambda e, res: (e.calllog.append(('delete634273', int(e.arg32(0) == p), e.arg32(1))), e.ret(argbytes=0)))
    return [ebp]


S(0x66ed48, 'cleanup66ed48 (free local 0xc, size 0x108)', ('regs', ['ebp']), None, ret=None, gen=_gen66ed48, note='u69 group 84; delete 0x634273 is a GUESS hook')
