"""specs_s5785.py - unclaimed-57, batch 85: 0x5c4b70 (GUESS name unnamed_5c4b70). Thiscall, no stack args, plain ret. The engine (global
0x70039c) sub-object at +0x9b has fake slots +0x134 (returns object x), +0x138 (returns object y) and +0x58 (one argument: the local, logged;
returns a per-case value stored at this+0x60). x has a fake slot +0x90 (two args: logged constant; writes a byte flag through the second
argument, nonzero in about three cases in ten, which makes the function return early). y has a fake slot +0x88 (two args: logged constant;
writes a per-case dword through the second argument)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c4b70(c):
    e = c.emu
    x_obj = _rnd(c, 0x40)
    y_obj = _rnd(c, 0x40)
    flag_v = 1 if c.rng.random() < 0.3 else 0
    local_v = c.rng.getrandbits(32)
    ret58 = c.rng.getrandbits(32)
    write88 = c.rng.random() < 0.8  # when the slot does not write, the caller's initial value of local is what is used

    def h134(em, r):
        em.calllog.append(('134', 0, None, ()))
        em.ret(eax=x_obj, argbytes=0)

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=y_obj, argbytes=0)

    def h58(em, r):
        em.calllog.append(('58', 0, None, (em.arg32(0),)))
        em.ret(eax=ret58, argbytes=4)

    def h90(em, r):
        em.calllog.append(('90', 0, 'X' if em.reg('ecx') == x_obj else 'other', (em.arg32(0),)))
        em.wbytes(em.arg32(1), bytes([flag_v]))
        em.ret(eax=0, argbytes=8)

    def h88(em, r):
        em.calllog.append(('88', 0, 'Y' if em.reg('ecx') == y_obj else 'other', (em.arg32(0),)))
        if write88:
            em.w32(em.arg32(1), local_v)
        em.ret(eax=0, argbytes=8)

    vt_sub = e.fake_vtable('c4b70_sub', 160, {0x134: h134, 0x138: h138, 0x58: h58})
    vt_x = e.fake_vtable('c4b70_x', 160, {0x90: h90})
    vt_y = e.fake_vtable('c4b70_y', 160, {0x88: h88})
    e.w32(x_obj, vt_x)
    e.w32(y_obj, vt_y)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x80)
    return [self_obj]


S(0x5c4b70, 'unnamed_5c4b70 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c4b70,
  note='unclaimed-57 batch 85; engine sub slots +0x134, +0x138, +0x58 fake; x slot +0x90 writes a flag byte; y slot +0x88 writes a dword')
