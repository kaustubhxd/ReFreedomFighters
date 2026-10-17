"""specs_s6511.py - unclaimed-65 batch 11 (docs/20-unclaimed-65.md, claim 12): ZActor::ReplaceMove. The actor has pointer slots at
+0x49a (index a in 0..3; a block of 8-byte (c, d) pairs for b in 0..3), a 16-entry table at +0x4b2 (16 bytes: a, b, value, flag)
with one entry always free (+8 zero), and slot +0x5ac (two args, logs; callee pops). 0x7003b0 is a counting stub (not reached)."""
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


def _gen(c):
    import serial_stubs as ss
    a = c.rng.randint(0, 3)
    b = c.rng.randint(0, 3)
    cv = c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0
    dv = c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0
    self_ = _rnd(c, 0x800)
    # the pointer slots at +0x49a; slot a points at a block whose (8b+4) dword is cv and (8b+8) is dv in half of the cases
    for i in range(4):
        if c.rng.random() < 0.3:
            c.emu.w32(self_ + 0x49a + 4 * i, 0)
        else:
            blk = _rnd(c, 0x100)
            c.emu.w32(self_ + 0x49a + 4 * i, blk)
            if i == a:
                c.emu.w32(blk + 8 * b + 4, cv)
                c.emu.w32(blk + 8 * b + 8, dv if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    # the 16-entry table at +0x4b2: entries match (a, b) sometimes; entry 15 is always free (+8 zero)
    for i in range(16):
        base = self_ + 0x4b2 + 16 * i
        c.emu.w32(base, a if c.rng.random() < 0.15 else c.rng.getrandbits(32))
        c.emu.w32(base + 4, b if c.rng.random() < 0.15 else c.rng.getrandbits(32))
        c.emu.w32(base + 8, 0 if (i == 15 or c.rng.random() < 0.3) else c.rng.getrandbits(32) | 1)
        c.emu.w32(base + 0xc, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x4ae, c.rng.getrandbits(32))

    def slot5ac(e, r_):
        e.calllog.append(('actor-5ac', e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    vt = c.emu.fake_vtable('actor-replace', 0x5b0, {0x5ac: slot5ac})
    c.emu.w32(self_, vt)
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0, log=False))
    _flush_code(c)
    return [self_, a, b, cv, dv]


S(0x47ac90, 'ZActor::ReplaceMove (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-65 batch 11 (residue 17); pointer block match; 16-entry table search and free slot; slot 0x5ac')
