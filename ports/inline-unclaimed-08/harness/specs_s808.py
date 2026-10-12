"""specs_s808.py - unclaimed-08 batch 808 (docs/20-unclaimed-08.md): CEntityTracker::GetEntity(int&, unsigned int),
thiscall with two stack arguments (ret 8).

The tracker object is 0x80 random bytes; its entry array (at +0x50, 23-byte stride) and count (+0x54, 0..6) are built
per case. Each entry's first dword is an object whose vtable +0x20 (stubbed: logs, returns the owner) gives an owner
with +8 pointing at a flags dword (+0x3c, random). The object's +0x54 type gives a shift dword at +4 (random 0..31 or any
dword). The index is random in [-1, count-1]; the mask is random with a bias to single bits."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _entry(c, arr, i):
    owner_flags = c.rng.getrandbits(32)
    flags = _rnd(c, 0x40)
    c.emu.w32(flags + 0x3c, owner_flags)
    owner = _rnd(c, 0x40)
    c.emu.w32(owner + 8, flags)
    shift = c.rng.randint(0, 31) if c.rng.random() < 0.8 else c.rng.getrandbits(32)
    typ = _rnd(c, 0x20)
    c.emu.w32(typ + 4, shift)
    obj = _rnd(c, 0x80)
    c.emu.w32(obj + 0x54, typ)
    vt = c.emu.fake_vtable('tracked obj', 0x24 // 4 + 1, slots={
        0x20: _slot('tracked obj owner (stub)', 0x20, 0, lambda e, a: (owner, None))})
    c.emu.w32(obj, vt)
    c.emu.w32(arr + 23 * i, obj)


def _get(c):
    self = _rnd(c, 0x80)
    n = c.rng.randint(0, 6)
    arr = _rnd(c, 23 * max(n, 1) + 8)
    c.emu.w32(self + 0x50, arr)
    c.emu.w32(self + 0x54, n)
    for i in range(n):
        _entry(c, arr, i)
    idx_cell = c.emu.alloc(4, 4)
    c.emu.w32(idx_cell, c.rng.randint(-1, max(n - 1, 0)) & 0xffffffff)
    k = c.rng.random()
    mask = (1 << c.rng.randint(0, 31)) if k < 0.4 else c.rng.getrandbits(32)
    return [self, idx_cell, mask]


S(0x5c00f0, 'CEntityTracker::GetEntity (unknown)', 'thiscall', None, ret='eax', gen=_get,
  note='unclaimed-08 batch 8; loop over 23-byte entries, owner vtable +0x20 stubbed')
