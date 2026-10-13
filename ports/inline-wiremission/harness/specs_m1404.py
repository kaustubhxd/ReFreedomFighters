"""specs_m1404.py - batch 1404: ZFFLevelController Save, Load, Load2, DisableTestMenu, DumpAI.
Profile helpers (SaveProfileToBuffer, LoadProfileFromBuffer, SetLevel, MakeSceneName, ...) are hooked: they have
their own specs."""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, logger, hook_stub  # noqa: E402
from specs_m1401 import lctrl, mgr_sys  # noqa: E402


def g_save(c):
    lc, p = lctrl(c)
    sg = obj(c, 0x10, {0x10: stub(c, 2, this=True, skip=(0,), copy=(0, 0x400, 1)),
                       0x60: stub(c, 1, this=True), 0x64: stub(c, 1, this=True), 0x3c: stub(c, 1, this=True),
                       0x44: stub(c, 1, this=True)})
    src = rnd(c, 0x400)
    # SaveProfileToBuffer fills the image: a fake that copies random bytes in and records its flag
    hook_stub(c, 0x5ae5a0, 2, this=True, skip=(0,))
    c.emu.hook(0x5ae5a0, _fill_hook(c, src, c.emu.hooks[0x5ae5a0]))
    hook_stub(c, 0x5adea0, 0, this=True, ret=cstr(c, 'SaveName ' + 'x' * c.rng.randrange(0, 20)))
    return [lc, sg]


def _fill_hook(c, src, inner):
    def h(e, r):
        dst = e.r32(e.reg('esp') + 4)
        e.wbytes(dst, e.rbytes(src, 0x400))
        inner(e, r)
    return h


def g_load(c):
    lc, p = lctrl(c)
    src = rnd(c, 0x400)
    lg = obj(c, 0x10, {0x18: stub(c, 2, this=True, skip=(0,), fill=(0, src, 1)),
                       0x68: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(8), 1)]),
                       0x40: stub(c, 1, this=True, skip=(0,), rets=[0], outs=[(0, c.rng.getrandbits(32))]),
                       0x48: stub(c, 1, this=True, skip=(0,), outs=[(0, c.rng.getrandbits(32))])})
    mgr_sys(c, {0x58: stub(c, 1, this=True, rets=[c.rng.getrandbits(32) for _ in range(3)])})
    hook_stub(c, 0x5ae450, 1, this=True, skip=(0,), ret=1, copy=(0, 0x400))
    hook_stub(c, 0x5ae900, 1, this=True, skip=(0,), copy=(0, 0x80))
    return [lc, lg]


def g_load2(c):
    lc, p = lctrl(c)
    c.emu.w8(lc + 0x103e, c.rng.choice([0, 0, 1]))
    c.emu.w8(lc + 0x4a, c.rng.choice(b'0123456789'))
    emb = obj(c, 8, {0: stub(c, 0, this=True), 4: stub(c, 1, this=True)})
    c.emu.w32(lc + 0x1064, c.emu.r32(emb))
    gv = obj(c, 0x10, {0x5c: stub(c, 3, this=True)})
    sysi, mgr = mgr_sys(c, {0x134: stub(c, 0, this=True, ret=gv)})
    e190 = obj(c, 0x10, {0x1b4: stub(c, 1, this=True)})
    # the sys object needs +0x190f: a bigger body with the same vtable
    big = rnd(c, 0x1a00)
    c.emu.w32(big, c.emu.r32(sysi))
    c.emu.w32(big + 0x9b, mgr)
    c.emu.w32(big + 0x190f, e190)
    c.emu.w32(0x70039c, big)
    tgt = rnd(c, 0xac0)
    c.emu.w32(0x7003b8, tgt)
    hook_stub(c, 0x59c0d0, 0, this=True)
    hook_stub(c, 0x5ae860, 1, this=True)
    hook_stub(c, 0x5ae240, 0, this=True)
    return [lc]


def g_testmenu(c):
    lc, p = lctrl(c)
    w = obj(c, 0x10, {0x31c: stub(c, 2, this=True)})
    m = obj(c, 0x10, {0x318: stub(c, 1, this=True, ret=w if c.rng.random() < 0.7 else 0), 0x28: stub(c, 0, this=True)})
    reg = obj(c, 0x10, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, c.rng.getrandbits(32))])})
    mgr_sys(c, {0x138: stub(c, 0, this=True, ret=reg), 0x58: stub(c, 1, this=True, ret=m if c.rng.random() < 0.8 else 0)})
    return [lc]


def g_dumpai(c):
    lc, p = lctrl(c)
    lst = obj(c, 0x10, {0x30: stub(c, 1, this=True, ret=c.rng.getrandbits(32))})
    tl = rnd(c, 0x20)
    c.emu.w32(tl + 0x18, lst)
    tlo = obj(c, 0x10, {0x25c: stub(c, 2, this=True, ret=tl)})
    a = obj(c, 0x10, {0x1e0: stub(c, 1, this=True, ret=c.rng.choice([0, 1, 0x100]))})
    sysi, mgr = mgr_sys(c, {0x58: stub(c, 1, this=True, ret=a if c.rng.random() < 0.8 else 0)})
    big = rnd(c, 0xb00)
    c.emu.w32(big, c.emu.r32(mgr))
    c.emu.w32(big + 0xadc, tlo)
    c.emu.w32(sysi + 0x9b, big)
    hook_stub(c, 0x478400, 0, this=True, ret=c.rng.getrandbits(32))
    logger(c, nargs=2)
    return [lc, c.rng.getrandbits(32)]


S(0x59c530, 'ZFFLevelController::Save', 'thiscall', ret='al', gen=g_save)
S(0x59bfa0, 'ZFFLevelController::Load', 'thiscall', ret='al', gen=g_load)
S(0x59bf00, 'ZFFLevelController::Load2', 'thiscall', ret=None, gen=g_load2)
S(0x59b0a0, 'ZFFLevelController::DisableTestMenu', 'thiscall', ret=None, gen=g_testmenu)
S(0x59b120, 'ZFFLevelController::DumpAI', 'thiscall', ret=None, gen=g_dumpai)
