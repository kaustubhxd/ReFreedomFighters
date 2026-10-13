"""specs_s2738.py - unclaimed-27 batch 40: FUN_59ac70 (GUESS, thiscall, no arguments, void). Stubs and hooks, NOT verified: G (global
0x70039c) has a vtable whose slot +0x1a8 (thiscall, one arg) records ecx and its argument; the engine E = G+0x9b has a vtable whose slot
+0x34 (thiscall, one arg) records the same; the two sub-objects A and B (this+0x1054, this+0x1058; each 0 or an object) have a slot +0
(thiscall, one arg) that records; 0x4cd0e0 is a hook (thiscall, no args) recording ecx. Each record is a 0x10-byte block: count, arg, ecx.
The SEH frame is not reproduced (tagged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    return s


def _rec_stub(blk):
    # thiscall, one stack argument: count++, arg -> blk+4, ecx -> blk+8; ret 4
    return (b'\x8b\x44\x24\x04' + b'\xa3' + (blk + 4).to_bytes(4, 'little')
            + b'\x89\x0d' + (blk + 8).to_bytes(4, 'little')
            + b'\xff\x05' + blk.to_bytes(4, 'little') + b'\xc2\x04\x00')


def _f59ac(c):
    recG = c.emu.alloc(0x10, 4)
    recE = c.emu.alloc(0x10, 4)
    recA = c.emu.alloc(0x10, 4)
    recB = c.emu.alloc(0x10, 4)
    rec4 = c.emu.alloc(0x10, 4)
    # the hook for 0x4cd0e0 (thiscall, no args) counts and records ecx
    c.emu.hook(0x4cd0e0, lambda e, r, rec4=rec4: (e.w32(rec4, (e.r32(rec4) + 1) & 0xffffffff), e.w32(rec4 + 4, e.reg('ecx')), e.ret(argbytes=0)))
    # G: its own vtable slot +0x1a8
    gvt = c.emu.alloc(0x200, 4)
    c.emu.w32(gvt + 0x1a8, _stub(c, _rec_stub(recG)))
    G = _rnd(c, 0x2000)
    c.emu.w32(G, gvt)
    # E = G+0x9b: its vtable slot +0x34
    evt = c.emu.alloc(0x200, 4)
    c.emu.w32(evt + 0x34, _stub(c, _rec_stub(recE)))
    E = _rnd(c, 0x100)
    c.emu.w32(E, evt)
    c.emu.w32(G + 0x9b, E)
    c.emu.w32(0x70039c, G)
    # sub-objects A and B, each 0 or an object with slot +0
    obj = _rnd(c, 0xc00)
    for off, rec in ((0x1054, recA), (0x1058, recB)):
        if c.rng.random() < 0.7:
            avt = c.emu.alloc(0x200, 4)
            c.emu.w32(avt + 0, _stub(c, _rec_stub(rec)))
            A = _rnd(c, 0x100)
            c.emu.w32(A, avt)
            c.emu.w32(obj + off, A)
        else:
            c.emu.w32(obj + off, 0)
    c.emu.mu.ctl_flush_tb()
    return [obj]


S(0x59ac70, 'FUN_59ac70 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f59ac, reg_values=True,
  note='unclaimed-27 batch 40; G slot +0x1a8, sub-object slot +0, 0x4cd0e0 hook, engine slot +0x34 are stubs; SEH not reproduced')
