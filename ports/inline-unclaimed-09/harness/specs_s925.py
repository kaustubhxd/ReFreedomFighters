"""specs_s925.py - unclaimed-09 batch 17 (docs/20-unclaimed-09.md, claim 17): 0x647380 (no GC name).

The object is 0x300 random bytes. The count at +0x69 is 0 to 3 (so the loop runs in most cases). The save object is
serial_stubs.save_obj with logged rec stubs on the slots used (0x3c, 0x60, 0x68, 0x70, 0x44). 0x644e30 is hooked
(unverified callee): it logs ecx and its argument and returns a random dword with a plain ret 4 (thiscall)."""
from pilot import S
from serial_stubs import save_obj, rec


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    rng = c.rng
    ret = rng.getrandbits(32)

    def hook644(e2, r):
        e2.calllog.append(('Call644e30', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=ret, argbytes=4)

    c.emu.hook(0x644e30, hook644)
    sv = save_obj(c, {0x3c: rec(c, 1), 0x60: rec(c, 1), 0x68: rec(c, 1), 0x70: rec(c, 1), 0x44: rec(c, 1)})
    this = _rnd(c, 0x300)
    c.emu.w32(this + 0x69, rng.randint(0, 3))
    c.emu.w32(this + 0x28d, 0 if rng.random() < 0.25 else c.emu.alloc(0x40, 4))
    c.emu.w32(this + 0x291, rng.getrandbits(32))
    return [this, sv]


S(0x647380, 'unnamed 0x647380 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b17; no GC name (GUESS); save slots rec, 0x644e30 hooked (unverified callees)')
