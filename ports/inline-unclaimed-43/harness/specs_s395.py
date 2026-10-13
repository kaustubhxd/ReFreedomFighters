"""specs_s395.py - core batch 395: 0x4c4e00 ZAnimSequence::FrameUpdate (thiscall, no arguments). Callee 0x4c5090 (SEH-framed
exe function, stdcall with two arguments) is hooked by address and logged (GUESS: body not ported). Vtable slot 0x68 is a
logging mock (two stack arguments, returns nothing). The engine object at global 0x70039c has a dword at +0x40 drawn so that
the branch is taken about half the time. The object's +0x69 flag is 0 or 1; +0x60 is a float in [-20, 20]; +0x65 is a dword
in [-50, 50] (both signed compares are exercised)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import engine_stubs as E
import pe_emu


def _nostack(x):
    return 'stack' if pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= x < pe_emu.STACK_TOP else x


def _setup(c):
    c.emu.hook(0x4c5090, lambda em, r: (em.calllog.append(('anim5090', 0, 0, (em.arg32(0), em.arg32(1)))),
                                        em.ret(eax=0, argbytes=8)))


def _gen(c):
    r = c.rng
    slots = {}
    for i in range(0x6c // 4 + 1):
        off = 4 * i

        def h(e, rr, off=off):
            args = [e.arg32(0), e.arg32(1)] if off == 0x68 else []
            e.calllog.append(('ANIMSEQ', off, e.reg('ecx'), tuple(args)))
            e.ret(eax=0, argbytes=8 if off == 0x68 else 0)
        slots[off] = h
    vt = c.emu.fake_vtable('ANIMSEQ', 0x6c // 4 + 1, slots)
    o = E.zero_obj(c, 0x100)
    c.emu.w32(o, vt)
    c.emu.wbytes(o + 0x50, bytes(r.getrandbits(8) for _ in range(8)))
    zero_x = r.random() < 0.5
    c.emu.wbytes(o + 0x60, struct.pack('<f', 0.0 if zero_x else r.uniform(-20.0, 20.0)))
    dv = r.randint(-50, 50)
    c.emu.w32(o + 0x65, dv & 0xffffffff)
    c.emu.wbytes(o + 0x69, bytes([r.choice([0, 1])]))
    eng = E.zero_obj(c, 0x80)
    c.emu.w32(eng + 0x40, (dv if zero_x and r.random() < 0.3 else r.randint(-50, 50)) & 0xffffffff)
    E.set_global(c, 0x70039c, eng)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4c4e00, 'ZAnimSequence::FrameUpdate (core) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='core batch 395; callee 0x4c5090 hooked (GUESS); vtable slot 0x68 mocked')
