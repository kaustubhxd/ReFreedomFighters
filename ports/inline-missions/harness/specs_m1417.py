"""specs_m1417.py - batch 1417: ZFFCareTaker_C02A PlayVoiceOver and Command."""
import os
import struct
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S  # noqa: E402
from mkit import rnd, cstr, stub, obj, hook_stub, logger  # noqa: E402


def sprintf_hook(c):
    rec = c.emu.alloc(8, 4)

    def h(e, r):
        esp = e.reg('esp')
        dst, fmt, a = e.r32(esp + 4), e.r32(esp + 8), e.r32(esp + 12)
        f = bytearray()
        k = 0
        while True:
            b = e.r8(fmt + k)
            if b == 0:
                break
            f.append(b)
            k += 1
        sa = a - (1 << 32) if a & 0x80000000 else a
        out = (f.decode('latin-1').replace('%2i', '%2d') % sa).encode('latin-1') + b'\0'
        e.wbytes(dst, out)
        e.w32(rec, e.r32(rec) + 1)
        e.ret(eax=len(out) - 1, argbytes=0)
    c.emu.hook(0x42ac56, h)


def world(c, ct):
    hero = rnd(c, 0x900)
    c.emu.w32(hero + 0x852, rnd(c, 16))
    c.emu.w32(ct + 0x64, hero)
    snd = rnd(c, 0x120) if c.rng.random() < 0.85 else 0
    if snd:
        ext = obj(c, 0x90, {0x84: stub(c, 0, this=True)})
        c.emu.w32(snd, c.emu.r32(obj(c, 0x110, {0x104: stub(c, 1, this=True, ret=ext if c.rng.random() < 0.7 else 0)})))
        d = rnd(c, 0x80) if c.rng.random() < 0.7 else 0
        c.emu.w32(snd + 0x18, d)
    lvt = c.emu.alloc(0x40, 4)
    c.emu.w32(lvt + 0x30, stub(c, 1, this=True, ret=0x55))
    c.emu.w32(ct + 0x130, lvt)
    reg = obj(c, 0x90, {0x88: stub(c, 2, this=True, skip=(1,), outs=[(1, 9)])})
    mgr = rnd(c, 0xb00)
    c.emu.w32(mgr, c.emu.r32(obj(c, 0x140, {0x58: stub(c, 1, this=True, rets=[snd, hero, hero, hero]),
                                            0x138: stub(c, 0, this=True, ret=reg)})))
    c.emu.w32(mgr + 0xae4, rnd(c, 16))
    sysi = rnd(c, 0x100)
    c.emu.w32(sysi + 0x9b, mgr)
    c.emu.w32(sysi + 0x40, c.rng.getrandbits(24))
    c.emu.w32(0x70039c, sysi)
    logger(c, nargs=2)
    hook_stub(c, 0x44c370, 0, this=True)
    hook_stub(c, 0x44c2b0, 0, this=True)
    hook_stub(c, 0x49df60, 2, this=True, skip=(0, 1), copy=(0, 40), rets=[c.rng.choice([0, 0x1000]), c.rng.choice([0, 0x2000])])
    hook_stub(c, 0x49e0d0, 0, this=True, rets=[cstr(c, 'Isabella'), cstr(c, 'Go!')])
    rec = c.emu.alloc(32, 4)

    def dlg(e, r):
        esp = e.reg('esp')
        e.w32(rec, e.reg('ecx'))
        e.w32(rec + 4, e.r32(esp + 4))
        e.wbytes(rec + 8, e.rbytes(e.r32(esp + 8), 12))
        e.w32(rec + 20, e.r32(esp + 12))
        e.ret(eax=0, argbytes=12)
    c.emu.hook(0x59a5b0, dlg)
    sprintf_hook(c)
    hook_stub(c, 0x597fc0, 2, this=True)
    hook_stub(c, 0x597fb0, 0, this=True)
    hook_stub(c, 0x59b310, 1, this=True, ret=c.rng.choice([0, 1]))
    hook_stub(c, 0x591e50, 1, this=True, ret=c.rng.choice([0, 7]))
    c.emu.w32(0x7003b8, rnd(c, 0x2c40))


def ct_obj(c):
    ct = rnd(c, 0x390)
    for i in range(10):
        c.emu.w8(ct + 0x2bc + i, c.rng.choice([0, 0, 1]))
    for off in (0x294, 0x296, 0x297, 0x298, 0x299, 0x372, 0x374):
        c.emu.w8(ct + off, c.rng.choice([0, 1]))
    c.emu.w32(ct + 0x2b4, c.rng.choice([0, rnd(c, 16)]))
    c.emu.w32(ct + 0x7c, c.rng.choice([0, 3]))
    return ct


def g_vo(c):
    ct = ct_obj(c)
    world(c, ct)
    return [ct, c.rng.randrange(0, 10), c.rng.choice([0x13, 0x1c, 7, -3])]


def g_cmd(c):
    ct = ct_obj(c)
    world(c, ct)
    ids = [0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62]
    for k, off in enumerate(ids):
        c.emu.w16(ct + off, 0x200 + k)
    # the +0x7c object (EnterBriefingRoom) comes from the manager lookup: give the first lookup slot 0x2c
    msg = (0x200 + c.rng.randrange(0, len(ids) + 1)) | (c.rng.getrandbits(16) << 16)
    if (msg & 0xffff) == 0x201:
        mgr = c.emu.r32(c.emu.r32(0x70039c) + 0x9b)
        c.emu.w32(c.emu.r32(mgr) + 0x58, stub(c, 1, this=True, ret=obj(c, 0x30, {0x2c: stub(c, 0, this=True)})))
    return [ct, msg, 0]


S(0x5bb960, 'ZFFCareTaker_C02A::PlayVoiceOver', 'thiscall', ret=None, gen=g_vo)
S(0x5bacc0, 'ZFFCareTaker_C02A::Command', 'thiscall', ret='eax', gen=g_cmd)
