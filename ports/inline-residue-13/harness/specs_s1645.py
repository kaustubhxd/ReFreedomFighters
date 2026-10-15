"""specs_s1645.py - residue 13 batch 1645: ZItemWeapon::CopyGeom. Recorders: vtable +0x1c0 (lookup), geom +0x2c/+0x74/
+0x100/+0x50, the child objects' +0x154/+0x158, and the exe ZBaseGeom functions SetControl, GetMatPos and CallEvents
(hooked by address, not recording their stack-buffer arguments). The child list is a chain of 0..3 children; +0x50
writes the next child into its out pointer (a stack address, not recorded)."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, HOOKED


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    cnt = {'ctl': 0, 'mat': 0, 'ev': 0}

    def ctl(e, rr):
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(argbytes=8)
    c.emu.hook(0x4dc630, ctl)
    HOOKED.add(0x4dc630)

    def mat(e, rr):
        a = e.r32(e.reg('esp') + 4)
        b = e.r32(e.reg('esp') + 8)
        for i in range(9):
            e.mu.mem_write(a + 4 * i, struct.pack('<f', (i * 0.5) - 2.0))
        for i in range(3):
            e.mu.mem_write(b + 4 * i, struct.pack('<f', 1.5 * i))
        e.ret(argbytes=8)
    c.emu.hook(0x4db2c0, mat)
    HOOKED.add(0x4db2c0)

    evlog = c.emu.alloc(4 + 4 * 16, 4)

    def ev(e, rr):
        n = e.r32(evlog)
        e.w32(evlog + 4 + 4 * (n % 16), e.r32(e.reg('esp') + 4))   # the event id (first parameter)
        e.w32(evlog, n + 1)
        e.ret(argbytes=16)
    c.emu.hook(0x4da340, ev)
    HOOKED.add(0x4da340)

    kids = []
    for _ in range(r.randint(0, 3)):
        k = rnd(c, 0x100)
        c.emu.w32(k + 0x3c, r.choice([0, 0x800000, 0x12345678]))
        kvt = obj(c, 0x200, {0x154: stub(c, seq, 0), 0x158: stub(c, seq, 0)})
        k54 = rnd(c, 0x40)
        c.emu.w32(k54, c.emu.r32(kvt))
        c.emu.w32(k + 0x54, k54 if r.random() < 0.8 else 0)
        kids.append(k)
    for i, k in enumerate(kids):
        c.emu.w32(k + 0x3c, c.emu.r32(k + 0x3c))
    item = obj(c, 0x80, {0x54: stub(c, seq, 1)})
    gvt_slots = {}
    state = {'i': 0}

    def nxt(e, rr):
        out = e.r32(e.reg('esp') + 4)
        state['i'] += 1
        e.w32(out, kids[state['i'] - 1] if state['i'] - 1 < len(kids) else 0)
        e.ret(argbytes=4)
    # the matrix buffers passed to +0x74 are stack addresses, so they are not recorded
    geomvt = obj(c, 0x200, {0x2c: stub(c, seq, 0), 0x74: stub(c, seq, 2, skip=(0, 1)),
                            0x100: stub(c, seq, 1, ret=item if r.random() < 0.8 else 0),
                            0x50: c.emu.stub_fn('next', nxt)})
    geom = rnd(c, 0x100)
    c.emu.w32(geom, c.emu.r32(geomvt))
    first = kids[0] if kids else 0
    c.emu.w32(geom + 8, first)
    # the first child is also linked into the chain by the next-pointer walk
    state['i'] = 0
    gvt = geomvt
    selfvt = obj(c, 0x200, {0x1c0: stub(c, seq, 5, ret=geom if r.random() < 0.9 else 0)})
    selfo = rnd(c, 0x100)
    c.emu.w32(selfo, c.emu.r32(selfvt))
    src = rnd(c, 0x100)
    c.emu.w32(src + 8, rnd(c, 0x40))
    grp = rnd(c, 8)
    return [selfo, src, grp, r.choice([0, 1])]


S(0x46d2d0, 'ZItemWeapon::CopyGeom', 'stdcall', None, ret='eax', gen=_gen, note='batch1645')
