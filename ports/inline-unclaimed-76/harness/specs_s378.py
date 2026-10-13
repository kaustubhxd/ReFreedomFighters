"""specs_s378.py - area 76, residue 17, batch 378 (thiscall vtable chains; GUESS). Each object has a vtable built from its slots:
arity and the returned value are per slot, every call is logged. 0x64f9d0's allocator object is the global 0x70038c; 0x657450's second call
takes [r + 0x80] from the first result, so the first result is a random 0x100-byte block."""
from pilot import S


def _vt(e, name, slots):
    """slots: {off: (nargs, value)}: thiscall stubs that log their words and return value."""
    def mk(off, n, v):
        def h(em, r):
            em.calllog.append((name, off, em.reg('ecx'), tuple(em.arg32(k) for k in range(n))))
            em.ret(eax=v, argbytes=4 * n)
        return h
    return e.fake_vtable(name, 0x100 // 4, {off: mk(off, n, v) for off, (n, v) in slots.items()})


def _gen_650(c):
    e = c.emu
    rng = c.rng
    vt = _vt(e, 'o650', {0x90: (0, 0), 0x9c: (1, 0)})
    this = e.alloc(0x80, 4)
    e.wbytes(this, rng.randbytes(0x80))
    e.w32(this, vt)
    e.w32(this + 0x3c, rng.getrandbits(32))
    return [this, rng.getrandbits(32)]


def _gen_64f(c):
    e = c.emu
    rng = c.rng
    alloc_vt = _vt(e, 'alloc64f', {0x98: (0, rng.getrandbits(32))})
    al = e.alloc(0x40, 4)
    e.w32(al, alloc_vt)
    e.w32(0x70038c, al)
    vt = _vt(e, 'o64f', {0x74: (2, 0)})
    this = e.alloc(0x80, 4)
    e.wbytes(this, rng.randbytes(0x80))
    e.w32(this, vt)
    return [this]


def _gen_657(c):
    e = c.emu
    rng = c.rng
    rec = e.alloc(0x100, 4)
    e.wbytes(rec, rng.randbytes(0x100))
    vt = _vt(e, 'o657', {0xc: (1, rec)})
    this = e.alloc(0x80, 4)
    e.wbytes(this, rng.randbytes(0x80))
    e.w32(this, vt)
    return [this, rng.getrandbits(32)]


S(0x650b50, 'chain650b50 (GUESS)', 'thiscall', None, ret=None, gen=_gen_650, note='area 76 batch 378; residue 17')
S(0x64f9d0, 'chain64f9d0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_64f, note='area 76 batch 378; residue 17')
S(0x657450, 'chain657450 (GUESS)', 'thiscall', None, ret='eax', gen=_gen_657, note='area 76 batch 378; residue 17')
