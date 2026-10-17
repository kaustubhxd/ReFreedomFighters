"""specs_s1647.py - residue 13 batch 1647: ZActor::SetActiveMoveSet(idx, force). The actor's vslot 0x5a8 (a stub
recorder) returns a pointer to a cell holding a row index for the class asked (3, 4, 5, 8, 0xc; 0 when absent). The
row table is the random buffer at manager+0x44 (manager = sys+0x9b), indexed by byte offset. The base move activation
(0x477740) is a hook. The CRT sqrt 0x634d7c runs as exe code. Row indices are never 0 (that reads near address zero)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, HOOKED


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _act(c, seq):
    """ZActor::ActivateBaseMove stand-in: records the call and changes +0x755 (the caller must keep its own value)."""
    rec = c.emu.alloc(12, 4)

    def h(e, _r):
        me = e.reg('ecx')
        e.w32(rec, me)
        e.w32(rec + 4, e.r32(e.reg('esp') + 4))
        e.w32(rec + 8, e.r32(e.reg('esp') + 8))
        n = e.r32(seq.addr) + 1
        e.w32(seq.addr, n)
        e.wf32(me + 0x755, 3.5 + (n % 7))
        e.ret(eax=1, argbytes=8)
    HOOKED.add(0x477740)
    c.emu.hook(0x477740, h)
    return rec


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _act(c, seq)

    B = rnd(c, 0x800)
    mgr = rnd(c, 0x100)
    c.emu.w32(mgr + 0x44, B)
    sysobj(c, db=mgr)

    retfn = []
    for n in (3, 4, 5, 8, 0xc):
        if r.random() < 0.85:
            cell = rnd(c, 4)
            ix = r.randint(1, 0x600) & ~3 or 4
            c.emu.w32(cell, ix)
            # row fields: vector at +0x70 (uniform floats), ints at +0x60, +0x64, +0x6c
            c.emu.w32(B + ix + 0x60, r.randint(-5, 5) & 0xffffffff)
            c.emu.w32(B + ix + 0x64, r.randint(-5, 25) & 0xffffffff)
            c.emu.w32(B + ix + 0x6c, r.randint(-1000, 1000) & 0xffffffff)
            for k in (0x70, 0x74, 0x78):
                c.emu.w32(B + ix + k, _f(r.uniform(-10, 10)))
            retfn.append((0, n, cell))
    selfo = obj(c, 0x800, {0x5a8: stub(c, seq, 1, ret=0, retfn=retfn or None)})

    idx = r.randint(0, 0x3f)
    c.emu.w32(selfo + 0x4ae, idx if r.random() < 0.3 else r.randint(0, 0x3f))
    for i in range(0x40):
        c.emu.w32(selfo + 0x49a + 4 * i, r.choice([0, 1, r.getrandbits(32)]))
    c.emu.w32(selfo + 0x650, r.choice([0, rnd(c, 0x40)]))
    c.emu.w32(selfo + 0x755, _f(r.uniform(-20, 20)))
    force = r.choice([0, 1, 0x100, r.getrandbits(32)])
    return [selfo, idx, force]


S(0x47b8d0, 'ZActor::SetActiveMoveSet', 'thiscall', None, ret='al', gen=_gen,
  note='batch1647; row table random; 0x477740 hooked; sqrt runs as exe code')
